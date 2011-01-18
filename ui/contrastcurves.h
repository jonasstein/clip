#ifndef CONTRASTCURVES_H
#define CONTRASTCURVES_H

#include <QWidget>
#include <QGraphicsScene>
#include <QPointer>

#include "image/laueimage.h"
#include "tools/circleitem.h"

class LaueImage;
class BezierCurve;
class ObjectStore;
class HistogramItem;

namespace Ui {
    class ContrastCurves;
}

class ContrastCurves : public QWidget
{
    Q_OBJECT

public:
    explicit ContrastCurves(LaueImage* img, QWidget *parent = 0);
    virtual ~ContrastCurves();
    void mousePressEvent(QMouseEvent *);
  public slots:
    void loadFromFile(const QString&);
    void saveToFile(const QString&);
    void newMarker(const QPointF&);
    void changeToCurve(int);
    void markerChanged();
    void updateCurveLines(int);
    void makeScales();
    void makeHScale();
    void makeVScale();
  private:
    class BoundedEllipse: public CircleItem {
    public:
      BoundedEllipse(QGraphicsItem *parent=0);
      QVariant itemChange(GraphicsItemChange change, const QVariant & value);
      void setBBox(const QRectF& b) { bbox = b; }
      bool operator<(const BoundedEllipse& o);
    private:
      QRectF bbox;
    };

    Ui::ContrastCurves *ui;
    QPointer<LaueImage> laueImage;
    QGraphicsScene scene;
    QList<BoundedEllipse*> handleMarkers;
    QList<QGraphicsPathItem*> curves;
    int activeCurve;
    HistogramItem* histogram;


private slots:
    void on_defaultCurveSelector_activated(int index);
    void on_saveButton_clicked();
    void on_loadButton_clicked();
};

#endif // CONTRASTCURVES_H
