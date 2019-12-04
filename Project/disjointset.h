#ifndef DISJOINTSET_H
#define DISJOINTSET_H
#include <vector>
using namespace std;
typedef unsigned int uint;
class DisjointSet
{
    vector<uint> parent;
public:
    DisjointSet();
    DisjointSet(uint size){
        parent.resize(size, 0);
        for(uint i = 0; i < size; i++)
            initSet(i);
    }
    void initSet(uint x){
        parent[x] = x;
    }
    uint findParent(uint x){
        return x == parent[x] ? x :
                    parent[x] = findParent(parent[x]);
    }
    bool inSameSet(uint x, uint y){
        return findParent(x) == findParent(y);
    }
    void unionSet(uint x, uint y){
        x = findParent(x);
        y = findParent(y);
        parent[x] = y;
    }

};

#endif // DISJOINTSET_H
