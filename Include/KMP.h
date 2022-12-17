#pragma once
#include <vector>

/*
KMP算法主要用于字符串匹配
暴力法匹配的话复杂度在 O(mn)，而采用KMP算法的话复杂度为线性O(n)
*/

std::vector<int> nextGene(const std::vector<int>& nums);
std::vector<int>::iterator KMP(std::vector<int>& nums, std::vector<int>& subVec, int k);


