#include <core/laueplaneprojector.h>
#include <cmath>
#include <QtGui/QGraphicsEllipseItem>
#include <QtGui/QCursor>
#include <tools/circleitem.h>
#include <iostream>
#include <ui/laueplanecfg.h>
#include <core/reflection.h>

#include "image/laueimage.h"
#include "core/projectorfactory.h"

using namespace std;

LauePlaneProjector::LauePlaneProjector(QObject* parent): Projector(parent), localCoordinates() {
  internalSetWavevectors(0.0, 2.0*M_PI);
  setDetSize(30.0, 110.0, 140.0);
  setDetOrientation(180.0, 0, 0);
  detDx=1.0;
  detDy=1.0;
  setDetOffset(0.0, 0.0);

  QList<QString> fitParameterNames;
  fitParameterNames << "Distance" << "X-Offset" << "Y-Offset" << "Omega" << "Chi";
  setFitParameterNames(fitParameterNames);
  connect(this, SIGNAL(imageLoaded(LaueImage*)), this, SLOT(loadParmetersFromImage(LaueImage*)));
};

Projector* LauePlaneProjector::getInstance() {
  return new LauePlaneProjector();
}

QPointF LauePlaneProjector::scattered2det(const Vec3D &v) const{
  Vec3D w=localCoordinates*v;
  if (w.x()<=0.0) {
    return QPointF();
  }
  return QPointF(w.y()/w.x()+detDx, w.z()/w.x()+detDy);
}

QPointF LauePlaneProjector::scattered2det(const Vec3D &v, bool& b) const{
  Vec3D w=localCoordinates*v;
  if (w.x()<=0.0) {
    b=false;
    return QPointF();
  }
  b=true;
  return QPointF(w.y()/w.x()+detDx, w.z()/w.x()+detDy);
}

Vec3D LauePlaneProjector::det2scattered(const QPointF& p) const{
  Vec3D v(1.0 , p.x()-detDx, p.y()-detDy);
  v.normalize();
  return localCoordinates.transposed()*v;
}

Vec3D LauePlaneProjector::det2scattered(const QPointF& p, bool& b) const{
  Vec3D v(1.0 , p.x()-detDx, p.y()-detDy);
  v.normalize();
  b=true;
  return localCoordinates.transposed()*v;
}

QPointF LauePlaneProjector::normal2det(const Vec3D& n) const{
  return scattered2det(normal2scattered(n));
}

QPointF LauePlaneProjector::normal2det(const Vec3D& n, bool& b) const{
  Vec3D v(normal2scattered(n, b));
  if (b) {
    return scattered2det(v,b);
  } else {
    return QPointF();
  }
}

Vec3D LauePlaneProjector::det2normal(const QPointF& p)  const {
  return scattered2normal(det2scattered(p));
}

Vec3D LauePlaneProjector::det2normal(const QPointF& p, bool& b)  const {
  Vec3D v(det2scattered(p, b));
  if (b) {
    return scattered2normal(v,b);
  } else {
    return Vec3D();
  }
}

void LauePlaneProjector::setDetSize(double dist, double width, double height) {
  if ((detDist!=dist) or (detWidth!=width) or (detHeight!=height)) {
    detDist=dist;
    detWidth=width;
    detHeight=height;

    scene.setSceneRect(QRectF(-0.5*detWidth/detDist, -0.5*detHeight/detDist, detWidth/detDist, detHeight/detDist));
    if (projectionEnabled) {
      emit projectionRectSizeChanged();
      emit projectionParamsChanged();
    }
  }
}

void LauePlaneProjector::setDetOrientation(double omega, double chi, double phi) {
  if ((detOmega!=omega) or (detChi!=chi) or (detPhi!=phi)) {
    detOmega=omega;
    detChi=chi;
    detPhi=phi;
    
    localCoordinates =Mat3D(Vec3D(0,0,1), M_PI*(omega-180.0)/180.0);
    localCoordinates*=Mat3D(Vec3D(0,1,0), M_PI*chi/180.0);
    localCoordinates*=Mat3D(Vec3D(1,0,0), M_PI*phi/180.0);
    //localCoordinates=Mat3D(Vec3D(0,0,1), M_PI*(omega-180.0)/180.0)*Mat3D(Vec3D(0,1,0), M_PI*chi/180.0)*Mat3D(Vec3D(1,0,0), M_PI*phi/180.0);
    movedPBMarker();
    //emit projectionParamsChanged();
  }
}

