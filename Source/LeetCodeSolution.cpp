#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
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