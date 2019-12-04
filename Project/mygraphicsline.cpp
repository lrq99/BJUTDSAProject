#include "mygraphicsline.h"
#include <QPainter>
#include <QCursor>
#include <QDebug>
#include <QMessageBox>
MyGraphicsShortestLine::MyGraphicsShortestLine(int x1, int y1, int x2, int y2, int num, QGraphicsItem *parent):
    QGraphicsItem(parent)
{
    this->setAcceptHoverEvents(true);
    setFlag(QGraphicsItem::ItemIsFocusable);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(dynamicControl()));
    timer->start(1);
    point.setX(x1);
    point.setY(y1);
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
    this->num = num;
    stepx = x1 < x2 ? 0.2 : -0.2;
    stepy = y1 < y2 ? 0.2 : -0.2;
    k = (y2 - y1)*1.0 / (x2 - x1)*1.0;
    if(k < 0) stepy = -stepy;
}
void MyGraphicsShortestLine::dynamicControl(){

    double x = x1 + stepx;
    double y = y1 + (k * stepy);
    point.setX(x);
    point.setY(y);
    this->scene()->update();
    if(fabs(x - x2) < 0.2 || fabs(y - y2) < 0.2){
        timer->stop();
    }
    if(stepx > 0) stepx += 0.2;
    if(stepx < 0) stepx -= 0.2;
    if(stepy > 0) stepy += 0.2;
    if(stepy < 0) stepy -= 0.2;


}

MyGraphicsShortestLine::~MyGraphicsShortestLine(){}

QRectF MyGraphicsShortestLine::boundingRect()const{
    return QRectF(x1, y1, x2 - x1, y2 - y1);

}
void MyGraphicsShortestLine::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Q_UNUSED(widget);
    Q_UNUSED(option);
    painter->setRenderHint(QPainter::Antialiasing, true);//Antialiasing
    painter->setPen(QPen(Qt::black, 4));
    painter->drawLine(QPointF(x1, y1), point);
}
void MyGraphicsShortestLine::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    this->setCursor(QCursor(Qt::PointingHandCursor));
    QGraphicsItem::hoverEnterEvent(event);
}
void MyGraphicsShortestLine::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    this->setCursor(QCursor(Qt::ArrowCursor));
    QGraphicsItem::hoverLeaveEvent(event);
}
void MyGraphicsShortestLine::mousePressEvent(QGraphicsSceneMouseEvent* event){
    if(num == 1)
        QMessageBox::information(nullptr, "tip", "Shortest Path!");
    else
        QMessageBox::information(nullptr, "tip", "Candidate Path!");

}