void LauePlaneProjector::setDetOffset(double dx, double dy) {
  dx/=dist();
  dy/=dist();
  detDx=dx;
  detDy=dy;
  updatePBPos();
  if (projectionEnabled)
    emit projectionParamsChanged();
}


void LauePlaneProjector::setDist(double v) {
  setDetSize(v, width(), height());
}

void LauePlaneProjector::setWidth(double v) {
  setDetSize(dist(), v, height());
}

void LauePlaneProjector::setHeight(double v) {
  setDetSize(dist(), width(), v);
}

void LauePlaneProjector::setOmega(double v) {
  setDetOrientation(v, chi(), phi());
}

void LauePlaneProjector::setChi(double v) {
  setDetOrientation(omega(), v, phi());
}

void LauePlaneProjector::setPhi(double v) {
  setDetOrientation(omega(), chi(), v);
}

void LauePlaneProjector::setXOffset(double v) {
  setDetOffset(v, yOffset());
}

void LauePlaneProjector::setYOffset(double v) {
  setDetOffset(xOffset(), v);
}


bool LauePlaneProjector::project(const Reflection &r, QPointF& p) {
  if (r.lowestDiffOrder==0)
    return false;

  bool doesReflect=false;
  for (int i=0; i<r.orders.size(); i++) {
    int n=r.orders[i];
    if ((2.0*QminVal<=n*r.Qscatter) and (n*r.Qscatter<=2.0*QmaxVal)) {
      doesReflect=true;
      break;
    }
  }
  if (not doesReflect)
    return false;

  Vec3D v=localCoordinates*r.scatteredRay;
  double s=v.x();
  if (s<1e-10)
    return false;


  s=1.0/s;
  p.setX(v.y()*s+detDx);
  p.setY(v.z()*s+detDy);
  return true;
}

void LauePlaneProjector::decorateScene() {
  while (!decorationItems.empty()) {
    QGraphicsItem* item = decorationItems.takeLast();
    scene.removeItem(item);
    delete item;
  }

  CircleItem* center=new CircleItem(getSpotSize(), imageItemsPlane);

  center->setColor(Qt::red);
  center->setFlag(QGraphicsItem::ItemIsMovable, true);
  center->setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
  center->setCursor(Qt::SizeAllCursor);
  center->setTransform(QTransform::fromScale(det2img.m11(), det2img.m22()));

  CircleItem* marker=new CircleItem(0.1, center);
  marker->setColor(Qt::red);

  CircleItem* handle=new CircleItem(getSpotSize(), center);
  handle->setColor(Qt::red);
  handle->setPos(0.2, 0);
  handle->setFlag(QGraphicsItem::ItemIsMovable, true);
  handle->setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
  handle->setCursor(Qt::SizeAllCursor);

  connect(this, SIGNAL(spotSizeChanged(double)), center, SLOT(setRadius(double)));
  connect(this, SIGNAL(spotSizeChanged(double)), handle, SLOT(setRadius(double)));

  decorationItems.append(center);
  decorationItems.append(handle);
  decorationItems.append(marker);

  updatePBPos();


  connect(center, SIGNAL(positionChanged()), this, SLOT(movedPBMarker()));
  connect(handle, SIGNAL(positionChanged()), this, SLOT(resizePBMarker()));
  resizePBMarker();
}


void LauePlaneProjector::resizePBMarker() {
  if (decorationItems.size()<3)
    return;

  //CircleItem* center=dynamic_cast<CircleItem*>(decorationItems[0]);
  CircleItem* handle=dynamic_cast<CircleItem*>(decorationItems[1]);
  CircleItem* marker=dynamic_cast<CircleItem*>(decorationItems[2]);

  QPointF p=handle->pos();
  double l=hypot(p.x(), p.y());

  marker->setRadius(l);
}

