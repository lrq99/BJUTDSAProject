#include "busroute.h"
#include "ui_busroute.h"
#include <QPainter>
#include <QGraphicsItem>
#include "constant.h"
#include <QDebug>
#include <QMessageBox>
#include "list.h"
#include <windows.h>
#include "listnode.h"
#include "dataprocess.h"
BusRoute::BusRoute(QWidget *parent):
    QWidget(parent),
    ui(new Ui::BusRoute)
{
    m_pScene = new MyScene();
    m_pScene->setSceneRect(0, 0, BUSIMG_WIDTH, BUSIMG_HEIGHT);
    m_pView = new MyView(this);
    m_pView->setGeometry(30, 30, BUSIMG_WIDTH, BUSIMG_HEIGHT);
    m_img.load("../../MapInformation/BusRoute.jpg");
    m_pPixMapItem = new QGraphicsPixmapItem(m_img);
    m_pScene->addItem(m_pPixMapItem);
    ui->setupUi(this);
    m_pView->setStyleSheet("padding: 0px; border: 0px;");
     m_pView->setScene(m_pScene);
    setMouseTracking(true);

    m_BusAttractionInfo = dp->readFile("../../MapInformation/BusAttractionInfo.txt");
    m_BusConnectRelation = dp->readFile("../../MapInformation/BusConnectRelation.txt");

    m_pG = new Graph(static_cast<int>(m_BusAttractionInfo.size() + 5));
    m_pD = new Dist[m_pG->vertexNum()];

    dp = new DataProcess();

    gd = new GraphicsDraw();
    dp->getAttractionInfo(m_BusAttractionInfo, m_mapFNumToElement, m_mapFNameToElement);
    dp->getConnectRelation(m_BusConnectRelation, m_pG, false);
    ps = new PathSolve(m_pG, m_pD, m_mapFNumToElement, m_mapFNameToElement);

    connect(ui->queryButton, SIGNAL(clicked()), this, SLOT(onQueryButtonClicked()));
    connect(ui->clearButton, SIGNAL(clicked()), this, SLOT(onClearButtonClicked()));
}

void BusRoute::resetGraph(){
    for(int i = 1; i < m_pG->vertex_num; i++){
        m_pG->mark[i] = false;
        m_pD[i].d = inf;
        m_pD[i].path = 1;
    }
}
BusRoute::~BusRoute()
{
    delete ui;
}

void BusRoute::onQueryButtonClicked()
{
    QString start_string = ui->startEdit->text();
    QString end_string = ui->endEdit->text();
    bool test_success = ps->testLocationExist(start_string.toStdString(), end_string.toStdString());
    if(!test_success) return;
    int start_loc_num;
    int end_loc_num;
    ps->getNumByName(start_string.toStdString(), start_loc_num);
    ps->getNumByName(end_string.toStdString(), end_loc_num);
    m_pScene->clear();
    gd->drawPicture(m_pPixMapItem, m_img, m_pScene);
    ui->startloc->setText("Start : " + start_string);
    ui->endloc->setText("End : " + end_string);

    Info info = ps->dijkstra(start_loc_num, end_loc_num);
    vector<Element> path = info.path;
    Element transform_elem = info.target_elem;
    double length = gd->drawKthPath(path, m_pScene);
    ui->totallen->setText("Totol Length : " + QString::number(length));
    if(transform_elem.node_name == " ")
        ui->transformloc->setText("Transform : None");
    else
        ui->transformloc->setText("Transform : " + QString::fromStdString(transform_elem.node_name));
    m_pView->setScene(m_pScene);
}
void BusRoute::recvMsg()
{
    this->show();
}

void BusRoute::onClearButtonClicked()
{
    ui->startEdit->clear();
    ui->endEdit->clear();
    m_pScene->clear();
    gd->drawPicture(m_pPixMapItem, m_img, m_pScene);
    ui->startloc->setText("Start : ");
    ui->endloc->setText("End : ");
    ui->transformloc->setText("Transform : ");
    ui->totallen->setText("Total Length : ");
}


