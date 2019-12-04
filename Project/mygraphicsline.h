  #ifndef MYGRAPHICSLINE_H
#define MYGRAPHICSLINE_H
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include "manager.h"
class MyGraphicsShortestLine : public Manager, public QGraphicsItem
{
    Q_OBJECT
public:
    int x1, y1, x2, y2;
    int num;
    double stepx, stepy;
    double k;
    QPointF point;
    QTimer *timer;
    MyGraphicsShortestLine(int x1, int y1, int x2, int y2, int num = 1, QGraphicsItem *parent = nullptr);
    ~MyGraphicsShortestLine();
protected:
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
public slots:
    void dynamicControl();
};

#endif // MYGRAPHICSLINE_H
