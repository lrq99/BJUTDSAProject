#include "walkroute.h"
#include "graph.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>
#include <QGraphicsItem>
#include <QApplication>
#include <QGraphicsScene>
#include <QWidget>
#include <map>
#include <QPixmap>
#include "dist.h"
#include "welcome.h"
#include "busroute.h"
#include "sceniccenterpoint.h"
#include "dataprocess.h"
#include "element.h"
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Welcome w2;
    WalkRoute w_walk;
    BusRoute w_bus;
    QObject::connect(&w2, SIGNAL(sendOpenWalkMsg()), &w_walk, SLOT(recvMsg()));
    QObject::connect(&w2, SIGNAL(sendOpenBusMsg()), &w_bus, SLOT(recvMsg()));
    w2.show();
    return a.exec();
}
