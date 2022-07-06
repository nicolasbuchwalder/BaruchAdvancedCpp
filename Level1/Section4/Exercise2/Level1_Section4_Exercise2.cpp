// Level1_Section4_Exercise2.cpp: This file contains all the code for this exercise. @Nicolas Buchwalder

#include <iostream>
#include <functional>

// given code

double freeFunction3(double x, double y, double z)
{
    return x + y + z;
}

// PART A)

double freeFunction2(double x, double y)
{
    return x + y + 3; // z=3
}

double freeFunction1(double x)
{
    return x + 2 + 3; // y=2, z=3
}

double freeFunction0()
{
    return 1 + 2 + 3; // x=1, y=2, z=3
}

int main()
{
    // bind last argument to 3 => arity 2
    auto f2 = std::bind(freeFunction3, std::placeholders::_1, std::placeholders::_2, 3);
    // bind second arguement to 2 and third to 3 => arity 1
    auto f1 = std::bind(freeFunction3, std::placeholders::_1, 2, 3);
    // bind all arguments to resp. 1,2,3 => arity 0
    auto f0 = std::bind(freeFunction3, 1, 2, 3);

    std::cout << "Arity 2:\t define func: " << freeFunction2(10, 7) << "\tbinded func: " << f2(10, 7) << std::endl;
    std::cout << "Arity 1:\t define func: " << freeFunction1(5) << "\tbinded func: " << f1(5) << std::endl;
    std::cout << "Arity 0:\t define func: " << freeFunction0() << " \tbinded func: " << f0() << std::endl;
    // => they are identical, binding works
}