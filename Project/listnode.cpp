#ifndef LISTNODE_H
#define LISTNODE_H
#define ListNodePosi(T) ListNode<T>*
#include <iostream>
typedef int Rank;
template <typename T> class ListNode {
public:
//member
    T data;
    ListNodePosi(T) pred;
    ListNodePosi(T) succ;

    ListNode() :  pred(NULL) , succ(NULL){}
    ListNode(T e , ListNodePosi(T) p = NULL , ListNodePosi(T) s = NULL) : data(e) , pred(p) , succ(s) {}

    ListNodePosi(T) insertAsPred(T const& e){
        ListNodePosi(T) x = new ListNode(e, pred, this);
        this->pred->succ = x;
        this->pred = x;
        return x;
    }
    ListNodePosi(T) insertAsSucc(T const& e){
        ListNodePosi(T) x = new ListNode(e , this , succ);
        this->succ->pred = x;
        this->succ = x;
        return x;
    }
};
#endif
