// Level2_Section5-6_Exercise1.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <iostream>
#include <cmath>

// template function to classify which type of numeric value a variable is
template <typename T>
const char* Classify(T t)
{
    switch (std::fpclassify(t))
    {
    case FP_INFINITE:  return "Inf";
    case FP_NAN: return "NaN";
    case FP_NORMAL:    return "normal";
    case FP_SUBNORMAL: return "subnormal";
    case FP_ZERO: return "zero";
    default:  return "unknown";
    }
}

// template function to check type
template <typename T>
const char* checkType(T t)
{
    if (std::isfinite(t)) { return "finite"; }
    if (std::isinf(t)) { return "infinite"; }
    if (std::isnan(t)) { return "nan"; }
    if (std::isnormal(t)) { return "normal"; }
}

int main()
{

    // PART A)
    double val = std::numeric_limits<double>::max();
    std::cout << "max double is " << Classify(val) << std::endl;
    std::cout << "2 times max double is " << Classify(2.0 * val) << std::endl;
    std::cout << "pi + max double is " << Classify(3.14 + val) << std::endl;
    double val2 = std::numeric_limits<double>::min() - 3.1415;
    std::cout << "min double - pi is " << Classify(val2) << std::endl;
    std::cout << "half of (min double - pi) is " << Classify(val2 / 2.0) << std::endl;
    std::cout << "half of min double is " << Classify(DBL_MIN / 2) << std::endl;
    //=> we notice that adding or substracting seems to not have influence but multipling does


    // Part B)
    double factor = 2.0;    
    val = factor * std::numeric_limits<double>::max();
    std::cout << "2 times max double is " << checkType(val) << std::endl;
    std::cout << "2 times max double minus itself is  " << checkType(val - val) << std::endl;
    std::cout << "square root of minus 1 is " << checkType(std::sqrt(-1.0)) << std::endl;
    std::cout << "log of 0 is " << checkType(std::log(0.0)) << std::endl;
    std::cout << "exponential of 2 times max double is  " << checkType(std::exp(val)) << std::endl;
    // => everything is infinite (as it tends to infinity) except the imaginary numbers that are nan
}
