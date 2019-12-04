#ifndef PATHSOLVE_H
#define PATHSOLVE_H
#include <QMessageBox>
#include <string>
#include "graph.h"
#include <map>
#include <vector>
#include "dist.h"
using namespace std;

struct Node{
    int vertex;
    int f;
    int g;
    Node* parent;
    Node(int f, int g, int vertex, Node *parent) : vertex(vertex), f(f), g(g), parent(parent) {}
    Node() : vertex(0), f(0), g(0), parent(NULL) {}
    bool operator < (const Node *& rhs) const{
        return f > rhs->f;
    }
};

struct cmp{
    bool operator()(Node *&a, Node *&b) const{
        return a->f > b->f;
    }
};

struct Info{
    vector<Element> path;
    Element target_elem;
};

class PathSolve
{
public:
    Graph *m_pG;
    Dist *m_pD;
    map<int, Element> m_mapFNumToElement;
    map<string, Element> m_mapFNameToElement;

    PathSolve(Graph *m_pG, Dist *m_pD, map<int, Element> m_mapFNumToElement, map<string, Element> m_mapfNameToElement);
    Info dijkstra(int s, int e);
    vector<Element> kShortestPath(int, int, int k);
    void getLocByNum(int loc_num, double &x, double &y);
    bool getNumByName(string loc_name, int &loc_num);
    bool testLocationExist(string start_loc_name, string end_loc_name);
private:
    void addToPath(vector<Element> &, Node *);
};

#endif // PATHSOLVE_H
