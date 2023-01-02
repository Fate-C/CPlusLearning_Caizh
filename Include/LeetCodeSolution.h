#pragma once

#include <string>


class Solution2Q791
{
public:
    Solution2Q791(std::string order, std::string s);
    std::string customSortString(std::string order, std::string s);
    void solve();
private:
    std::string order, s;
};

class Solution2Q799 //香槟塔
{
public:
    Solution2Q799(int poured, int query_row, int query_glass);
    double champagneTower();
    void solve();
private:
    int poured, query_row, query_glass;
};


typedef enum {UNDISCOVERED, DISCOVERED, VISITED} status; //在图中，每一门课有三个状态，未被访问、访问中、访问完

class Solution2Q207
{
public:
    void dfs(int courseNum);
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites);
    void solve();
private:
    std::vector<std::vector<int>> edges;
    std::vector<status> courseStatus;
    bool valid = true;
};

class Student
{
public:
    Student(int cardId, std::string name, int score);
    Student(Student &stud);
    ~Student();
    void printInfo();
    void getInformation(int &cardId, std::string &name, int &score);
    friend class Tool; //友元类
    friend void getInfo(Student &stud); //友元函数
private:
    int cardId;
    std::string name;
    int score;
};

void getInfo(Student &stud); //声明友元函数

class Tool //声明友元类
{
public:
    void getCardId(Student &stud);
    void getName(Student &stud);
    void getScore(Student &stud);
};

class ForeignStudent : public Student
{
public:
    ForeignStudent(int cardId, std::string name, int score, std::string nation);
    void printInfor();
private:
    std::string nation;
};


void testLeetCode();

class Solution2Q1801 {
public:
    int getNumberOfBacklogOrders(std::vector<std::vector<int>>& orders);
    void solve();
private:
    int MOD = 1e9 + 7;
};