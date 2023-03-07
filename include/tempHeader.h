#include <iostream>

#include <string>
#include <cstring>
#include <string_view>

namespace Move{

class String
{
public:
    String() = default;

    String(const char* str)
    {
        printf("Created!\n");
        m_Size = strlen(str);
        m_Data = new char[m_Size];
        memcpy(m_Data, str, m_Size);
    }

    String(const String& other)
    {
        printf("Copied!\n");
        m_Size = other.m_Size;
        m_Data = new char[m_Size];
        memcpy(m_Data, other.m_Data, m_Size);
    }

    String(String&& other) noexcept
    {
        printf("Moved!\n");
        m_Size = other.m_Size;
        m_Data = other.m_Data;

        other.m_Data = nullptr;
        other.m_Size = 0;
    }

    ~String()
    {
        printf("Destroyed!\n");
        delete m_Data;
    }

    String& operator=(const String& other)
    {
        printf("Copy Assigned\n");
        m_Size = other.m_Size;
        m_Data = new char[m_Size];
        memcpy(m_Data, other.m_Data, m_Size);
        return *this;
    }

    String& operator=(String&& other)
    {
        if(this != &other)
        {
            printf("Assigned\n");
            delete[] m_Data;
            m_Size = other.m_Size;
            m_Data = other.m_Data;

            other.m_Data = nullptr;
            other.m_Size = 0;
        }
        return *this;
    }

    void Print()
    {
        for(uint32_t i = 0; i < m_Size; i++)
        {
            printf("%c", m_Data[i]);
        }
        printf("\n");
    }

private:
    char* m_Data = nullptr;
    uint32_t m_Size = 0;

};

class Entity
{
public:
    Entity(const String& name) : m_Name(name) {}
    
    // Entity(String&& name) : m_Name(name) {};
    // Entity(String&& name) : m_Name((String&&) name) {};
    Entity(String&& name) : m_Name(std::move(name)) {};

    void PrintName()
    {
        m_Name.Print();
    }
private:
    String m_Name;
};

}