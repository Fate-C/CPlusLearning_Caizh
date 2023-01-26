#include <iostream>

#include <string>
#include <string_view>

#define NEW_OVERLOAD 1
#if NEW_OVERLOAD

static uint32_t s_AllocCount = 0;
void* operator new(size_t size)
{
    s_AllocCount++;
    std::cout << "Allocating: " << size << "bytes\n";
    return malloc(size);
}

#endif

#define STRING_VIEW 0
#if STRING_VIEW

void PrintName(std::string_view name)
{
    std::cout << name << std::endl;
}
#else
void PrintName(const std::string& name)
{
    std::cout << name << std::endl;
}

#endif