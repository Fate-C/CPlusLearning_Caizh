#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

void rever(std::vector<int>& A, int left, int right)
{
    if(left < right)
    {
        std::swap(A[left], A[right]);
        rever(A, left + 1, right - 1);
    }
}

int main()
{
    //std::vector<int> A = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> A;
    std::string getInt;
    while(std::cin >> getInt)
    {
        //如果判断是否为换行符的语句在 emplace_back 前面的话，
        //会导致最后一个数字没有被置入A中就退出了while循环
        A.emplace_back(std::stoi(getInt));
        if(std::cin.get() == '\n')
        {
            break;
        }
    }

    rever(A, 0, A.size() - 1);

    for(int a : A)
    {
        std::cout << a << "\t";
    }
    std::cout << std::endl;
    return 0;
}

