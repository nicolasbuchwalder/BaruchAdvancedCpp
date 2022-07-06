// Level1_Section4_Exercise1.cpp: This file contains all the code for this exercise. @Nicolas Buchwalder

#include <iostream>
#include <functional>
#include <cmath>

// PART A)

// template function wrapper for a certain type
template <typename T>
using FunctionType = std::function<T(const T& t)>;

// printing the function that is contained in the function wrapper 
template <typename T>
void print(const FunctionType<T>& f, T t)
{
    std::cout << f(t) << '\n';
};

// PART B)

// free function
double CircleArea(const double radius)
{
    return 3.14 * radius * radius;
};

// fonction object
struct PerfectRectangleArea {
    double operator() (double side)
    {
        return  1.618 * side * side;
    }

};

// stored lambda
FunctionType<double> SquareArea = [](double side) {return side * side; };


int main()
{
    // PART B)
    double t{ 1 };

    FunctionType<double> circle = CircleArea;
    FunctionType<double> perf_rectangle = PerfectRectangleArea();
    FunctionType<double> square = SquareArea;

    print(circle, t);
    print(perf_rectangle, t);
    print(square, t);
    //=> works as expected

}

