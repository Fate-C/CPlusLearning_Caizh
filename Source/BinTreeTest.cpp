
#include <iostream>
#include <vector>
#include "BST.h"


int main()
{
    std::vector<int> vec = {1, 3, 5, 6, 9, 12, 2, 4, 8, 7};

    BST<int> bst;

    for(auto num : vec)
    {
        bst.insert(num);
    }

    std::cout << bst.search(9)->data << std::endl;

    return 0;
}