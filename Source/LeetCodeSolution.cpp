#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include "mathFcn.h"
#include "LeetCodeSolution.h"

Solution2Q791::Solution2Q791(std::string order, std::string s)
{
    this->order = order;
    this->s = s;
};

std::string Solution2Q791::customSortString(std::string order, std::string s)
{
    int weightVal[26] = {0};
    for(int i = 0; i < order.size(); i++)
    {
        weightVal[order[i] - 'a'] = i + 1;
    }
    std::sort(s.begin(), s.end(), [&](int ch1, int ch2){
        return weightVal[ch1 - 'a'] < weightVal[ch2 - 'a'];
    });
    return s;
};

void Solution2Q791::solve()
{
    std::string ansS = customSortString(order, s);
    std::cout << ansS << std::endl;
};

Solution2Q799::Solution2Q799(int poured, int query_row, int query_glass)
{
    this->poured = poured;
    this->query_row = query_row;
    this->query_glass = query_glass;
}

double Solution2Q799::champagneTower()
{
    std::vector<double> currRow = {double(poured)};
    for(int i = 1; i <= query_row; i++)
    {
        std::vector<double> nextRow(i + 1, 0.0);
        for(int k = 0; k < currRow.size(); k++)
        {
            if(currRow[k] > 1)
            {
                nextRow[k] += (currRow[k] - 1) / 2;
                nextRow[k + 1] += (currRow[k] - 1) / 2;
            }
            std::printf("%5.4f\t", (currRow[k] > 1? 1.0 : currRow[k]));
            //std::cout << (currRow[k] > 1? 1.0 : currRow[k]) << "\t";
        }
        std::printf("\n");
        //t << std::endl;
        currRow = nextRow;
    }
    return std::min(1.0, currRow[query_glass]);
}

void Solution2Q799::solve()
{
    double ans;
    ans = champagneTower();
}


void Solution2Q207::dfs(int courseNum)
{
    courseStatus[courseNum] = DISCOVERED; //开始访问当前节点
    for(int nextCourse : edges[courseNum]) //对每一个边进行探寻
    {
        if(courseStatus[nextCourse] == UNDISCOVERED)
        {
            dfs(nextCourse);
            if(!valid)
            {
                return;
            }
        }
        else if(courseStatus[nextCourse] == DISCOVERED) //如果下一访问节点已经处于访问中状态，则说明形成环
        {
            valid = false;
            return;
        }
    }
    courseStatus[courseNum] = VISITED; //当前节点已结束访问
}

bool Solution2Q207::canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
    edges.resize(numCourses);
    courseStatus.resize(numCourses, UNDISCOVERED);

    for(const auto& prereq : prerequisites)
    {
        edges[prereq[0]].emplace_back(prereq[1]);
    }
    for(int i = 0; i < numCourses; i++)
    {
        if(courseStatus[i] == UNDISCOVERED)
        {
            dfs(i);
        }
    }
    return valid;
}

void Solution2Q207::solve()
{
    int numCourses = 2;
    std::vector<std::vector<int>> prerequisites = {{1,0},{0,1}};
    bool valid = canFinish(numCourses, prerequisites);
    std::string ans = valid? "true" : "false";
    std::cout << ans << std::endl;
}

//构造函数
Student::Student(int cardId, std::string name, int score)
{
    this->cardId = cardId;
    this->name = name;
    this->score = score;
    std::cout << "Object Constructed:\t";
    printInfo();
}
//拷贝构造函数
Student::Student(Student &stud)
{
    this->cardId = stud.cardId;
    this->name = stud.name;
    this->score = stud.score;
    std::cout << "Object Copy Constructed:\t";
    printInfo();
}
//析构函数
Student::~Student()
{
    std::cout << "Object Destructed:\t";
    printInfo();
}
//成员函数
void Student::printInfo()
{
    std::cout << "Id:" << cardId;
    std::cout << "\tName:" << name;
    std::cout << "\tScore:" << score << std::endl;
}
void Student::getInformation(int &cardId, std::string &name, int &score)
{
    cardId = this->cardId;
    name = this->name;
    score = this->score;
}
//友元函数
void getInfo(Student &stud)
{
    int id, score;
    std::string name;
    id = stud.cardId;
    name = stud.name;
    score = stud.score;
    std::cout << "The Student's Information:\t";
    std::cout << "Id:" << id;
    std::cout << "\tName:" << name;
    std::cout << "\tScore:" << score << std::endl;
}
//友元类的成员函数
void Tool::getCardId(Student &stud)
{
    std::cout << "The Student's Card Id is:" << stud.cardId << std::endl;
}
void Tool::getName(Student &stud)
{
    std::cout << "The Student's Name is:" << stud.name << std::endl;
}
void Tool::getScore(Student &stud)
{
    std::cout << "The Student's Score is:" << stud.score << std::endl;
}

