#pragma once
#define BinNodePosi(T) BinNode<T>*

template <typename T> struct BinNode
{
    T data;
    BinNodePosi(T) parent;
    BinNodePosi(T) leftChild;
    BinNodePosi(T) rightChild;

    BinNode(): 
        parent(nullptr), leftChild(nullptr), rightChild(nullptr) { }
    BinNode(T val, BinNodePosi(T) p = nullptr, BinNodePosi(T) lc = nullptr, BinNodePosi(T) rc = nullptr): 
        data(val), parent(p), leftChild(lc), rightChild(rc) {}
    //操作接口
    BinNodePosi(T) succ();
    BinNodePosi(T) insertAsLC(T const& val);
    BinNodePosi(T) insertAsRC(T const& val);

    template <typename VST> void traverIn(VST& visit);

    //比较器、判等器等
    bool operator< (BinNode const& bn) {return data < bn.data;}
    bool operator== (BinNode const& bn) {return data == bn.data;}
};


template <typename T> BinNodePosi(T) BinNode<T>::succ()
{
    BinNodePosi(T) currNode = this;
    if(currNode->rightChild != nullptr)
    {
        currNode = currNode->leftChild;
        while(currNode->leftChild)
        {
            currNode = currNode->leftChild;
        }
    }
    else
    {
        while(currNode->parent->leftChild != currNode)
        {
            currNode = currNode->parent;
            if(!currNode->parent)
            {
                break;
            }
        }
        currNode = currNode->parent;
    }
    return currNode;
}

template <typename T> BinNodePosi(T) BinNode<T>::insertAsLC(T const& val)
{
    return leftChild = new BinNode(val, this); //创建左节点，并将当前节点作为其父节点
}

template <typename T> BinNodePosi(T) BinNode<T>::insertAsRC(T const& val)
{
    return rightChild = new BinNode(val, this); //创建右节点，并将当前节点作为其父节点
}


