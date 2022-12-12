#pragma once
#include "BinNode.h"

template<typename T> class BinTree
{
protected:
    int _size;
    BinNodePosi(T) _root;

public:
    BinTree(): _size(0), _root(nullptr) {}
};


