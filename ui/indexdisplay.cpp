#include "indexdisplay.h"
#include "ui_indexdisplay.h"

#include <iostream>

#include "core/crystal.h"
#include "core/projector.h"
#include "indexing/indexer.h"
using namespace std;

IndexDisplay::IndexDisplay(Crystal* _c, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Indexing),
    crystal(_c)
{
    ui->setupUi(this);
}

IndexDisplay::~IndexDisplay()
{
    delete ui;
}

void IndexDisplay::on_startButton_clicked()
{
  QList<Vec3D> spotMarkerNormals;
  QList<Vec3D> zoneMarkerNormals;
  foreach (Projector* p, crystal->getConnectedProjectors()) {
    spotMarkerNormals += p->getSpotMarkerNormals();
    zoneMarkerNormals += p->getZoneMarkerNormals();
  }

  Indexer indexer(spotMarkerNormals, zoneMarkerNormals, crystal->getRealOrientationMatrix(), crystal->getReziprocalOrientationMatrix());

  cout << "Start indexing" << endl;
  indexer.run();
  cout << "Indexing ended" << endl;


}
