#include <iostream>
#include <functional>


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
        f = [](double d) { std::cout << "c\n"; };
    }
    void rotate(double d) { f(d); };
};

class CustomShape : public Shape
{
public:
    CustomShape(VoidFunctionType& function)
    {
        f = function;
    }
    void rotate(double d) { f(d); };
};

int main()
{

    Circle circle;
    circle.rotate(2.0);
    VoidFunctionType customfunc1 = [](double d) { std::cout << "custom1\n"; };
    VoidFunctionType customfunc2 = [](double d) { std::cout << "custom2\n"; };
    CustomShape custom1{ customfunc1 };
    custom1.rotate(2.0);
    CustomShape custom2{ customfunc2 };
    custom2.rotate(2.0);

}