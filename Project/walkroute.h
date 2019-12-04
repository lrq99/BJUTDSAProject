    #ifndef WALKROUTE_H
#define WALKROUTE_H
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
#include "disjointset.h"
#include "pathsolve.h"
#include "dataprocess.h"
#include "graphicsdraw.h"
using namespace std;
namespace Ui {
class WalkRoute;
}

class WalkRoute : public QWidget
{
    Q_OBJECT

public:
    MyScene* m_pScene;
    MyView* m_pView;
    QPixmap m_img;
    QGraphicsPixmapItem* m_pPixMapItem;

    ScenicCenterPoint* m_pCenterPoint;
    vector<string> m_WalkAttractionInfo;
    vector<string> m_WalkConnectRelation;
    vector<string> m_WalkScenicPoint;
    map<int, Element> m_mapFNumToElement;
    map<string, Element> m_mapFNameToElement;


    Dist* m_pD;
    Graph* m_pG;
    DataProcess *dp;
    PathSolve *ps;
    GraphicsDraw *gd;

    int m_iRouteNum;
    int type;

    explicit WalkRoute(QWidget *parent = nullptr);
    ~WalkRoute();
public slots:
    void onQueryButtonClicked();
    void recvMsg();
    void onClearButtonClicked();
    void onNextPathButtonClicked();
    void onPrevPathButtonClicked();
private slots:
    void onStartEditTextChanged(const QString &arg1);
    void onEndEditTextChanged(const QString &arg1);

private:
    void resetGraph();

private:
    Ui::WalkRoute *ui;
};

#endif // WALKROUTE_H
