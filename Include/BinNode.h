#pragma once
#define BinNodePosi(T) BinNode<T>*

template <typename T> struct BinNode
{
    T data;
    BinNodePosi(T) parent;
    BinNodePosi(T) leftChild, rightChild;

    BinNode(): 
        parent(NULL), leftChild(NULL), rightChild(NULL) { }
    BinNode(T val, BinNodePosi(T) p = nullptr, BinNodePosi(T) lc = nullptr, BinNodePosi(T) rc = nullptr): 
        data(val), parent(p), leftChild(lc), rightChild(rc) {}
    //操作接口
    BinNodePosi(T) insertAsLC(T const& val);
    BinNodePosi(T) insertAsRC(T const& val);

    //比较器、判等器等
    bool operator< (BinNode const& bn) {return data < bn.data};
    bool operator== (BinNode const& bn) {return data == bn.data};
};