//类的继承与派生
//派生类的构造函数
ForeignStudent::ForeignStudent(int cardId, std::string name, int score, std::string nation) : Student(cardId, name, score)
{
    this->nation = nation;
}
//派生类的成员函数，通过基类的成员函数来访问基类的private成员
//因为派生类的成员函数无法去访问基类里面的private成员，只能通过基类的成员函数进行访问
void ForeignStudent::printInfor()
{
    int cardId, score;
    std::string name;
    getInformation(cardId, name, score);
    std::cout << "Id:" << cardId;
    std::cout << "\tName:" << name;
    std::cout << "\tScore:" << score;
    std::cout << "\tNation:" << nation << std::endl;
}

void testLeetCode()
{
    int a = 4;
    int b = 4;
    int c = 7;

    int ans = maximumScore(a, b, c);
}

/*
******************************************************************************
******************************************************************************
******************************************************************************
*/

Solution2Q855::Solution2Q855(int n) : n(n) {}

int Solution2Q855::seat()
{
    if (seats.empty())
    {
        seats.insert(0);
        return 0;
    }
    int left = *seats.begin(), right = n - 1 - *seats.rbegin();
    while (seats.size() >= 2)
    {
        auto p = pq.top();
        if (seats.count(p.first) > 0 && seats.count(p.second) > 0 &&
            *next(seats.find(p.first)) == p.second)
        {
            int dis = p.second - p.first;
            if (dis / 2 < right || dis / 2 <= left)
            {
                break;
            }
            pq.pop();
            int nextSeat = p.first + dis / 2;
            pq.push({p.first, nextSeat});
            pq.push({nextSeat, p.second});
            seats.insert(nextSeat);
            return nextSeat;
        }
        pq.pop();
    }
    if(right > left)
    {
        pq.push({*seats.rbegin(), n - 1});
        seats.insert(n - 1);
        return n - 1;
    }
    else
    {
        pq.push({0, *seats.begin()});
        seats.insert(0);
        return 0;
    }
}

void Solution2Q855::leave(int p)
{
    if(p != *seats.begin() && p != *seats.rbegin())
    {
        auto it = seats.find(p);
        pq.push({*prev(it), *next(it)});
    }
    seats.erase(p);
}

void Solution2Q855::disp()
{
    for(int i = 0; i < n; i++)
    {
        std::cout << (seats.count(i)? std::to_string(i) : "*") << "\t";
    }
    std::cout << std::endl;
}

void soluQ855Test()
{
    Solution2Q855 solu(20);
    char choice = 0;
    while(1)
    {
        std::cout << "Please choose your operation(1 -> seat or 2 -> leave): ";
        std::cin >> choice;
        switch (choice)
        {
            case '1':
            {
                solu.seat();
                solu.disp();
                break;
            }
            case '2':
            {
                int num = 0;
                std::cout << "Input the leave num: ";
                std::cin >> num;
                solu.leave(num);
                solu.disp();
                break;
            }
            case '3':
            {
                solu.disp();
                break;
            }
            default:
                break;
        }
    }
}

int Solution2Q1801::getNumberOfBacklogOrders(std::vector<std::vector<int>>& orders) {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, 
        std::greater<std::pair<int, int>>> sellOrders;  //积压的销售订单，价格低的在前
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, 
        std::less<std::pair<int, int>>> buyOrders;   //积压的采购订单，价格高的在前

    for(auto& order : orders)
    {
        if(order[2] == 0)   //采购订单
        {
            while((!sellOrders.empty()) && order[0] >= sellOrders.top().first && order[1] > 0)
            {
                std::pair<int, int> currOrder = sellOrders.top();
                sellOrders.pop();
                int offset = std::min(currOrder.second, order[1]);
                currOrder.second -= offset;
                order[1] -= offset;
                if(currOrder.second > 0)
                {
                    sellOrders.push(currOrder);
                }
            }
            if(order[1] > 0)
            {
                buyOrders.push({order[0], order[1]});
            }
        }
        else
        {
            while((!buyOrders.empty()) && order[0] <= buyOrders.top().first && order[1] > 0)
            {
                std::pair<int, int> currOrder = buyOrders.top();
                buyOrders.pop();
                int offset = std::min(currOrder.second, order[1]);
                currOrder.second -= offset;
                order[1] -= offset;
                if(currOrder.second > 0)
                {
                    buyOrders.push(currOrder);
                }
            }
            if(order[1] > 0)
            {
                sellOrders.push({order[0], order[1]});
            }
        }
    }
    long long cntOrders = 0;
    while(!sellOrders.empty())
    {
        auto order = sellOrders.top();
        sellOrders.pop();
        cntOrders += order.second;
    }
    while(!buyOrders.empty())
    {
        auto order = buyOrders.top();
        buyOrders.pop();
        cntOrders += order.second;
    }
    return cntOrders % MOD;
}

void Solution2Q1801::solve()
{
        std::vector<std::vector<int>> orders = {{26,7,0},{16,1,1},{14,20,0},{23,15,1},{24,26,0},{19,4,1}, {1,1,0}};

    int ans = getNumberOfBacklogOrders(orders);

    std::cout << ans << std::endl;
}