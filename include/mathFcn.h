#pragma once
#include <stack>
#include <vector>
#include <string>
#include <functional>
#include "priority.h"

double pow(double num, int n);
int sum(std::vector<int> &nums, int left, int right);

//函数模板，定义一个函数 add
template <typename type1, typename type2> type1 add(type1 a, type2 b)
{
    std::cout << typeid(a).name() << "\t" << typeid(b).name() << std::endl;
    return a + b;
}

std::string baseConvert(int num, int base);

double area(double radius);
double area(double length, double width);
double area(double edge1, double edge2, double edge3);

//进行多项式的运算，采用向量来记录多项式的系数
std::vector<double> polyProduct(std::vector<double> poly1, std::vector<double> poly2);
std::vector<double> multiPolyProduct(std::vector<std::vector<double>> polys);
void polyDisp(std::vector<double> poly);

//检查字符串是否括号匹配
void trim(const std::string expr, int &indexLow, int &indexHigh);
int dividePos(const std::string expr, int indexLow, int indexHigh);
bool parenMatchRecur(const std::string expr, int indexLow, int indexHigh);
bool parenMatchStack(const std::string expr, int indexLow, int indexHigh);
bool isParenMatching(const std::string expr, int indexLow, int indexHigh, char method);

//栈的应用---表达式求值算法
void readNumber(std::string::iterator &op, std::stack<double> &stk);
void append(std::string &RPN, double opnd);
void append(std::string &RPN, char optr);
int optr2rank(char op);
char orderBetween(char op1, char op2);
int facI(int num);
double calculate(double pOpnd1, char op);
double calculate(double pOpnd1, char op, double pOpnd2);
double evaluate(std::string::iterator &op, std::string &RPN);

int maximumScore(int a, int b, int c);
//测试函数指针，用lambda函数作为参数传入时，且lambda函数捕获其他变量时
void PrintVal(int val);
void ForEach(const std::vector<int>& values, void(*func)(int));
void ForEach2(const std::vector<int>& values, const std::function<void(int)>& func);
//测试多线程
namespace threadTest {
    static bool s_Finished = false;
}
void DoWork();

