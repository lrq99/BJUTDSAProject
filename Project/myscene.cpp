#include "myscene.h"

MyScene::MyScene(QObject* parent) :
    QGraphicsScene (parent)
{

}

void MyScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event){
    QGraphicsScene::mouseMoveEvent(event);
}
void MyScene::mousePressEvent(QGraphicsSceneMouseEvent *event){
    QGraphicsScene::mousePressEvent(event);
}
