#ifndef SCENICPOINT_H
#define SCENICPOINT_H
#include <QGraphicsItem>
#include <QPainter>
#include <constant.h>
#include <QMessageBox>
#include <QDebug>
class MyRect : public QGraphicsItem
{
    int m_nX, m_nY, m_nW, m_nH;
    int m_nType;
public:
    MyRect(int x, int y, int w, int h, int type);
protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
};

#endif // SCENICPOINT_H
