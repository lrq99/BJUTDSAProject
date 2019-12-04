#ifndef BUSROUTE_H
#define BUSROUTE_H
#include <QGraphicsScene>
#include <QWidget>
#include <map>
#include "graph.h"
#include "element.h"
#include "dist.h"
#include <QMouseEvent>
#include "myview.h"
#include "mygraphicsline.h"
#include "myscene.h"
#include "sceniccenterpoint.h"
#include "myrect.h"
#include "dataprocess.h"
#include "pathsolve.h"
#include "graphicsdraw.h"
using namespace std;
namespace Ui {
class BusRoute;
}


class BusRoute : public QWidget
{
    Q_OBJECT

public:

    vector<string> m_BusAttractionInfo;
    vector<string> m_BusConnectRelation;
    vector<string> m_BusScenicPoint;
    map<int, Element> m_mapFNumToElement;
    map<string, Element> m_mapFNameToElement;
    ScenicCenterPoint* m_pCenterPoint;

    MyScene* m_pScene;
    MyView* m_pView;
    QGraphicsPixmapItem* m_pPixMapItem;
    QPixmap m_img;

    Dist* m_pD;
    Graph* m_pG;
    DataProcess *dp;
    PathSolve *ps;
    GraphicsDraw *gd;

    int type;
    explicit BusRoute(QWidget *parent = nullptr);
    ~BusRoute();
public slots:
    void onQueryButtonClicked();
    void recvMsg();
private slots:
    void onClearButtonClicked();
private:
    void resetGraph();
private:
    Ui::BusRoute *ui;
};

#endif // BUSROUTE_H
