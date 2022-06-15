#include <iostream>
#include <functional>
#include <math.h>

// PART A)

template <typename T>
using FunctionType = std::function<T(const T& t)>;

template <typename T>
void print(const FunctionType<T>& f, T t)
{
    std::cout << f(t) << '\n';
};

// PART B)

// free function
double CircleArea(const double radius)
{
    return M_PI * radius * radius;
};

// fonction object
struct PerfectRectangleArea{
    double operator() (double side)
    {
        return  1.618 * side * side;
    }

};

// stored lambda
FunctionType<double> SquareArea = [](double side){return side * side;};


int main()
{
    // PART B)
    double t{1};

    FunctionType<double> circle = CircleArea;
    FunctionType<double> perf_rectangle = PerfectRectangleArea();
    FunctionType<double> square = SquareArea;

    print(circle, t);
    print(perf_rectangle, t);
    print(square, t);

    
}

