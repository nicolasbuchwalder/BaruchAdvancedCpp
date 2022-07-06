// Level1_Section4_Exercise4.cpp: This file contains all the code for this exercise. @Nicolas Buchwalder

#include <iostream>
#include <functional>


// function wrapper
using VoidFunctionType = std::function<void(double)>;

// given code

// Class hierarchy
class Shape
{
protected:
    VoidFunctionType f;
public:
    Shape() {};

};

class Circle : public Shape
{
public:
    Circle()
    {
        // replacement of the function (instead of virtual functions)
        f = [](double d) { std::cout << "c\n"; };
    }
    void rotate(double d) { f(d); };
};

class CustomShape : public Shape
{
public:
    CustomShape(VoidFunctionType& function)
    {
        // custom contruction of a function
        f = function;
    }
    void rotate(double d) { f(d); };
};

int main()
{

    Circle circle;
    circle.rotate(2.0);
    // => correctly overridden

    VoidFunctionType customfunc1 = [](double d) { std::cout << "custom1\n"; };
    VoidFunctionType customfunc2 = [](double d) { std::cout << "custom2\n"; };
    CustomShape custom1{ customfunc1 };
    custom1.rotate(2.0);
    // => we notice the custom function "custom1"
    CustomShape custom2{ customfunc2 };
    // => we notice the custom function "custom2"
    custom2.rotate(2.0);
    
}