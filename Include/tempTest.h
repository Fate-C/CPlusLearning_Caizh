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

class Entity
{
public:
    float x, y;
    
    Entity()
        : x(0.0f), y(0.0f) {}
    Entity(float x, float y)
        : x(x), y(y) {}

    Entity operator+(Entity& e) {return Entity(this->x + e.x, this->y + e.y);}
};

std::ostream& operator<<(std::ostream& stream, const Entity& e)
{
    stream << e.x << ", " << e.y;
    return stream;
}