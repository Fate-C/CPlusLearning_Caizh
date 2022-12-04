#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "LeetCodeSolution.h"
#include "mathFcn.h"
#include "testFcns.h"
#include "nQueen.h"

int main()
{

    //testGenerateFcn(); //测试generate函数

    //testVecTraverse(); 

    //testBaseConvert(); //测试数制转换

    //testFcnOverloading(); //测试函数重载

    //testFcnTemplate(); //测试函数模板

    //testConstructionAndDestruction();
    //testClassSuccess();

    //testPolyExpand(); //测试多项式乘法

    //testParenMatch();

    //testExprCalcu();

    testNQueens();

    //testFileIO(); //测试文件IO

    //testException();

    /* //测试递归计算乘方
    int num = 0, order = 0;
    std::cout << "Input the base number:\t";
    std::cin >> num;
    std::cout << "Input the power order:\t";
    std::cin >> order;
    
    std::cout << "The result is:\t" << pow(num, order) << std::endl; */

    //leetcode题目
    /*
    std::string targetOrder = "cbaeij";
    std::string ss = "abcdajdifoaneijfl";
    Solution2Q791 solu(targetOrder, ss);
    solu.solve();
    */

    //Solution2Q799 solu(50, 15, 12);
    //solu.solve();

    return 0;
}