#ifndef LIST_H
#define LIST_H

#include "listnode.h"
template<typename T>
class List {
private:
    int _size;
public:
    ListNodePosi(T) header;
    ListNodePosi(T) trailer;
protected:

    T& operator[](Rank r)const;
public:
    void init(){
        header = new ListNode<T>;
        trailer = new ListNode<T>;

        header->succ = trailer; header->pred = NULL;
        trailer->pred = header; trailer->succ = NULL;

        _size = 0;
    }
    List(){init();}

    int size(){return _size;}
    ListNodePosi(T) first() { return header->succ; }
    ListNodePosi(T) last() { return trailer->pred; }
    ListNodePosi(T) find(T const& e , int n , ListNodePosi(T) p) const;
    ListNodePosi(T) insertAsFirst(T const& e);
    ListNodePosi(T) insertAsLast(T const& e);
    ListNodePosi(T) insertA(ListNodePosi(T) p , T const& e);
    ListNodePosi(T) insertB(ListNodePosi(T) p , T const& e);
    void copyNodes(ListNodePosi(T) p , int n);
};

#endif // !LIST_H






