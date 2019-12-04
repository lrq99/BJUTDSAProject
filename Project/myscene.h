#ifndef MYSCENE_H
#define MYSCENE_H
#include <QGraphicsScene>
#include <QMouseEvent>

class MyScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit MyScene(QObject* parent = nullptr);
protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
};

#endif // MYSCENE_H
