#include "walkroute.h"
#include "ui_walkroute.h"
#include <QPainter>
#include <QGraphicsItem>
#include "constant.h"
#include <QMessageBox>
#include "list.h"
#include <windows.h>
#include "listnode.h"
#include <queue>
#include "dataprocess.h"
#include "pathsolve.h"
#include <QLineEdit>
WalkRoute::WalkRoute(QWidget *parent):
    QWidget(parent),
    ui(new Ui::WalkRoute)
{
    m_iRouteNum = 0;

    m_pScene = new MyScene();
    m_pScene->setSceneRect(0, 0, IMG_WIDTH, IMG_HEIGHT);
    m_pView = new MyView(this);
    m_pView->setGeometry(30, 30, IMG_WIDTH, IMG_HEIGHT);
    m_img.load("../../MapInformation/GuidePic.jpg");
    m_pPixMapItem = new QGraphicsPixmapItem(m_img);
    ui->setupUi(this);
    this->resize(WINDOW_WIDTH, WINDOW_HEIGHT);
    m_pView->setStyleSheet("padding: 0px; border: 0px;");
    m_pScene->addItem(m_pPixMapItem);
    m_pView->setScene(m_pScene);
    setMouseTracking(true);


    m_WalkAttractionInfo = dp->readFile("../../MapInformation/AttractionInfo.txt");
    m_WalkConnectRelation = dp->readFile("../../MapInformation/ConnectRelation.txt");
    m_WalkScenicPoint = dp->readFile("../../MapInformation/ScenicPoint.txt");

    dp = new DataProcess();
    gd = new GraphicsDraw();

    m_pG = new Graph(static_cast<int>(m_WalkAttractionInfo.size() + 5));
    m_pD = new Dist[m_pG->vertexNum()]();

    dp->getAttractionInfo(m_WalkAttractionInfo, m_mapFNumToElement, m_mapFNameToElement);
    dp->getConnectRelation(m_WalkConnectRelation, m_pG, true);
    dp->getScenicPoint(m_WalkScenicPoint, m_pCenterPoint);

    ps = new PathSolve(m_pG, m_pD, m_mapFNumToElement, m_mapFNameToElement);
    gd->drawCenterPoint(m_pCenterPoint, m_pScene);

    connect(ui->queryButton, SIGNAL(clicked()), this, SLOT(onQueryButtonClicked()));
    connect(ui->ClearButton, SIGNAL(clicked()), this, SLOT(onClearButtonClicked()));
    connect(ui->NextPathButton, SIGNAL(clicked()), this, SLOT(onNextPathButtonClicked()));
    connect(ui->PrevPathButton, SIGNAL(clicked()), this, SLOT(onPrevPathButtonClicked()));
    connect(ui->startEdit, SIGNAL(textChanged(const QString&)), this, SLOT(onStartEditTextChanged(const QString&)));
    connect(ui->endEdit, SIGNAL(textChanged(const QString&)), this, SLOT(onEndEditTextChanged(const QString&)));
}

void WalkRoute::resetGraph(){
    for(int i = 1; i < m_pG->vertex_num; i++){
        m_pG->mark[i] = false;
        m_pD[i].d = inf;
        m_pD[i].path = 1;
    }
}
WalkRoute::~WalkRoute()
{
    delete ui;
}

void WalkRoute::onQueryButtonClicked()
{
    m_iRouteNum = 1;
    QString start_string = ui->startEdit->text();
    QString end_string = ui->endEdit->text();
    bool test_success = ps->testLocationExist(start_string.toStdString(), end_string.toStdString());
    if(!test_success) return;
    int start_loc_num;
    int end_loc_num;
    ps->getNumByName(start_string.toStdString(), start_loc_num);
    ps->getNumByName(end_string.toStdString(), end_loc_num);
    m_pScene->clear();
    ui->LabelStartPos->setText("Start : " + start_string);
    ui->LabelEndPos->setText("End : " + end_string);
    ui->LabelRoute->setText("Route : Shortest");
    vector<Element> path = ps->kShortestPath(start_loc_num, end_loc_num, m_iRouteNum);

    gd->drawPicture(m_pPixMapItem, m_img, m_pScene);
    double length = gd->drawKthPath(path, m_pScene, m_iRouteNum);
    gd->drawCenterPoint(m_pCenterPoint, m_pScene);

    m_pView->setScene(m_pScene);
    ui->totallen->setText("Total Length : " + QString::number(length));
    resetGraph();

}
void WalkRoute::recvMsg()
{
    this->show();
}

