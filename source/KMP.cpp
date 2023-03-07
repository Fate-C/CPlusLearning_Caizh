#include <vector>
#include "KMP.h"


std::vector<int> nextGene(const std::vector<int>& nums)
{
    int n = nums.size();
    std::vector<int> next(n, 0);
    int prefix = 0, index = 1;
    while(index < n)
    {
        if(nums[prefix] == nums[index])
        {
            prefix++;
            next[index] = prefix;
            index++;
        }
        else
        {
            if(prefix == 0)
            {
                next[index] = 0;
                index++;
            }
            else
            {
                prefix = next[prefix - 1];
            }
        }
    }
    return next;
}

std::vector<int>::iterator KMP(std::vector<int>& nums, std::vector<int>& subVec, int k)
{
    int m = subVec.size();
    std::vector<int> next = nextGene(subVec);

    for(int i = k, j = 0; i < nums.size(); i++)
    {
        while(j > 0 && nums[i] != subVec[j])
        {
            j = next[j - 1];
        }
        if(nums[i] == subVec[j])
        {
            j++;
        }
        if(j == m)
        {
            return nums.begin() + (i - m + 1);
        }
    }
    return nums.end();
}



