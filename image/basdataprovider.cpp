#include "basdataprovider.h"
#include <image/dataproviderfactory.h>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QTextStream>
#include <iostream>
#include <cmath>

#ifdef WIN32
#include <winsock2.h>
#else
#include <netinet/in.h>
#endif

using namespace std;

BasDataProvider::BasDataProvider(QObject *parent) :
    DataProvider(parent)
{
  cout << "init BasDataProvider" << endl;
}

DataProvider* BasDataProvider::loadImage(const QString& filename) {
  cout << "BasDP tries to load " << qPrintable(filename) << endl;

  QFileInfo info(filename);

  // Return if file does not exist
  if (!info.exists() || !info.isReadable()) return NULL;

  // Check if suffix is .inf or .img
  QString suffix = info.suffix().toLower();
  if (suffix!="img" && suffix!="inf") return NULL;

  // search the second file (img or inf)
  QString secondSuffix = (suffix=="img")?"inf":"img";
  QDir dir(info.path());
  QStringList filter;
  filter << info.completeBaseName()+".*";
  QFileInfo info2;
  bool ok=false;
  foreach (QFileInfo i, dir.entryInfoList(filter, QDir::Files|QDir::Readable|QDir::CaseSensitive)) {
    if (i.suffix().toLower()==secondSuffix) {
      info2 = i;
      ok=true;
      break;
    }
  }
  if (!ok) return NULL;

  QFile infFile((suffix=="inf")?info.filePath():info2.filePath());
  QFile imgFile((suffix=="img")?info.filePath():info2.filePath());

  if (!infFile.open(QFile::ReadOnly) || !imgFile.open(QFile::ReadOnly)) return NULL;

  QTextStream inf(&infFile);

  if (inf.readLine()!="BAS_IMAGE_FILE") return NULL;

  QStringList keyValues;
  keyValues << "OriginalFilename" << "IP-Size" << "X-PixelPerMM" << "Y-PixelPerMM"
      << "BitsPerPixel" << "Width" << "Height" << "Sensitivity" << "Latitude" << "Exposure Date"
      << "UnixTime" << "OverflowPixels" << "" << "Comment";
  QStringList intKeyValues;
  intKeyValues << "X-PixelPerMM" << "Y-PixelPerMM"
      << "BitsPerPixel" << "Width" << "Height" << "Sensitivity" << "Latitude"
      << "UnixTime" << "OverflowPixels";


  QMap<QString, QVariant> headerData;
  foreach(QString key, keyValues) {
    if (inf.atEnd()) return NULL;
    QString s = inf.readLine();
    if (key!="") {
      if (intKeyValues.contains(key)) {
        bool ok;
        headerData.insert(key, QVariant(s.toInt(&ok)));
        if (!ok) return NULL;
      } else {
        headerData.insert(key, QVariant(s));
      }
    }
  }

  int pixelCount = headerData["Width"].toInt()*headerData["Height"].toInt();
  int bytesPerPixel = (headerData["BitsPerPixel"].toInt()>8)?2:1;
  int dataSize = pixelCount * bytesPerPixel;
  if (dataSize != imgFile.size()) return NULL;


  QVector<float> pixelData(pixelCount);

  double linscale = 4000.0/headerData["Sensitivity"].toDouble();
  linscale *= headerData["X-PixelPerMM"].toDouble()/100.0;
  linscale *= headerData["Y-PixelPerMM"].toDouble()/100.0;

  double logscale = M_LN10*headerData["Latitude"].toDouble();
  linscale *= exp(-0.5*logscale);
  logscale /= (1<<headerData["BitsPerPixel"].toInt())-1;

  QDataStream in(&imgFile);
  in.setByteOrder(QDataStream::BigEndian);
  if (bytesPerPixel==1) {
    quint8 pixel;
    for (int i=0; i<pixelCount; i++) {
      in >> pixel;
      if (pixel!=0) {
        pixelData[i]=linscale * exp(logscale*pixel);
      }
    }
  } else if (bytesPerPixel==2) {
    quint16 pixel;
    for (int i=0; i<pixelCount; i++) {
      in >> pixel;
      if (pixel!=0) {
        pixelData[i]=linscale * exp(logscale*pixel);
      }
    }
  }

  cout << "Open OK" << endl;
  BasDataProvider* provider = new BasDataProvider();
  provider->headerData = headerData;
  provider->pixelData = pixelData;

  return provider;
}

const void* BasDataProvider::getData() {
  return (void*)pixelData.data();
}

int BasDataProvider::width() {
  return headerData["Width"].toInt();
}

int BasDataProvider::height() {
  return headerData["Height"].toInt();
}

int BasDataProvider::bytesCount() {
  return pixelData.size()*sizeof(float);
}

int BasDataProvider::pixelCount() {
  return pixelData.size();
}

DataProvider::Format BasDataProvider::format() {
  return Float32;
}


bool BasRegisterOK = DataProviderFactory::registerImageLoader(0, &BasDataProvider::loadImage);