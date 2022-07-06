// Level1_Section3_Exercise2.cpp: This file contains all the code for this exercise. @Nicolas Buchwalder

#include <iostream>
#include <array>

// given code
class Shape
{
public:
    virtual void rotate(double d) = 0;
};

class Circle : public Shape
{
public:
    void rotate(double d) override { std::cout << "c\n"; }
};

class Line : public Shape
{
public:
    void rotate(double d) override { std::cout << "l\n"; }
};

class Valve
{
public:
    void rotate(double d) { std::cout << "v\n"; }
};


// PART A)
// tail function
void rotate(double factor) {};

// variadic recursive function
template< class C, class... Cs>
void rotate(double factor, C class1, Cs... otherclasses)
{
    class1.rotate(factor);
    rotate(factor, otherclasses...);
};

int main()
{
    Circle circle;
    Line line;
    Valve valve;

    double factor = 2.0;

    // We can in essence create compile-time aggregates/whole
    // part objects on the fly. We only need to write one function.

    rotate(factor, circle);
    rotate(factor, circle, line);
    rotate(factor, circle, valve);
    rotate(factor * 2, circle, valve, line);

    // PART B)

    // The other way of doing it.
    std::array<Shape*, 5> shapeList{ &circle, &line, &circle, &circle, &line };
    double factor2 = 20.0;
    for (auto& elem : shapeList)
    {
        elem->rotate(factor2);
    }

    // => we cannot put valve in the list as the array is a Shape array, from which circle and line are derived from, but not valve
    // => in variadic approach, the type can be anything, so the class can change
}