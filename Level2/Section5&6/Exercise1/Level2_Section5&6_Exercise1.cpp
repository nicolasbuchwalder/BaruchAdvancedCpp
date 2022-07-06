#include <iostream>
#include <limits>
#include <cmath>
#include <cfloat>

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

template <typename T>
const char* Classify2(T t) {
    if (std::isfinite(t))
        return "finite";
    if (std::isinf(t))
        return "Inf";
    if (std::isnan(t))
        return "NaN";
    if (std::isnormal(t))
        return "normal";
    return "zero";
}

int main() {
    // PART A)    

    double val = std::numeric_limits<double>::max();
    std::cout << "'double' max limit:                        " << Classify(val) << std::endl;
    std::cout << "'double' max limit times 2:                " << Classify(2.0 * val) << std::endl;
    std::cout << "'double' max limit times 2 plus pi:        " << Classify(3.1415 + val) << std::endl;
    double val2 = std::numeric_limits<double>::min() - 3.1415;
    std::cout << "'double' min limit minus pi:               " << Classify(val2) << std::endl;
    std::cout << "'double' min limit minus pi divided by 2:  " << Classify(val2 / 2.0) << std::endl;
    std::cout << "'DBL_MIN' constant:                        " << Classify(DBL_MIN / 2) << std::endl;

    std::cout << std::endl;

    // PART B)

    double factor = 2.0;
    std::cout << "'double':                                  " << Classify2(val) << std::endl;
    val = factor * std::numeric_limits<double>::max();
    std::cout << "'double' max limit times 2:                " << Classify2(val) << std::endl;
    std::cout << "'double' max limit times 2 minus the same: " << Classify2(val - val) << std::endl;
    std::cout << "sqrt of -1:                                " << Classify2(std::sqrt(-1.0)) << std::endl;
    std::cout << "log of 0:                                  " << Classify2(std::log(0.0)) << std::endl;
    std::cout << "exp of 'double' max limit times 2:         " << Classify2(std::exp(val)) << std::endl;
}