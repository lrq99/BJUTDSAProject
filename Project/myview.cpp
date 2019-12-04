#include "myview.h"


MyView::MyView(QWidget *parent) :
    QGraphicsView(parent)
{
    setMouseTracking(true);

}

void MyView::mouseMoveEvent(QMouseEvent *event){
    int x = event->x();
    int y = event->y();
    emit sendXYPos(x, y);
    QGraphicsView::mouseMoveEvent(event);
}

void MyView::mousePressEvent(QMouseEvent *event){
    QGraphicsView::mousePressEvent(event);
}
