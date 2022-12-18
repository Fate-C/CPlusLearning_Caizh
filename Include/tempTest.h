#pragma once
#include <string>
#include <iostream>

class People
{
public:
    std::string Name;
    std::string getClassName() const
    {
        return Name;
    }
};

void printClassName(const People& p)
{
    std::cout << p.getClassName() << std::endl;
}

class Student : public People
{
public:
    int studentId;
    int score;
};

