#include "graph.h"
#include "listnode.h"

Graph::Graph(int vertex_num)
{
    this->vertex_num = vertex_num;
    this->edge_num = 0;
    indegree = new int[vertex_num];
    mark = new bool[vertex_num];
    for(int i = 0; i < vertex_num; i++){
        mark[i] = false;
        indegree[i] = 0;
    }

    graList = new List<Element>[vertex_num]();
}
bool Graph::isEdge(Edge oneEdge){
    return oneEdge.weight > 0
            && oneEdge.weight < inf
            && oneEdge.to > 0;

}
Edge Graph::firstEdge(int one_vertex){
    Edge myEdge;
    myEdge.from = one_vertex;
    ListNodePosi(Element) temp = graList[one_vertex].header;
    ListNodePosi(Element) trailer = graList[one_vertex].trailer;
    if(temp->succ != trailer){
        Element elem = temp->succ->data;
        myEdge.to = elem.index;
        myEdge.weight = elem.weight;
    }
    return myEdge;
}

Edge Graph::nextEdge(Edge preEdge){
    Edge myEdge;
    myEdge.from = preEdge.from;
    ListNodePosi(Element) temp = graList[preEdge.from].header;
    ListNodePosi(Element) trailer = graList[preEdge.from].trailer;
    while(temp->succ != trailer && temp->succ->data.index <= preEdge.to){
        temp = temp->succ;
    }
    if(temp->succ != trailer){
        myEdge.to = temp->succ->data.index;
        myEdge.weight = temp->succ->data.weight;
    }
    return myEdge;
}

void Graph::setEdge(int from, int to, double weight){
    ListNodePosi(Element) temp = graList[from].header;
    ListNodePosi(Element) trailer = graList[from].trailer;
    while(temp->succ != trailer && temp->succ->data.index < to){
        temp = temp->succ;
    }
    if(temp->succ == graList[from].trailer){//cannot find pred node
        Element ins;
        ins.index = to;
        ins.weight = weight;
        temp->succ->insertAsPred(ins);
        edge_num++;
        indegree[to]++;
        return;
    }
    if(temp->succ->data.index == to){
        temp->succ->data.weight = weight;
        return;
    }
    if(temp->succ->data.index > to){
        Element ins;
        ins.index = to;
        ins.weight = weight;
        temp->succ->insertAsPred(ins);
        edge_num++;
        indegree[to]++;
        return;
    }

}
