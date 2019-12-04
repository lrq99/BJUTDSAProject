#ifndef ELEMENT_H
#define ELEMENT_H
#define ROAD 1
#define CROSS 2
#define SCENIC 3
#include <string>


class Element{
public:
    int index;
    double weight;
    int x, y;
    char node_type;
    std::string node_name;
    Element() : x(0), y(0), node_type(ROAD), index(0), node_name(" "){}
    Element(int x, int y, char node_type, std::string node_name) : x(x), y(y), node_type(node_type){}

};

#endif // ELEMENT_H
