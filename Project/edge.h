#ifndef EDGE_H
#define EDGE_H


class Edge
{
public:
    int from, to;
    double weight;
    Edge() : from(-1), to(-1), weight(0){}
    Edge(int from, int to, int weight): from(from), to(to), weight(weight){}

};

#endif // EDGE_H
