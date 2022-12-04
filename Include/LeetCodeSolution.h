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




