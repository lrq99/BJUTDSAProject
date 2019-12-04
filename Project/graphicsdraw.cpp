#include "graphicsdraw.h"
#include "mygraphicsline.h"
#include "myrect.h"
#include <QObject>
#include <QMessageBox>
GraphicsDraw::GraphicsDraw()
{

}
void GraphicsDraw::drawCenterPoint(ScenicCenterPoint* center_point, MyScene *&scene){
    for(size_t i = 1; i <= SCENIC_NUM; i++){
        int x = center_point[i].x;
        int y = center_point[i].y;
        int w = SCENIC_RECT_SIZE;
        int h = SCENIC_RECT_SIZE;
        int type = center_point[i].type;
        MyRect *rect = new MyRect(x, y, w, h, type);
        scene->addItem(rect);
    }
}
void GraphicsDraw::drawPicture(QGraphicsPixmapItem* pixmap_item, QPixmap img, MyScene *&scene){
    pixmap_item = new QGraphicsPixmapItem(img);
    scene->addItem(pixmap_item);
}
double GraphicsDraw::drawKthPath(vector<Element> path, MyScene *&scene, int k){
    double totalLength = 0;
    for(auto it = path.begin(); (it + 1) != path.end(); it++){
        Element first = *it;
        Element second = *(it + 1);
        double x1, x2, y1, y2;
        x1 = first.x; y1 = first.y;
        x2 = second.x; y2 = second.y;
        totalLength += sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        MyGraphicsShortestLine *line = new MyGraphicsShortestLine(x1, y1, x2, y2, k);
        scene->addItem(line);
    }
    return totalLength;

}
