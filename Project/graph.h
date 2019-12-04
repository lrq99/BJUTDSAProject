#ifndef GRAPH_H
#define GRAPH_H
#include "edge.h"
#include "element.h"
#include "constant.h"
#include "list.h"
#include "dist.h"
class Graph
{
public:
    List<Element> *graList;
    int vertex_num;
    int edge_num;
    bool *mark;
    int *indegree;
    Graph(int vertex_num);
    int vertexNum(){return vertex_num;}
    bool isEdge(Edge oneEdge);
    Edge firstEdge(int one_vertex);
    Edge nextEdge(Edge preEdge);
    void setEdge(int from, int to, double weight);
    void resetGraph();
};

#endif // GRAPH_H
