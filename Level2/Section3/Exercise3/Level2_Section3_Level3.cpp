#include <iostream>
#include <functional>
#include <math.h>

// Function maps Domain to Range
template <typename R, typename D>
using FunctionType = std::function<R(const D x)>;
// Working function type
using ScalarFunction = FunctionType<double, double>;


// PART A)

//////////////////////////////////////

// with 2 functions
// addition
template <typename R, typename D>
FunctionType<R, D> operator+ (const FunctionType<R, D>& f, const FunctionType<R, D>& g) {
    // Addition of functions
    return [=] (const D& x) {
        return f(x) + g(x);
    };
}

// subtraction
template <typename R, typename D>
FunctionType<R, D> operator- (const FunctionType<R, D>& f, const FunctionType<R, D>& g) {
    return [=] (const D& x) {
        return f(x) - g(x);
    };
}

// multiplication
template <typename R, typename D>
FunctionType<R, D> operator* (const FunctionType<R, D>& f, const FunctionType<R, D>& g) {
    return [=] (const D& x) {
        return f(x) * g(x);
    };
}

// division
template <typename R, typename D>
FunctionType<R, D> operator/ (const FunctionType<R, D>& f, const FunctionType<R, D>& g) {
    return [=] (const D& x) {
        return f(x) / g(x);
    };
}

// composition
template <typename R, typename D>
FunctionType<R, D> operator<< (const FunctionType<R, D>& f, const FunctionType<R, D>& g) {
    return [=] (const D& x) {
        return f(g(x));
    };
}

//////////////////////////////////////

// function and scalar
// addition
template <typename R, typename D>
FunctionType<R, D> operator+ (const FunctionType<R, D>& f, const R& g) {
    return [=] (const D& x) {
        return f(x) + g;
    };
}

// addition inverted
template <typename R, typename D>
FunctionType<R, D> operator+ (const R& f, const FunctionType<R, D>& g) {
    return g + f;
}

// subtraction
template <typename R, typename D>
FunctionType<R, D> operator- (const FunctionType<R, D>& f, const R& g) {
    return [=] (const D& x) {
        return f(x) - g;
    };
}

// substraction inverted
template <typename R, typename D>
FunctionType<R, D> operator- (const R& f, const FunctionType<R, D>& g) {
    return [=] (const D& x) {
        return g - f(x);
    };
}

// multiplication
template <typename R, typename D>
FunctionType<R, D> operator* (const FunctionType<R, D>& f, const R& g) {
    return [=] (const D& x) {
        return f(x) * g;
    };
}

// multiplication inverted
template <typename R, typename D>
FunctionType<R, D> operator* (const R& f, const FunctionType<R, D>& g) {
    return g * f;
}

// division
template <typename R, typename D>
FunctionType<R, D> operator/ (const FunctionType<R, D>& f, const R& g) {
    return [=] (const D& x) {
        return f(x) / g;
    };
}

// division inverted
template <typename R, typename D>
FunctionType<R, D> operator/ (const R& f, const FunctionType<R, D>& g) {
    return [=] (const D& x) {
        return g(x) / f;
    };
}

//////////////////////////////////////

// other
// unary additive
template <typename R, typename D>
FunctionType<R, D> operator+ (const FunctionType<R, D>& f) {
    return [=] (const D& x) {
        return +f(x);
    };
}

// unary additive inverse
template <typename R, typename D>
FunctionType<R, D> operator- (const FunctionType<R, D>& f) {
    return [=] (const D& x) {
        return -f(x);
    };
}

//////////////////////////////////////


// PART B)

// exponential function
template <typename R, typename D>
FunctionType<R, D> exp(const FunctionType<R, D>& f) {
    return [=] (const D& x) {
        return std::exp(f(x));
    };
}

// logarithmic function
template <typename R, typename D>
FunctionType<R, D> log(const FunctionType<R, D>& f) {
    return [=] (const D& x) {
        return std::log(f(x));
    };
}

// power function
template <typename R, typename D>
FunctionType<R, D> pow(const FunctionType<R, D>& f, const R& g) {
    return [=] (const D& x) {
        return std::pow(f(x), g);
    };
}

// square root function
template <typename R, typename D>
FunctionType<R, D> sqrt(const FunctionType<R, D>& f) {
    return [=] (const D& x) {
        return std::sqrt(f(x));
    };
}

// absolute value function
template <typename R, typename D>
FunctionType<R, D> abs(const FunctionType<R, D>& f) {
    return [=] (const D& x) {
        return std::abs(f(x));
    };
}

// cosine function
template <typename R, typename D>
FunctionType<R, D> cos(const FunctionType<R, D>& f) {
    return [=] (const D& x) {
        return std::cos(f(x));
    };
}

// sinus function
template <typename R, typename D>
FunctionType<R, D> sin(const FunctionType<R, D>& f) {
    return [=] (const D& x) {
        return std::sin(f(x));
    };
}

// tangent function
template <typename R, typename D>
FunctionType<R, D> tan(const FunctionType<R, D>& f) {
    return [=] (const D& x) {
        return std::tan(f(x));
    };
}

// PART C)

// minimum function
template <typename R, typename D>
FunctionType<R, D> min(const FunctionType<R, D>& f, const FunctionType<R, D>& g) {
    return [=] (const D& x) {
        return std::min(f(x), g(x));
    };
}

// maximum function
template <typename R, typename D>
FunctionType<R, D> max(const FunctionType<R, D>& f, const FunctionType<R, D>& g) {
    return [=] (const D& x) {
        return std::max(f(x), g(x));
    };
}

int main() {
    // Scalar functions: double to double
    ScalarFunction f = [](double x) {return x*x; };
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
    auto fC = g << g << 4.0*g;
    // unary additive of 2 functions
    auto fMinus = -(f + g);

    double x = 5.0;

    std::cout << fA(x) << ", " << fM(x) << ", " << fD(x) << ", " << fMul(x) << ", compose: " << fC(x) << ", " << fMinus(x) << std::endl;

    // PART B)

    auto ftmp = log(g);
    auto ftmp2 = cos(f);
    auto f2 = (abs(exp(g))*log(g) + sqrt(ftmp)) / ftmp2;
    std::cout << f2(x)<< std::endl;

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