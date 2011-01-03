#include "indexer.h"

#include <QThreadPool>
#include <QMutexLocker>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <QtAlgorithms>

#include "tools/vec3D.h"
#include "tools/mat3D.h"
#include "tools/optimalrotation.h"
#include "indexing/marker.h"


using namespace std;



Indexer::Indexer(QList<Vec3D> _spotMarkerNormals, QList<Vec3D> _zoneMarkerNormals, const Mat3D& _MReal, const Mat3D& _MReziprocal, double maxAngularDeviation, double _maxHKLDeviation, int _maxHKL, QList< TMat3D<int> > _lauegroup):
    QObject(),
    QRunnable(),
    candidates(_MReal, _MReziprocal),
    spotMarkerNormals(_spotMarkerNormals),
    zoneMarkerNormals(_zoneMarkerNormals),
    MReal(_MReal),
    MReziprocal(_MReziprocal),
    maxHKLDeviation(_maxHKLDeviation),
    maxHKL(_maxHKL)
{

  MRealInv = MReziprocal.transposed();
  MReziprocalInv = MReal.transposed();

  foreach (TMat3D<int> R, _lauegroup) {
    lauegroup << MReal * R.toType<double>() * MRealInv;
  }

  shouldStop=false;

  foreach (Vec3D n, spotMarkerNormals)
    globalMarkers << Marker(n, Marker::SpotMarker);
  foreach (Vec3D n, zoneMarkerNormals)
    globalMarkers << Marker(n, Marker::ZoneMarker);

  int spotN = spotMarkerNormals.size();
  int zoneN = zoneMarkerNormals.size();


  for (int i=0; i<spotN; i++) {
    for (int j=0; j<i; j++) {
      spotSpotAngles.append(AngleInfo(i, j, globalMarkers, maxAngularDeviation));
    }
  }
  qSort(spotSpotAngles);
  for (int i=spotN; i<spotN+zoneN; i++) {
    for (int j=spotN; j<i; j++) {
      zoneZoneAngles.append(AngleInfo(i, j, globalMarkers, maxAngularDeviation));
    }
  }
  qSort(zoneZoneAngles);
  for (int i=0; i<spotN; i++) {
    for (int j=spotN; j<spotN+zoneN; j++) {
      spotZoneAngles.append(AngleInfo(i, j, globalMarkers, maxAngularDeviation));
    }
  }
  qSort(spotZoneAngles);

  connect(&candidates, SIGNAL(nextMajorIndex(int)), this, SIGNAL(nextMajorIndex(int)));
  connect(&candidates, SIGNAL(progessInfo(int)), this, SIGNAL(progressInfo(int)));
}


void Indexer::run() {
  QThreadPool::globalInstance()->tryStart(this);

  ThreadLocalData localData;
  localData.markers = globalMarkers;
  for (int i=0; i<localData.markers.size(); i++)
    localData.markers[i].setMatrices(localData.spotNormalToIndex, localData.zoneNormalToIndex, MReziprocal, MReal);


  forever {
    int i = candidatePos.fetchAndAddOrdered(1);
    CandidateGenerator::Candidate c1 = candidates.getCandidate(i);
    for (int j=0; j<i; j++) {
      if (shouldStop) return;
      // Be nice to the GUI Thread
      QThread::yieldCurrentThread();
      CandidateGenerator::Candidate c2 = candidates.getCandidate(j);

      checkPossibleAngles(c1.spot(), c2.spot(), spotSpotAngles, localData);
      checkPossibleAngles(c1.zone(), c2.zone(), zoneZoneAngles, localData);
      checkPossibleAngles(c1.spot(), c2.zone(), spotZoneAngles, localData);
    }
  }
}