void LauePlaneProjector::movedPBMarker() {
  if (decorationItems.size()<3)
    return;
  CircleItem* center=dynamic_cast<CircleItem*>(decorationItems[0]);
  QPointF p=center->scenePos();
  QPointF p2 = center->pos();

  bool b=false;
  QPointF q;
  if (omega()>90.5) {
    q=(scattered2det(Vec3D(1,0,0), b));
  } else if (omega()<89.5) {
    q=scattered2det(Vec3D(-1,0,0), b);
  }
  if (b) {
    setDetOffset(xOffset()+(p.x()-q.x())*dist(), yOffset()+(p.y()-q.y())*dist());
  }
}

void LauePlaneProjector::updatePBPos() {
  bool b=false;
  QPointF q;
  if (omega()>90.5) {
    q=(scattered2det(Vec3D(1,0,0), b));
  } else if (omega()<89.5) {
    q=scattered2det(Vec3D(-1,0,0), b);
  }
  if (b and decorationItems.size()>2) {
    CircleItem* center=dynamic_cast<CircleItem*>(decorationItems[0]);
    center->setPosNoSig(det2img.map(q));
  }
}

QWidget* LauePlaneProjector::configWidget() {
  return new LauePlaneCfg(this);
}

QString LauePlaneProjector::projectorName() {
  return QString("LauePlaneProjector");
}

QString LauePlaneProjector::displayName() {
  return QString("Laue Plane");
}


double LauePlaneProjector::dist() const {
  return detDist;
}

double LauePlaneProjector::width() const {
  return detWidth;
}

double LauePlaneProjector::height() const {
  return detHeight;
}
double LauePlaneProjector::omega() const {
  return detOmega;
}

double LauePlaneProjector::chi() const {
  return detChi;
}

double LauePlaneProjector::phi() const {
  return detPhi;
}

double LauePlaneProjector::xOffset() const {
  return detDx*dist();
}

double LauePlaneProjector::yOffset() const {
  return detDy*dist();
}

void LauePlaneProjector::doImgRotation(const QTransform& t) {
  Projector::doImgRotation(t);
  // TODO: change detector size
  QTransform Tinv = t.inverted();
  QPointF c = Tinv.map(QPointF(0,0));
  QPointF x = Tinv.map(QPointF(1,0));
  double dw = hypot((x.x()-c.x())*detWidth, (x.y()-c.y())*detHeight);
  x = Tinv.map(QPointF(0,1));
  double dh = hypot((x.x()-c.x())*detWidth, (x.y()-c.y())*detHeight);
  setDetSize(dist(), dw, dh);
}





double LauePlaneProjector::fitParameterValue(unsigned int n) {
  switch (n)  {
  case 0:
    return dist();
  case 1:
    return xOffset();
  case 2:
    return yOffset();
  case 3:
    return omega();
  case 4:
    return chi();
  }
  return 0.0;
}

void LauePlaneProjector::fitParameterSetValue(unsigned int n, double val) {
  switch (n)  {
  case 0:
    return setDetSize(val, width(), height());
  case 1:
    return setDetOffset(val, yOffset());
  case 2:
    return setDetOffset(xOffset(), val);;
  case 3:
    return setDetOrientation(val, chi(), phi());
  case 4:
    return setDetOrientation(omega(), val, phi());
  }
}


void LauePlaneProjector::saveToXML(QDomElement base) {
  QDomDocument doc = base.ownerDocument();
  QDomElement projector = (base.tagName()=="Projector") ? base : base.appendChild(doc.createElement("Projector")).toElement();

  QDomElement e = projector.appendChild(doc.createElement("DetSize")).toElement();
  e.setAttribute("width", width());
  e.setAttribute("height", height());
  e.setAttribute("dist", dist());

  e = projector.appendChild(doc.createElement("DetOrientation")).toElement();
  e.setAttribute("Omega", omega());
  e.setAttribute("Chi", chi());
  e.setAttribute("Phi", phi());

  e = projector.appendChild(doc.createElement("DetOffset")).toElement();
  e.setAttribute("xOffset", xOffset());
  e.setAttribute("yOffset", yOffset());

  Projector::saveToXML(projector);
}

