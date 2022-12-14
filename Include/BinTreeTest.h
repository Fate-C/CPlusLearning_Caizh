#pragma once
#include <vector>
#include "BST.h"

template <typename T>void traverIn(BinNodePosi(T) root, std::vector<T>& vec)
{
    if(root == nullptr)
    {
        return;
    }
    traverIn(root->leftChild, vec);
    vec.emplace_back(root->data);
    traverIn(root->rightChild, vec);
}



