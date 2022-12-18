#include <string>
#include <iostream>
#include <vector>
#include "KMP.h"
#include "tempTest.h"



int main()
{
    std::vector<int> nums = {1, 2, 1, 3, 1, 2, 1, 2};

    std::vector<int> subVec = {3, 1, 2};

    auto it = KMP(nums, subVec, 0);

    std::cout << it - nums.begin() << std::endl;

    return 0;
}
