#ifndef MYVIEW_H
#define MYVIEW_H
#include <QGraphicsView>
#include <QMouseEvent>
class MyView : public QGraphicsView{
    Q_OBJECT
public:
    explicit MyView(QWidget* parent = nullptr);
protected:
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
signals:
    void sendXYPos(int x, int y);
};

#endif // MYVIEW_H