bool LauePlaneProjector::parseXMLElement(QDomElement e) {
  bool ok;
  if (e.tagName()=="DetSize") {
    double detW = e.attribute("width").toDouble(&ok); if (!ok) return false;
    double detH = e.attribute("height").toDouble(&ok); if (!ok) return false;
    double detD = e.attribute("dist").toDouble(&ok); if (!ok) return false;
    setDetSize(detD, detW, detH);
  } else if (e.tagName()=="DetOrientation") {
    double detC = e.attribute("Chi").toDouble(&ok); if (!ok) return false;
    double detP = e.attribute("Phi").toDouble(&ok); if (!ok) return false;
    double detO = e.attribute("Omega").toDouble(&ok); if (!ok) return false;
    setDetOrientation(detO, detC, detP);
  } else if (e.tagName()=="DetOffset") {
    double detX = e.attribute("xOffset").toDouble(&ok); if (!ok) return false;
    double detY = e.attribute("yOffset").toDouble(&ok); if (!ok) return false;
    setDetOffset(detX, detY);
  } else {
    return Projector::parseXMLElement(e);
  }
  return true;
}

double LauePlaneProjector::TTmax() const {
  Vec3D n(1.0, 0.0, 0.0);
  double mc=maxCos(n);
  return 180.0-180.0*acos(mc)/M_PI;
}

double LauePlaneProjector::TTmin() const {
  Vec3D n(-1.0, 0.0, 0.0);
  double mc=maxCos(n);
  return 180.0*acos(mc)/M_PI;
}


double LauePlaneProjector::maxCos(Vec3D n) const {
  double dx = 0.5*width()/dist();
  double dy = 0.5*height()/dist();

  bool b;
  QPointF p=scattered2det(n, b);
  if (b and (fabs(p.x())<dx) and (fabs(p.y())<dy))
    return 1.0;

  // The four corners of the plane, vectors are normalized!
  QList<Vec3D> corners;
  corners.append(det2scattered(QPointF( dx,  dy)));
  corners.append(det2scattered(QPointF(-dx,  dy)));
  corners.append(det2scattered(QPointF(-dx, -dy)));
  corners.append(det2scattered(QPointF( dx, -dy)));

  // small value
  double maxCosTT=-2.0;

  for (unsigned int i=0; i<4; i++) {
    // Check one corner
    Vec3D a(corners[i]);
    double cosTT=n*a;
    if (cosTT>maxCosTT)
      maxCosTT=cosTT;


    Vec3D b=corners[(i+1)%4]-corners[i];
    double denom = ((n*a)*(b*b)-(n*b)*(a*b));
    if (denom!=0.0) {
      double lmin = ((n*b)*(a*a)-(n*a)*(a*b))/denom;
      if ((lmin>=0.0) and (lmin<=1.0)) {
        Vec3D v=a+b*lmin;
        v.normalize();
        cosTT=n*v;
        if (cosTT>maxCosTT)
          maxCosTT=cosTT;
      }
    }
  }

  return maxCosTT;
}

void LauePlaneProjector::loadParmetersFromImage(LaueImage *img) {
  QSizeF imgSize;
  if (img->hasAbsoluteSize()) {
    imgSize = img->absoluteSize();
  } else {
    double scale = sqrt(width()*height()/img->width()/img->height());
    imgSize = QSizeF(scale*img->width(), scale*img->height());
  }
  setDetSize(dist(), imgSize.width(), imgSize.height());
}



bool LauePlaneProjector_registered = ProjectorFactory::registerProjector("LauePlaneProjector", &LauePlaneProjector::getInstance);
