// LevelX_SectionY_ExerciseY.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <iostream>
#include <algorithm>
#include <functional>

// GIVE CODE (in last exercise)
// Function maps Domain to Range
template <typename R, typename D>
using FunctionType = std::function<R(const D x)>;
// Working function type
using ScalarFunction = FunctionType<double, double>;

// bind to the first param "x" of f(x,y)
template <typename T>
std::function<T(const T&)> bind1st(const std::function<T(const T& x, const T& y)>& f, const T& x_) {
    return [=](const T& y_) {
        return f(x_, y_);
    };
}

// bind to the second param "y" of f(x,y)
template <typename T>
std::function<T(const T&)> bind2nd(const std::function<T(const T& x, const T& y)>& f, const T& y_) {
    return [=](const T& x_) {
        return f(x_, y_);
    };
}

int main() {
    auto fxy = [](const double x, const double y) { return x + y; };

    double yval = 10.0;
    ScalarFunction fx = bind2nd<double>(fxy, yval);
    std::cout << fx(3.0) << std::endl;
    // Test new bind code on STL algorithms
    std::vector<double> vec(10, 2.0);
    std::transform(vec.begin(), vec.end(), vec.begin(), fx);
    for (auto i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << ",";
    }
}