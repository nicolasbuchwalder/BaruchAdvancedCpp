#include <iostream>
#include <cmath>
#include <boost/math/special_functions/next.hpp>

int main() {
    // Number gaps/bits/ULP between
    // 2 floating-point values a and b
    // Returns a signed value indicating whether a < b
    double a = 0.1;
    double b = a + std::numeric_limits<double>::min();
    std::cout << boost::math::float_distance(a, b) << std::endl;
    a = 1.0;
    b = 0.0;
    std::cout << boost::math::float_distance(a, b) << std::endl;

    float val1 = 1.0;
    // float_next
    std::cout << "Next representable value that is greater than 1.0: " << boost::math::float_next(val1) << std::endl;
    // std::cout << "Next representable value that is greater than 'float' max: " << boost::math::float_next(std::numeric_limits<float>::max()) << std::endl; // Overflow Error
    
    // float_prior
    std::cout << "Next representable value that is less than 1.0: " << boost::math::float_prior(val1) << std::endl;
    // TODO no Overflow Error?
    std::cout << "Next representable value that is less than 'float' min: " << boost::math::float_prior(std::numeric_limits<float>::min()) << std::endl;
    
    // float_advance
    std::cout << "1.0 advanced by 100.0: " << boost::math::float_advance(val1, 100.0) << std::endl;
    std::cout << "1.0 advanced by -100.0: " << boost::math::float_advance(val1, -100.0) << std::endl;

    // nextafter(x, y)
    std::cout << "Next representable value that is greater than 1.0: " << boost::math::nextafter(val1, std::numeric_limits<float>::max()) << std::endl;
    std::cout << "Next representable value that is greater than 'float' max: " << boost::math::nextafter(std::numeric_limits<float>::max(), std::numeric_limits<float>::max()) << std::endl;
}