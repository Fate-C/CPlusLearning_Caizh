
#include <iostream>
#include <vector>
#include "BST.h"
#include "BinTreeTest.h"


int main()
{
    std::vector<int> vec = {1, 3, 5, 6, 9, 12, 2, 4, 8, 7, 20, 40, 28};

    BST<int> bst;

    for(auto num : vec)
    {
        bst.insert(num);
    }

    std::vector<int> TraverInVec;

    traverIn(bst.getRoot(), TraverInVec);

    for(int num : TraverInVec)
    {
        printf("%d\t", num);
    }
    printf("\n");

    return 0;
}