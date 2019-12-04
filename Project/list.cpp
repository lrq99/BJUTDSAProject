#include "list.h"
/*template<typename T> void List<T>::init() {
    header = new ListNode<T>;
    trailer = new ListNode<T>;

    header->succ = trailer; header->pred = NULL;
    trailer->pred = header; trailer->succ = NULL;

    _size = 0;
}*/
template<typename T> T& List<T>::operator[](Rank r) const {
    ListNode<T> p = first();
    while (r-- > 0) {
        p = p->succ;
    }
    return p->data;
}
template<typename T> ListNodePosi(T) List<T>::find(T const&e , int n , ListNodePosi(T) p)const {
    while (n-- > 0) {
        p = p->pred;
        if (p->data == e) return p;
        else return NULL;
    }
}
template<typename T> ListNodePosi(T) List<T>::insertAsFirst(T const& e) {
    _size++;
    return header->insertAsSucc(e);

}
template<typename T> ListNodePosi(T) List<T>::insertAsLast(T const& e) {
    _size++;
    return trailer->insertAsPred(e);
}
template<typename T> ListNodePosi(T) List<T>::insertA(ListNodePosi(T) p , T const& e) {
    _size++;
    return p->insertAsSucc(e);
}
template<typename T> ListNodePosi(T) List<T>::insertB(ListNodePosi(T) p , T const& e) {
    _size++;
    return p->insertAsPred(e);
}
template<typename T> void List<T>::copyNodes(ListNodePosi(T) p , int n) {
    init();
    while (n--) {
        insertAsLast(p->data);
        p = p->succ;
    }
}
