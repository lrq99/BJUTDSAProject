#ifndef DATAPROCESS_H
#define DATAPROCESS_H
#include <vector>
#include <map>
#include "element.h"
#include <sstream>
#include <fstream>
#include <QDebug>
#include "sceniccenterpoint.h"
#include "graph.h"
using namespace std;
class DataProcess{
public:
    map<int, Element> m_mapFNumToElement;
    map<string, Element> m_mapFNameToElement;
    DataProcess();
    DataProcess(map<int, Element> m_mapFNumToElement, map<string, Element> m_mapFNameToElement);

    void split(const string& s,vector<string>& sv,const char flag);
    vector<string> readFile(string fileName);
    void getAttractionInfo(vector<string>& AttractionInfo,
                           map<int, Element>& fNumToElement,
                           map<string, Element>& fNameToElement);
    void getConnectRelation(vector<string>& ConnectRelation, Graph*& g, bool is_walk_type);
    void getScenicPoint(vector<string>& ScenicPoint, ScenicCenterPoint* &CenterPoint);
};

#endif // DATAPROCESS_H
