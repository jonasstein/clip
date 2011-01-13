#include "projectiongraphicsview.h"
#include <QMouseEvent>
#include <QTime>
#include <QGraphicsItem>
#include <QString>
#include <iostream>

using namespace std;

ProjectionGraphicsView::ProjectionGraphicsView(QWidget *parent) :
    QGraphicsView(parent) {
  viewIgnoresThisMouseEvent=false;
  frames=0;
}

void ProjectionGraphicsView::dragEnterEvent(QDragEnterEvent *e) {
  if (!not e->mimeData()->hasFormat("application/CrystalPointer"))
    QGraphicsView::dragEnterEvent(e);
  e->ignore();
}

void ProjectionGraphicsView::mousePressEvent(QMouseEvent *e) {
  QGraphicsView::mousePressEvent(e);
  viewIgnoresThisMouseEvent = (e->button()!=Qt::LeftButton) || !e->isAccepted();
  e->setAccepted(!viewIgnoresThisMouseEvent);
}

void ProjectionGraphicsView::mouseMoveEvent(QMouseEvent *e) {
  emit mouseMoved(mapToScene(e->pos()));
  if (viewIgnoresThisMouseEvent) {
    e->ignore();
  } else {
    QGraphicsView::mouseMoveEvent(e);
  }
}

void ProjectionGraphicsView::mouseReleaseEvent(QMouseEvent *e) {
  if (viewIgnoresThisMouseEvent) {
    e->ignore();
    viewIgnoresThisMouseEvent=false;
  } else {
    QGraphicsView::mouseReleaseEvent(e);
  }
}

void ProjectionGraphicsView::leaveEvent(QEvent *) {
  emit mouseLeft();
}

int ProjectionGraphicsView::getFrames() {
  int f = frames;
  frames = 0;
  return f;
}

void ProjectionGraphicsView::paintEvent(QPaintEvent *e) {
  QGraphicsView::paintEvent(e);
  frames++;
}

void ProjectionGraphicsView::setImage(LaueImage * img) {
  image = img;
}

#include <QPaintEngine>
#include <QImage>
#include <QRectF>
#include <tools/debug.h>

QPolygonF rectToPoly(const QRectF& r) {
  QPolygonF poly;
  poly << r.topLeft() << r.topRight() << r.bottomRight() << r.bottomLeft();
  return poly;
}

void ProjectionGraphicsView::drawBackground(QPainter *painter, const QRectF &rect) {
  if (image.isNull()) {
    painter->fillRect(rect, Qt::white);

  } else {
    // Rect in scene coordinates of what is actually visible in the view
    // sometimes a little bit more than sceneRect()!!!

    QTransform viewportTransform = painter->worldTransform();
    QRectF visibleRect = QRectF(mapToScene(0, 0), mapToScene(viewport()->width(), viewport()->height())).normalized();

    QRectF imgRect = viewportTransform.mapRect(visibleRect);
    QRect sourceRect = viewportTransform.mapRect(rect).toRect();

    QTransform zoomTransform;
    QTransform::quadToSquare(rectToPoly(sceneRect()), zoomTransform);
    zoomTransform = QTransform::fromScale(1, -1) * zoomTransform;

    QImage cache = image->getScaledImage(imgRect.size().toSize(), rectToPoly(zoomTransform.mapRect(visibleRect)));

    painter->resetTransform();
    painter->drawImage(sourceRect, cache, sourceRect);
    painter->setTransform(viewportTransform);
  }
}

