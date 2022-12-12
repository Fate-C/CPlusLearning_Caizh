#pragma once
#include "BinTree.h"


template <typename T> class BST : public BinTree<T>
{
protected:
    BinNodePosi(T) _hot; //命中节点的父亲
public:
    virtual BinNodePosi(T) & search(const T& val);
    virtual BinNodePosi(T) insert(const T& val);
    virtual bool remove(const T& val);
};

template <typename T> static BinNodePosi(T) & searchIn(BinNodePosi(T)& v, const T& val, BinNodePosi(T)& hot);