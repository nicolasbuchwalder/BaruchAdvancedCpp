// Level2_Section5_Exercise2.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <iostream>
#include <cmath>

// PART A)

// template function that computes the epsilon based on the algorithm given in the exercise
// generalised to all types
template <typename T>
T computeEpsilon() {
    T epsilon = (T)1.0;
    while ((T)1.0 + (T)0.5 * epsilon != (T)1.0) {
        epsilon *= (T)0.5;
    }
    return epsilon;
}

int main() {
    // PART B)
    std::cout
        << "Is computeEpsilon<double> the same as std::numeric_limits<double>::epsilon(): " 
        << std::boolalpha 
        << (computeEpsilon<double>() == std::numeric_limits<double>::epsilon()) 
        << std::endl;
    //=> we notice that it is indeed the same
}