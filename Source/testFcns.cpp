#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "mathFcn.h"
#include "KMP.h"
#include "BST.h"
#include "tempTest.h"
#include "testFcns.h"
#include "LeetCodeSolution.h"

//the practice is used for test the function std::generate()
void testGenerateFcn()
{
    std::vector<int> nums(100, 0);
    int interCh = 0;
    // 采用外部引用的方法
    // std::generate(nums.begin(), nums.end(), [&interCh](){
    //     return ++interCh;
    // });

    // 采用静态变量的方法
    std::generate(nums.begin(), nums.end(), [](){
        static int i = 0;
        return ++i;
    });

    int cnt = 0;
    for(int num : nums)
    {
        std::cout << num << "\t";
        cnt++;
        if(cnt % 10 == 0)
        {
            std::cout << std::endl;
        }
    }
    std::cout << sum(nums, 0, nums.size() - 1) << std::endl;
}


void testVecTraverse()
{
    std::vector<int> nums(20, 0);
    std::generate(nums.begin(), nums.end(), [](){
        static int i = 0;
        i += 2;
        return i / 8;
    });

    for(int num : nums)
    {
        std::cout << num << "\t";
    }
    std::cout << std::endl;

}

void testFcnOverloading()
{
    std::cout << area(10.0) << std::endl;
    std::cout << area(10.0, 30.0) << std::endl;
    std::cout << area(3.0, 4.0, 5.0) << std::endl;
}


void testBaseConvert()
{
    int num, base;
    std::cout << "Pleas input the number: " ;
    std::cin >> num;
    std::cout << "Please input the base ( base <=16 ): " ;
    std::cin >> base;

    std::cout << "The result is: " << baseConvert(num, base) << std::endl;
}

//used to test the function template
void testFcnTemplate()
{
    std::cout << add(2, 5) << std::endl;
    std::cout << add(2.658, 5.74) << std::endl;
    std::cout << add('A', 5) << std::endl;
}

//test the construct function and destruct function of class
void testConstructionAndDestruction()
{
    Student stu1(2131549, "CaiZhen", 90);
    Student stu2(1652136, "Caizh", 95);
    Student stu3(stu1);
    std::cout << std::endl;
    Tool T;
    T.getCardId(stu1);
    T.getName(stu1);
    T.getScore(stu1);
    getInfo(stu2);
}

void testClassSuccess()
{
    ForeignStudent fstu1(2131549, "CaiZhen", 90, "China");
    fstu1.printInfo();
    std::cout << std::endl;
    fstu1.printInfor();
}

void testPolyExpand()
{
    std::vector<double> ansPoly;
    std::vector<std::vector<double>> polys = {{1.3, 1}, {2.3, 1}, {3.3, 1}, {4.3, 1}};
    for(auto poly : polys)
    {
        polyDisp(poly);
    }

    ansPoly = multiPolyProduct(polys);
    polyDisp(ansPoly);
}

void testFileIO()
{
    //std::ofstream::app采用此方法打开文件不会截断清除掉原有数据
    std::ofstream outFile("testFileIO.txt", std::ofstream::app);

    outFile << "use the ofstream to write message into file\n";
    outFile << "This is a new line\n";
    outFile << "This is a new file";

    outFile.close();

    std::ifstream inFile("testFileIO.txt", std::ofstream::in);

    std::string line;
    while(getline(inFile, line))
    {
        std::cout << line << std::endl;
    }

    inFile.close();
}

void testException()
{
    int dividend = 0, divisor = 1;
    std::cout << "Input The Dividend: " << std::endl;
    std::cin >> dividend;
    std::cout << "Input The Divisor: " << std::endl;
    std::cin >> divisor;

    try
    {
        if(divisor == 0)
        {
            throw "Error: The Divisor Equal to Zero.";
        }
    }
    catch(const char* str)
    {
        std::cout << str << std::endl;
    }
    catch(int)
    {
        std::cout << "Int" << std::endl;
    }

    std::cout << "The divid result is: " << (double)dividend / (double)divisor << std::endl;

}

void testParenMatch()
{
    std::vector<std::string> objSentence = {"(1+5)+[155*(5+x2)]", "(15+96(85(86)(4+9))"};

    for(std::string ss : objSentence)
    {
        std::cout << (isParenMatching(ss, 0, ss.size() - 1, 'c')? "true" : "false") << std::endl;
        std::cout << (isParenMatching(ss, 0, ss.size() - 1, 's')? "true" : "false") << std::endl;
    }
}

void testExprCalcu()
{
    std::string expr = "(4+6)*10+(5!+12.2)/4";
    std::string RPN = "\0";
    std::string::iterator exprIter = expr.begin();
    double val = evaluate(exprIter, RPN);

    printf("The expression result is: \t%6.2f\n", val);
    printf("The RPN expression is:\t%s\n", RPN.c_str());
}

void testOperatorOverloading()
{
    Entity a(1.2f, 2.4f);
    Entity b(2.4f, 4.8f);

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << a + b << std::endl;
}

void testKMP()
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

}