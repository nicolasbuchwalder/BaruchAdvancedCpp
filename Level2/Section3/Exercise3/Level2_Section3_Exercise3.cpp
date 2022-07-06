// Level2_Section3_Exercise3.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <iostream>
#include <functional>
#include <math.h>

// GIVEN CODE

// Function maps Domain to Range
template <typename R, typename D>
using FunctionType = std::function<R(const D x)>;
// Working function type
using ScalarFunction = FunctionType<double, double>;


// PART A)


// addition of two functions
template <typename R, typename D>
FunctionType<R, D> operator+ (const FunctionType<R, D>& f, const FunctionType<R, D>& g) {
    // lambda function that adds function together
    return [=](const D& x) {
        return f(x) + g(x);
    };
}

// subtraction of two functions
template <typename R, typename D>
FunctionType<R, D> operator- (const FunctionType<R, D>& f, const FunctionType<R, D>& g) {
    // lambda function that substract function g to function f
    return [=](const D& x) {
        return f(x) - g(x);
    };
}

// multiplication of two functions
template <typename R, typename D>
FunctionType<R, D> operator* (const FunctionType<R, D>& f, const FunctionType<R, D>& g) {
    // lambda function that multiplies functions together
    return [=](const D& x) {
        return f(x) * g(x);
    };
}

// division of two functions
template <typename R, typename D>
FunctionType<R, D> operator/ (const FunctionType<R, D>& f, const FunctionType<R, D>& g) {
    // lambda function that diveds function g to function f
    return [=](const D& x) {
        return f(x) / g(x);
    };
}

// composition of two functions
template <typename R, typename D>
FunctionType<R, D> operator<< (const FunctionType<R, D>& f, const FunctionType<R, D>& g) {
    // lambda function that composes functions together (g then f)
    return [=](const D& x) {
        return f(g(x));
    };
}

// addition of a function and scalar
template <typename R, typename D>
FunctionType<R, D> operator+ (const FunctionType<R, D>& f, const R& g) {
    return [=](const D& x) {
        return f(x) + g;
    };
}

// addition of a function and scalar in inverted order
template <typename R, typename D>
FunctionType<R, D> operator+ (const R& f, const FunctionType<R, D>& g) {
    return g + f;
}

// subtraction of a function and scalar
template <typename R, typename D>
FunctionType<R, D> operator- (const FunctionType<R, D>& f, const R& g) {
    return [=](const D& x) {
        return f(x) - g;
    };
}

// substraction inverted of a function and scalar in inverted order
template <typename R, typename D>
FunctionType<R, D> operator- (const R& f, const FunctionType<R, D>& g) {
    return [=](const D& x) {
        return g - f(x);
    };
}

// multiplication of a function and scalar 
template <typename R, typename D>
FunctionType<R, D> operator* (const FunctionType<R, D>& f, const R& g) {
    return [=](const D& x) {
        return f(x) * g;
    };
}

// multiplication of a function and scalar in inverted order
template <typename R, typename D>
FunctionType<R, D> operator* (const R& f, const FunctionType<R, D>& g) {
    return g * f;
}

// division of a function and scalar 
template <typename R, typename D>
FunctionType<R, D> operator/ (const FunctionType<R, D>& f, const R& g) {
    return [=](const D& x) {
        return f(x) / g;
    };
}

// division of a function and scalar in inverted order
template <typename R, typename D>
FunctionType<R, D> operator/ (const R& f, const FunctionType<R, D>& g) {
    return [=](const D& x) {
        return g(x) / f;
    };
}


// unary addition
template <typename R, typename D>
FunctionType<R, D> operator+ (const FunctionType<R, D>& f) {
    return [=](const D& x) {
        return +f(x);
    };
}

// unary substraction
template <typename R, typename D>
FunctionType<R, D> operator- (const FunctionType<R, D>& f) {
    return [=](const D& x) {
        return -f(x);
    };
}



// PART B)

// apply exponential to function
template <typename R, typename D>
FunctionType<R, D> exp(const FunctionType<R, D>& f) {
    return [=](const D& x) {
        return std::exp(f(x));
    };
}

// apply logarithmic to function
template <typename R, typename D>
FunctionType<R, D> log(const FunctionType<R, D>& f) {
    return [=](const D& x) {
        return std::log(f(x));
    };
}

// apply power to function
template <typename R, typename D>
FunctionType<R, D> pow(const FunctionType<R, D>& f, const R& g) {
    return [=](const D& x) {
        return std::pow(f(x), g);
    };
}

// apply square root to function
template <typename R, typename D>
FunctionType<R, D> sqrt(const FunctionType<R, D>& f) {
    return [=](const D& x) {
        return std::sqrt(f(x));
    };
}

// apply absolute value to function
template <typename R, typename D>
FunctionType<R, D> abs(const FunctionType<R, D>& f) {
    return [=](const D& x) {
        return std::abs(f(x));
    };
}

// apply cosine to function
template <typename R, typename D>
FunctionType<R, D> cos(const FunctionType<R, D>& f) {
    return [=](const D& x) {
        return std::cos(f(x));
    };
}

// apply sinus to function
template <typename R, typename D>
FunctionType<R, D> sin(const FunctionType<R, D>& f) {
    return [=](const D& x) {
        return std::sin(f(x));
    };
}

// apply tangent to function
template <typename R, typename D>
FunctionType<R, D> tan(const FunctionType<R, D>& f) {
    return [=](const D& x) {
        return std::tan(f(x));
    };
}

// PART C)

// minimum of two functions at x
template <typename R, typename D>
FunctionType<R, D> min(const FunctionType<R, D>& f, const FunctionType<R, D>& g) {
    return [=](const D& x) {
        return std::min(f(x), g(x));
    };
}

// maximum of two functions at x
template <typename R, typename D>
FunctionType<R, D> max(const FunctionType<R, D>& f, const FunctionType<R, D>& g) {
    return [=](const D& x) {
        return std::max(f(x), g(x));
    };
}



int main() {
    // Scalar functions: double to double
    ScalarFunction f = [](double x) {return x * x; };
    ScalarFunction g = [=](double x) { return x; };

    std::cout << g(2) << ", " << g(8) << std::endl;

    // PART A)

    double scale = 2.0;
    // addition of 2 functions
    auto fA = 2.0 * (f + g);
    // subtraction of 2 functions
    auto fM = f - g;
    // division of 2 functions
    auto fD = f / g;
    // multiplication of 2 functions
    auto fMul = f * g;
    // composition of a function
    auto fC = g << g << 4.0 * g;
    // unary additive of 2 functions
    auto fMinus = -(f + g);

    double x = 5.0;

    std::cout << fA(x) << ", " << fM(x) << ", " << fD(x) << ", " << fMul(x) << ", compose: " << fC(x) << ", " << fMinus(x) << std::endl;

    // PART B)

    auto ftmp = log(g);
    auto ftmp2 = cos(f);
    auto f2 = (abs(exp(g)) * log(g) + sqrt(ftmp)) / ftmp2;
    std::cout << f2(x) << std::endl;

    // PART C)

    auto h1 = min(f, g);
    auto h2 = max(f, g);
    std::cout << "min(f,g): " << h1(2.0) << std::endl;
    std::cout << "max(f,g): " << h2(2.0) << std::endl;
    auto h3 = min(h1, max(2.0 * f, 3.0 * g));
    auto h4 = max(h2, max(-2.0 * f, 3.0 * g));
    std::cout << "min(min(f,g): " << h3(2.0) << std::endl;
    std::cout << "max(max(f,g): " << h4(2.0) << std::endl;
}