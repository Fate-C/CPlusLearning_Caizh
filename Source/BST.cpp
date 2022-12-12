#include "BST.h"

template <typename T> static BinNodePosi(T) & searchIn(BinNodePosi(T)& v, const T& val, BinNodePosi(T)& hot)
{
    if(!v || (v->data == val))
    {
        return v;
    }
    hot = v;
    return searchIn(((val < v->data)? v->leftChild : v->rightChild), val, hot);
}

template <typename T> BinNodePosi(T) & BST<T>::search(const T& val)
{
    return searchIn(_root, val, _hot = nullptr);
}

template <typename T> BinNodePosi(T) BST<T>::insert(const T& val)
{
    BinNodePosi(T)& obj = search(val);
    if(obj) return obj;
    obj = new BinNode<T>(val, _hot);
    _size++;
    return obj;
}

