#include "dataprocess.h"
DataProcess::DataProcess(){}
DataProcess::DataProcess(map<int, Element> m_mapFNumToElement, map<string, Element> m_mapFNameToElement){
    this->m_mapFNumToElement = m_mapFNumToElement;
    this->m_mapFNameToElement = m_mapFNameToElement;
}
void DataProcess::split(const string& s,vector<string>& sv,const char flag) {
    sv.clear();
    istringstream iss(s);
    string temp;
    while (getline(iss, temp, flag)) {
        sv.push_back(temp);
    }
    return;
}
vector<string> DataProcess::readFile(string fileName){
    ifstream f(fileName);
    vector<string> s;
    while(f.good()){
        string str;
        getline(f, str);
        s.push_back(str);
    }
    f.close();
    return s;
}


void DataProcess::getAttractionInfo(vector<string>& AttractionInfo,
                       map<int, Element>& fNumToElement,
                       map<string, Element>& fNameToElement){
    vector<string> LineInfo;
    for(int i = 0; i < AttractionInfo.size(); i++){
        split(AttractionInfo[i], LineInfo, ',');
        Element elem;
        elem.x = atoi(LineInfo[0].c_str());
        elem.y = atoi(LineInfo[1].c_str());
        elem.node_type = LineInfo[3][0];
        elem.node_name =  LineInfo[2];
        elem.index = atoi(LineInfo[4].c_str());
        fNumToElement[elem.index] = elem;
        if(elem.node_name.size() >= 3){
            fNameToElement[elem.node_name] = elem;
            qDebug() << QString::fromStdString(elem.node_name);
        }
        LineInfo.clear();
    }
}
void DataProcess::getConnectRelation(vector<string>& ConnectRelation, Graph*& g, bool is_walk_type){
    vector<string> LineInfo;
    for(size_t i = 0; i < ConnectRelation.size(); i++){
        split(ConnectRelation[i], LineInfo, ',');
        int from = atoi(LineInfo[0].c_str());
        int to = atoi(LineInfo[1].c_str());
        double x1 = atof(LineInfo[2].c_str());
        double y1 = atof(LineInfo[3].c_str());
        double x2 = atof(LineInfo[4].c_str());
        double y2 = atof(LineInfo[5].c_str());
        double weight = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
        g->setEdge(from, to, weight);
        if(is_walk_type == true)
            g->setEdge(to, from, weight);
    }
}
void DataProcess::getScenicPoint(vector<string>& ScenicPoint, ScenicCenterPoint* &CenterPoint){
    CenterPoint = new ScenicCenterPoint[ScenicPoint.size() + 1];
    vector<string> LineInfo;
    for(size_t i = 0; i < ScenicPoint.size(); i++){
        split(ScenicPoint[i], LineInfo, ',');
        int x = atoi(LineInfo[0].c_str());
        int y = atoi(LineInfo[1].c_str());
        int type = atoi(LineInfo[2].c_str());
        CenterPoint[i + 1].x = x;
        CenterPoint[i + 1].y = y;
        CenterPoint[i + 1].type = type;
    }
}