void Indexer::checkPossibleAngles(const CandidateGenerator::Candidate& c1, const CandidateGenerator::Candidate& c2, QList<AngleInfo> angles, ThreadLocalData& localData) {
  if (angles.empty()) return;

  double cosAng = c1.normal*c2.normal;

  // Binary search for first AngleInfo that has upperBound>cosAng
  int minIdx = 0;
  int maxIdx = angles.size();
  while (maxIdx!=minIdx) {
    int chkIdx = (minIdx+maxIdx)/2;
    if (cosAng>angles.at(chkIdx).upperBound) {
      minIdx = chkIdx+1;
    } else {
      maxIdx = chkIdx;
    }
  }

  for (int n=minIdx; n<angles.size() && cosAng>=angles.at(n).lowerBound; n++) {
    checkGuess(c1, c2, angles.at(n), localData);
    checkGuess(c2, c1, angles.at(n), localData);
  }
}


void Indexer::checkGuess(const CandidateGenerator::Candidate& c1, const CandidateGenerator::Candidate& c2, const AngleInfo &a, ThreadLocalData& localData) {
  // Prepare Best Rotation Matrix from c1,c2 -> a(1) a(2)

  Mat3D R = VectorPairRotation(c1.normal,
                               c2.normal,
                               localData.markers.at(a.index1).getMarkerNormal(),
                               localData.markers.at(a.index2).getMarkerNormal());

  int loops = 0;
  forever {
    loops++;
    localData.spotNormalToIndex = MReziprocalInv * R.transposed();
    localData.zoneNormalToIndex = MRealInv * R.transposed();

    OptimalRotation optRot;

    for (int i=0; i<localData.markers.size(); i++) {
      Marker& m = localData.markers[i];
      if (i==a.index1) {
        m.setIndex(c1.index);
      } else if (i==a.index2) {
        m.setIndex(c2.index);
      } else {
        m.invalidateCache();
      }

      if (m.getBestScore()>maxHKLDeviation) return;
      optRot.addVectorPair(m.getIndexNormal(), m.getMarkerNormal());
    }
    Mat3D T = optRot.getOptimalRotation();
    if (optRot.getOptimalRotation()==R) break;
    R = optRot.getOptimalRotation();
  }

  if (loops>5)
    cout << "Loops " << loops << endl;

  Solution solution;
  solution.bestRotation = R;
  solution.hklDeviation = 0;
  foreach (Marker m, localData.markers) {
    solution.hklDeviation += m.getBestScore();
    solution.markerIdx << m.getRationalIndex();
    solution.markerScore += m.getBestScore();
  }

  Mat3D bestinv(solution.bestRotation.transposed());
  int n=0;
  uniqLock.lockForRead();
  bool duplicate = symmetryEquivalentSolutionPresent(bestinv, n);
  uniqLock.unlock();
  if (duplicate) return;

  uniqLock.lockForWrite();
  duplicate = symmetryEquivalentSolutionPresent(bestinv, n);
  if (!duplicate) {
    uniqSolutions << solution;

    emit publishSolution(solution);
  }
  uniqLock.unlock();
}

bool Indexer::symmetryEquivalentSolutionPresent(const Mat3D &R, int &n) {
  for (; n<uniqSolutions.size(); n++) {
    Mat3D T(R*uniqSolutions.at(n).bestRotation);
    foreach (Mat3D G, lauegroup)  {
      if ((G-T).sqSum()<1e-4) {
        return true;
      }
    }
  }
  return false;
}




Indexer::AngleInfo::AngleInfo(int i1, int i2, const QList<Marker>& markers, double maxDeviation):
    index1(i1),
    index2(i2)
{
  cosAng=markers.at(index1).getMarkerNormal()*markers.at(index2).getMarkerNormal();
  double c=acos(cosAng);
  double c1=cos(c-maxDeviation);
  double c2=cos(c+maxDeviation);
  if (c1<c2) {
    lowerBound = c1;
    upperBound = c2;
  } else {
    lowerBound = c2;
    upperBound = c1;
  }
  if (fabs(c)<maxDeviation) upperBound = 1.0;
  if (fabs(c-M_PI)<maxDeviation) lowerBound = -1.0;
}


bool Indexer::AngleInfo::operator<(const AngleInfo& o) const {
  return cosAng<o.cosAng;
}

void Indexer::stop() {
  //QMutexLocker lock(&indexMutex);
  shouldStop=true;
}
