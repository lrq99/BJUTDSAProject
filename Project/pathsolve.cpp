#include "pathsolve.h"
#include <queue>
#include <map>
#include "constant.h"
#include "element.h"
#include "dataprocess.h"
using namespace std;
PathSolve::PathSolve(Graph *m_pG, Dist *m_pD, map<int, Element> m_mapFNumToElement, map<string, Element> m_mapFNameToElement){
    this->m_pD = m_pD;
    this->m_pG = m_pG;
    this->m_mapFNumToElement = m_mapFNumToElement;
    this->m_mapFNameToElement = m_mapFNameToElement;
}

void PathSolve::addToPath(vector<Element> &path, Node *now){
    Element nElem;
    DataProcess dp(m_mapFNumToElement, m_mapFNameToElement);
    while(now->parent){
        nElem = m_mapFNumToElement[now->vertex];
        double x1, y1, x2, y2;
        getLocByNum(now->vertex, x1, y1);
        getLocByNum(now->parent->vertex, x2, y2);
        path.push_back(nElem);
        now = now->parent;
    }
    nElem = m_mapFNumToElement[now->vertex];
    path.push_back(nElem);

}
vector<Element> PathSolve::kShortestPath(int loc_src, int loc_dest, int k){
    dijkstra(loc_dest, loc_src);
    vector<Element> path;
    priority_queue<Node*, vector<Node *>, cmp> *pq = new priority_queue<Node*, vector<Node *>, cmp>();
    Node *src = new Node(m_pD[loc_src].d, 0, loc_src, nullptr);
    pq->push(src);
    int kst = 0;
    Node *last = nullptr;
    while(!pq->empty()){
        Node *now = pq->top();
        pq->pop();

        if(now->vertex == loc_dest){
            kst++;
            if(k == kst){
                addToPath(path, now);
                break;
            }
        }

        for(Edge e = m_pG->firstEdge(now->vertex); m_pG->isEdge(e); e = m_pG->nextEdge(e)){
            Node *next = new Node();
            bool invalid = false;
            Node* tmp = now->parent;
            while(tmp){
                if(tmp->vertex == e.to){
                    invalid = true;
                    break;
                }
                tmp = tmp->parent;
            }
            if(invalid) continue;
            next->g = static_cast<int>(e.weight + now->g);
            next->f = static_cast<int>(m_pD[e.to].d + next->g);
            next->parent = now;
            next->vertex = e.to;
            pq->push(next);
        }

       /*
        for(Edge e = m_pG->firstEdge(now->vertex); m_pG->isEdge(e); e = m_pG->nextEdge(e)){
            Node *next = new Node();
            if(last && e.to == last->vertex) continue;
            if(now->parent && now->parent->vertex == e.to) continue;
            if(e.to == loc_src) continue;
            next->g = static_cast<int>(e.weight + now->g);
            next->f = static_cast<int>(m_pD[e.to].d + next->g);
            next->parent = now;
            next->vertex = e.to;
            pq->push(next);
        }
        last = now;*/
    }
    return path;
}

Info PathSolve::dijkstra(int s, int e){
    m_pD[s].d = 0;
    m_pD[s].path = -1;
    Element e_end = m_mapFNumToElement[e];
    Element e_start = m_mapFNumToElement[s];
    for(int i = 1; i < m_pG->vertexNum(); i++){
       double minv = inf;
       int min = 0;
       for(int j = 1; j < m_pG->vertexNum(); j++){
           if(m_pD[j].d < minv && !m_pG->mark[j]){
               minv = m_pD[j].d;
               min = j;
           }
       }
       if(fabs(minv - inf) < 1e-6) break;
       m_pG->mark[min] = true;
       for(Edge e = m_pG->firstEdge(min); m_pG->isEdge(e); e = m_pG->nextEdge(e)){
           if(minv + e.weight < m_pD[e.to].d){
               m_pD[e.to].d = minv + e.weight;
               m_pD[e.to].path = min;
           }
       }
   }
   Info info;
   vector<Element> path;
   Element nElem;
   Element target_elem;
   bool transform = false;
   if(e_end.node_type != e_start.node_type)
       transform = true;
   while(e != s){
       double x1, y1;
       double x2, y2;
       getLocByNum(e, x1, y1);
       getLocByNum(m_pD[e].path, x2, y2);

       nElem = m_mapFNumToElement[e];
       if(transform){
           if(nElem.node_type == 'I'){
               target_elem = nElem;
               transform = false;
           }
       }
       path.push_back(nElem);
       e = m_pD[e].path;
   }
   nElem = m_mapFNumToElement[e];
   path.push_back(nElem);
   info.path = path;
   info.target_elem = target_elem;
   return info;
}

void PathSolve::getLocByNum(int loc_num, double &x, double &y){
    x = m_mapFNumToElement[loc_num].x;
    y = m_mapFNumToElement[loc_num].y;
}

bool PathSolve::getNumByName(string loc_name, int &loc_num){
    auto iter = m_mapFNameToElement.find(loc_name);
    if( iter != m_mapFNameToElement.end()){
        loc_num = m_mapFNameToElement[loc_name].index;
        return SUCCESS_FOUND;
    }
    return NO_EXISTED_NUM;
}

bool PathSolve::testLocationExist(string start_loc_name, string end_loc_name){

    int start_loc_num, end_loc_num;
    if(!getNumByName(start_loc_name, start_loc_num)){
        QMessageBox::information(nullptr, "Error!", "No Such Name!");
        return false;
    }

    if(!getNumByName(end_loc_name, end_loc_num)){
        QMessageBox::information(nullptr, "Error!", "No Such Name!");
        return false;
    }
    return true;
}
