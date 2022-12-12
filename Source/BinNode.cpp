#include "BinNode.h"


template <typename T> BinNodePosi(T) BinNode<T>::insertAsLC(T const& val)
{
    return leftChild = new BinNode(val, this); //创建左节点，并将当前节点作为其父节点
}

template <typename T> BinNodePosi(T) BinNode<T>::insertAsRC(T const& val)
{
    return rightChild = new BinNode(val, this); //创建右节点，并将当前节点作为其父节点
}

