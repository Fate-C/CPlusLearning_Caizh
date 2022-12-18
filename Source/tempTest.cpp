#include <string>
#include <iostream>
#include <vector>
#include "KMP.h"
#include "tempTest.h"



int main()
{
    Entity a(1.2f, 2.4f);
    Entity b(2.4f, 4.8f);

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << a + b << std::endl;

    return 0;
}
