#pragma once
#include "BinTree.h"

template <typename T> static BinNodePosi(T) & searchIn(BinNodePosi(T)& v, const T& val, BinNodePosi(T)& hot);
template <typename T> static BinNodePosi(T) removeAt(BinNodePosi(T)& x, BinNodePosi(T)& hot);

template <typename T> class BST : public BinTree<T>
{
protected:
    BinNodePosi(T) _hot; //命中节点的父亲
public:
    BST();
    ~BST();
    BinNodePosi(T) getRoot();
    BinNodePosi(T)& search(const T& val);
    BinNodePosi(T)& insert(const T& val);
    bool remove(const T& val);
};

template <typename T> static BinNodePosi(T) & searchIn(BinNodePosi(T)& v, const T& val, BinNodePosi(T)& hot)
{
    if(!v || (v->data == val))
    {
        return v;
    }
    hot = v;
    return searchIn(((val < v->data)? v->leftChild : v->rightChild), val, hot);
}

template <typename T> static BinNodePosi(T) removeAt(BinNodePosi(T)& x, BinNodePosi(T)& hot)
{
    BinNodePosi(T) w = x;
    BinNodePosi(T) succ = nullptr;
    if(x->leftChild == nullptr) //如果左孩子为空，则直接用右儿子接上
    {
        succ = x = x->rightChild;
    }
    else if(x->rightChild == nullptr)
    {
        succ = x = x->leftChild;
    }
    else
    {
        w = w->succ();
        swap(x->data, w->data);
        BinNodePosi(T) u = w->parent;
        ((u == x)? u->rightChild : u->leftChild) = succ = w->rightChild;
    }
    hot = w->parent;
    if(succ)
    {
        succ->parent = hot;
    }
    release(w->data);
    release(w);
    return succ;
}

template <typename T> BST<T>::BST()
{
    std::cout << "BST Created!" << std::endl;
}

template <typename T> BST<T>::~BST()
{
    std::cout << "BST Deleted!" << std::endl;
}

template <typename T> BinNodePosi(T) BST<T>::getRoot()
{
    return this->_root;
}

template <typename T> BinNodePosi(T)& BST<T>::search(const T& val)
{
    return searchIn(this->_root, val, _hot = nullptr);
}

template <typename T> BinNodePosi(T)& BST<T>::insert(const T& val)
{
    BinNodePosi(T)& obj = search(val);
    if(obj) return obj;
    obj = new BinNode<T>(val, _hot);
    this->_size++;
    return obj;
}

template <typename T> bool BST<T>::remove(const T& val)
{
    BinNodePosi(T)& x = search(val);
    if(!x)
    {
        return false;
    }
    removeAt(x, _hot);
    this->_size--;
    return true;
}




