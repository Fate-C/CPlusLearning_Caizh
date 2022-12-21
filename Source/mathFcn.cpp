#include <string>
#include <stack>
#include <vector>
#include <cmath>
#include <typeinfo>
#include <iostream>
#include "mathFcn.h"
#include "priority.h"

//采用二分递归的方式进行求和
int sum(std::vector<int> &nums, int left, int right)
{
    if(left == right)
    {
        return nums[left];
    }
    else
    {
        int mid = (left + right) >> 1;
        return sum(nums, left, mid) + sum(nums, mid + 1, right);
    }
}

//进行乘方的计算，正常的应该改为 double 类型
double pow(double num, int n)
{
    if(n == 1)
    {
        return num;
    }
    double subPow = pow(num, n / 2);
    return n % 2 == 1? subPow * subPow * num: subPow * subPow;
}


//进行数制的转换
std::string baseConvert(int num, int base)
{
    static char digit[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    std::stack<char> sta;
    std::string ansS = "";
    while(num > 0)
    {
        int remainder = num % base;
        sta.push(digit[remainder]);
        num /= base;
    }
    while(!sta.empty())
    {
        ansS += sta.top();
        sta.pop();
    }
    return ansS;
}

//函数重载（function overloading）, 同名函数但是根据传入参数的数量和类型的不同, 系统会主动进行函数选择
double area(double radius)
{
    return 3.1415926 * radius * radius;
}
double area(double length, double width)
{
    return length * width;
}
double area(double edge1, double edge2, double edge3)
{
    double p = (edge1 + edge2 + edge3) / 2;
    return std::sqrt(p * (p - edge1) * (p - edge2) * (p - edge3));
}

//双多项式相乘
std::vector<double> polyProduct(std::vector<double> poly1, std::vector<double> poly2)
{
    int polyOrder1 = poly1.size(), polyOrder2 = poly2.size();
    std::vector<double> ansPoly(polyOrder1 + polyOrder2 - 1, 0.0);
    for(int i = 0; i < polyOrder1; i++)
    {
        for(int j = 0; j < polyOrder2; j++)
        {
            ansPoly[i + j] += poly1[i] * poly2[j];
        }
    }
    return ansPoly;
}
//多多项式相乘
std::vector<double> multiPolyProduct(std::vector<std::vector<double>> polys)
{
    std::vector<double> ansPoly = {1};
    for(auto poly : polys)
    {
        ansPoly = polyProduct(ansPoly, poly);
    }
    return ansPoly;
}
//多项式输出
void polyDisp(std::vector<double> poly)
{
    int len = poly.size();
    std::printf("Poly: ");
    for(int i = len - 1; i > 0; i--)
    {
        std::printf("%5.3fx^%d  +  ", poly[i], i);
    }
    std::printf("%5.3f\n", poly[0]);
}


//检查字符串是否括号匹配
//trim用于剪除无括号的前缀和后缀
void trim(const std::string expr, int &indexLow, int &indexHigh) 
{
    while((indexLow <= indexHigh) && (expr[indexLow] != '(') && (expr[indexLow] != ')'))
    {
        indexLow++;
    }
    while((indexLow <= indexHigh) && (expr[indexHigh] != '(') && (expr[indexHigh] != ')'))
    {
        indexHigh--;
    }
}
//dividePos用于确定分治方法中将字符串分割的位置
int dividePos(const std::string expr, int indexLow, int indexHigh)
{
    int indexMid = indexLow, diffParen = 1;
    while(diffParen > 0 && ++indexMid < indexHigh) //已经确定expr的首字符为括号，故直接跳到indexMid+1
    {
        if(expr[indexMid] == ')')
        {
            diffParen--;
        }
        if(expr[indexMid] == '(')
        {
            diffParen++;
        }
    }
    return indexMid;
}
bool parenMatchRecur(const std::string expr, int indexLow, int indexHigh)
{
    trim(expr, indexLow, indexHigh);
    if(indexLow > indexHigh)
    {
        return true;
    }
    if(expr[indexLow] != '(')
    {
        return false;
    }
    if(expr[indexHigh] != ')')
    {
        return false;
    }
    int indexMid = dividePos(expr, indexLow, indexHigh);
    if(indexMid > indexHigh)
    {
        return false;
    }
    return parenMatchRecur(expr, indexLow+1, indexMid-1) && parenMatchRecur(expr, indexMid+1, indexHigh);
}
bool parenMatchStack(const std::string expr, int indexLow, int indexHigh)
{
    std::stack<char> parenStack;
    for(int i = indexLow; i <= indexHigh; i++)
    {
        switch(expr[i])
        {
            case '(':
            case '[':
            case '{':
            {
                parenStack.push(expr[i]);
                break;
            }
            case ')':
            {
                if(parenStack.empty() || (parenStack.top() != '('))
                {
                    return false;
                }
                parenStack.pop();
                break;
            }
            case ']':
            {
                if(parenStack.empty() || (parenStack.top() != '['))
                {
                    return false;
                }
                parenStack.pop();
                break;
            }
            case '}':
            {
                if(parenStack.empty() || (parenStack.top() != '{'))
                {
                    return false;
                }
                parenStack.pop();
                break;
            }
            default: break;        
        }
        //std::cout << (parenStack.empty()? 'e' : parenStack.top()) << std::endl;
    }
    return parenStack.empty();
}
bool isParenMatching(const std::string expr, int indexLow, int indexHigh, char method)
{
    switch (method)
    {
    case 'c':
        printf("Use the recursion to varify the expression:\n");
        return parenMatchRecur(expr, indexLow, indexHigh);
        break;
    case 's':
        printf("Use the stack to varify the expression:\n");
        return parenMatchStack(expr, indexLow, indexHigh);
        break;
    default:
        printf("This method is not exist.");
        break;
    }
    return false;
}

//用来将数字压入 运算数栈
void readNumber(std::string::iterator &op, std::stack<double> &stk)
{
    stk.push((double) (*op - '0')); //将当前数字入栈
    while(isdigit(*(++op)))
    {
        double curr = stk.top();
        stk.pop();
        stk.push(curr * 10 + (*op - '0'));
    }
    if(*op == '.')
    {
        double fraction = 1;
        while(isdigit(*(++op)))
        {
            double curr = stk.top();
            stk.pop();
            stk.push(curr + (*op - '0') * (fraction /= 10));
        }
    }
}

void append(std::string &RPN, double opnd)
{
    char buff[64];
    if((int)opnd < opnd)
    {
        sprintf(buff, "%6.2f", opnd);
    }
    else
    {
        sprintf(buff, "%d", (int)opnd);
    }
    RPN += buff;
}

void append(std::string &RPN, char optr)
{
    RPN += optr;
}

int optr2rank(char op)
{
    switch (op)
    {
        case '+': return ADD;
        case '-': return SUB;
        case '*': return MUL;
        case '/': return DIV;
        case '^': return POW;
        case '!': return FAC;
        case '(': return L_P;
        case ')': return R_P;
        case '\0': return EOE;
        default: exit(-1);
    }
}

char orderBetween(char op1, char op2)
{
    return pri[optr2rank(op1)][optr2rank(op2)];
}

int facI(int num)
{
    if(num == 0)
    {
        return 1;
    }
    else
    {
        return num * facI(num - 1);
    }
}

double calculate(double pOpnd1, char op)
{
    switch (op)
    {
        case '!': return (double) facI((int) pOpnd1);
        default: exit(-1);
    }
}

double calculate(double pOpnd1, char op, double pOpnd2)
{
    switch(op)
    {
        case '+': return pOpnd1 + pOpnd2;
        case '-': return pOpnd1 - pOpnd2;
        case '*': return pOpnd1 * pOpnd2;
        case '/':
        {
            if(pOpnd2 == 0)
            {
                exit(-1);
            }
            return pOpnd1 / pOpnd2;
        }
        case '^': return pow(pOpnd1, pOpnd2);
        default: exit(-1);
    }
}

double evaluate(std::string::iterator &op, std::string &RPN)
{
    std::stack<double> opnd;
    std::stack<char> optr;
    opnd.push(2131549);
    optr.push('\0');
    while(!optr.empty())
    {
        //std::cout << opnd.top() << "\t" << optr.top() << std::endl;
        if(isdigit(*op))
        {
            readNumber(op, opnd);
            append(RPN, opnd.top());
        }
        else
        {
            switch(orderBetween(optr.top(), *op))
            {
                case '<': //当栈顶的运算符优先级更低时，计算推迟，当前运算符入栈
                {
                    optr.push(*op);
                    op++;
                    break;
                }
                case '=': //当运算符等级相等时，及 ')' 或 '/0' 时，脱括号并进入下一字符
                {
                    optr.pop();
                    op++;
                    break;
                }
                case '>': //栈顶运算符优先级更高时，进行相应计算，并将结果入栈
                {
                    char opr = optr.top();
                    optr.pop();
                    append(RPN, opr);
                    if(opr == '!')
                    {
                        double pOpnd = opnd.top();
                        opnd.pop();
                        opnd.push(calculate(pOpnd, opr));
                    }
                    else
                    {
                        double pOpnd2 = opnd.top(); opnd.pop();
                        double pOpnd1 = opnd.top(); opnd.pop();
                        opnd.push(calculate(pOpnd1, opr, pOpnd2));
                    }
                    break;
                }
                default: exit(-1);
            }
        }
    }
    return opnd.top();
}

int maximumScore(int a, int b, int c)
{
    int maxHeap = std::max(std::max(a, b), c);
    int minHeap = std::min(std::min(a, b), c);
    int midHeap = (a + b + c) - maxHeap - minHeap;
    int cntScore = 0;

    if (maxHeap >= minHeap + midHeap)
    { 
        return minHeap + midHeap;
    }
    else if (minHeap < (maxHeap >> 1))
    {
        return maxHeap;
    }
    else
    {
        cntScore += maxHeap;
        minHeap -= maxHeap >> 1;
        midHeap -= (maxHeap >> 1) + (maxHeap & 1);

        return cntScore + std::min(minHeap, midHeap);
    }
}