void WalkRoute::onClearButtonClicked()
{
    m_iRouteNum = 0;
    ui->startEdit->clear();
    ui->endEdit->clear();
    m_pScene->clear();
    gd->drawPicture(m_pPixMapItem, m_img, m_pScene);
    gd->drawCenterPoint(m_pCenterPoint, m_pScene);
    ui->totallen->setText("Total Length : ");
    ui->LabelStartPos->setText("Start : ");
    ui->LabelEndPos->setText("End : ");
    ui->LabelRoute->setText("Route : ");
    resetGraph();
}

void WalkRoute::onNextPathButtonClicked()
{
    QString start_string = ui->startEdit->text();
    QString end_string = ui->endEdit->text();
    bool test_success = ps->testLocationExist(start_string.toStdString(), end_string.toStdString());
    if(!test_success) return;
    int start_loc_num;
    int end_loc_num;
    ps->getNumByName(start_string.toStdString(), start_loc_num);
    ps->getNumByName(end_string.toStdString(), end_loc_num);
    if(m_iRouteNum + 1 >= 4 || m_iRouteNum == 0){
        QMessageBox::information(nullptr, "tips", "No more Candidate Path");
        return;
    }

    this->m_iRouteNum++;
    if(m_iRouteNum > 1)
        ui->LabelRoute->setText("Route : Candidate " + QString::number(m_iRouteNum - 1));
    else
        ui->LabelRoute->setText("Route : Shortest");

    m_pScene->clear();
    vector<Element> path = ps->kShortestPath(start_loc_num, end_loc_num, m_iRouteNum);

    gd->drawPicture(m_pPixMapItem, m_img, m_pScene);
    double length = gd->drawKthPath(path, m_pScene, m_iRouteNum);
    gd->drawCenterPoint(m_pCenterPoint, m_pScene);

    m_pView->setScene(m_pScene);
    ui->totallen->setText("Total Length : " + QString::number(length));
    resetGraph();
}

void WalkRoute::onPrevPathButtonClicked()
{
    QString start_string = ui->startEdit->text();
    QString end_string = ui->endEdit->text();
    bool test_success = ps->testLocationExist(start_string.toStdString(), end_string.toStdString());
    if(!test_success) return;
    int start_loc_num;
    int end_loc_num;
    ps->getNumByName(start_string.toStdString(), start_loc_num);
    ps->getNumByName(end_string.toStdString(), end_loc_num);
    if(m_iRouteNum - 1 <= 0 || m_iRouteNum == 0){
        QMessageBox::information(nullptr, "tips", "No more Candidate Path");
        return;
    }
    this->m_iRouteNum--;
    if(m_iRouteNum > 1)
        ui->LabelRoute->setText("Route : Candidate " + QString::number(m_iRouteNum - 1));
    else
        ui->LabelRoute->setText("Route : Shortest");
    m_pScene->clear();
    vector<Element> path = ps->kShortestPath(start_loc_num, end_loc_num, m_iRouteNum);
    gd->drawPicture(m_pPixMapItem, m_img, m_pScene);
    double length = gd->drawKthPath(path, m_pScene, m_iRouteNum);
    gd->drawCenterPoint(m_pCenterPoint, m_pScene);
    m_pView->setScene(m_pScene);
    ui->totallen->setText("Total Length : " + QString::number(length));
    resetGraph();
}

void WalkRoute::onStartEditTextChanged(const QString &arg1)
{
    m_iRouteNum = 0;
}

void WalkRoute::onEndEditTextChanged(const QString &arg1)
{
    m_iRouteNum = 0;
}
