#ifndef GRAPHICSDRAW_H
#define GRAPHICSDRAW_H
#include <QString>
#include <QMessageBox>
#include <vector>
#include <map>
#include "myscene.h"
#include "element.h"
#include "constant.h"
#include "dataprocess.h"
using namespace std;

class GraphicsDraw
{
public:
    GraphicsDraw();
    void drawCenterPoint(ScenicCenterPoint* center_point, MyScene *&scene);
    void drawPicture(QGraphicsPixmapItem* pixmap_item, QPixmap img, MyScene *&scene);
    double drawKthPath(vector<Element> path, MyScene *&scene, int k = 1);
};

#endif // GRAPHICSDRAW_H
