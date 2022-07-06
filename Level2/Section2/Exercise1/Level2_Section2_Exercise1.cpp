// Level2_Section2_Exercise1.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <iostream>
#include <vector>
#include <array>
#include <complex>
#include <string>


// PART A)

// addition for compound types (e.g. std::vector<int>)
// implicit calling from third arugment (which will be decided by type traits)
template <typename T>
T Addition_impl(const T& t1, const T& t2, std::true_type) {
    T result(t1);
    // creating the array by adding both vectors elementwise
    for (auto i = 0; i < t1.size(); ++i) result[i] = t1[i] + t2[i];
    return result;
};

// addition for non compound types (e.g. int)
// implicit calling from third arugment (which will be decided by type traits)
template <typename T>
T Addition_impl(const T& t1, const T& t2, std::false_type) {
    return t1 + t2;
};

// function that will call either of the two above functions depending if the type is compound
template <typename T>
T Addition(const T& t1, const T& t2) {
    return Addition_impl(t1, t2, std::is_compound<T>());
};


// PART B)
// we implement things the same way as before but by simply setting a vector which is minus the input vector

// additive inverse for compound types
template <typename T>
T AdditiveInverse_impl(T& t, std::true_type) {
    T result(t);
    for (auto i = 0; i < t.size(); ++i) result[i] = -t[i];
    return result;
};

// additive inverse for non compound types
template <typename T>
T AdditiveInverse_impl(T& t, std::false_type) {
    return -t;
};

// function that will call either of the two above functions depending if the type is compound
template <typename T>
auto AdditiveInverse(T& t) {
    return AdditiveInverse_impl(t, std::is_compound<T>());
};


// PART C)
// as we want a function where the order do not matter, we want to implement for all possibilies

// multiplication with both scalars
template <typename Scalar, typename SecondScalar>
auto Multiplication_impl(const Scalar& t1, std::false_type, const SecondScalar& t2, std::false_type) {
    // returning auto so that the coherent type is returned
    return t1 * t2;
};

// multiplication with first an array and then a scalar
template <typename Array, typename Scalar>
Array Multiplication_impl(const Array& t1, std::true_type, const Scalar& t2, std::false_type) {
    Array result(t1);
    for (auto i = 0; i < t1.size(); ++i)
        result[i] = t1[i] * t2;
    return result;
};

// multiplication with first a scalar and then an array
template <typename Scalar, typename Array>
Array Multiplication_impl(const Scalar& t1, std::false_type, const Array& t2, std::true_type) {
    Array result(t2);
    for (auto i = 0; i < t1.size(); ++i)
        result[i] = t1[i] * t2;
    return result;
};

// multiplication with two arrays
template <typename Array, typename SecondArray>
std::string Multiplication_impl(const Array& t1, std::true_type, const SecondArray& t2, std::true_type) {
    return "Error: cannot multiply a vector with a vector.\n";
};

// function that will call one of the four functions above depending on the type traits of the imputs
template <typename FirstType, typename SecondType>
auto Multiplication(const FirstType& t1, const SecondType& t2) {
    return Multiplication_impl(t1, std::is_compound<FirstType>(), t2, std::is_compound<SecondType>());
};


// function to print arrays
template <typename T>
void printVector(const T& t) {
    std::cout <<"[ ";
    for (auto i = 0; i < t.size()-1; ++i) {
        std::cout << t[i] << ", ";
    };
    std::cout << t[t.size()-1] << " ]" << std::endl;
}

int main() {
    // PART D)

    // defining all variables
    double scal1 = 5;
    double scal2 = 10;
    std::array<double, 4> arr1 = { 1, 3, 5, 7 };
    std::array<double, 4> arr2 = { 3, 5, 7, 9 };
    std::vector<double> vec1 = { 2, 4, 6, 8 };
    std::vector<double> vec2 = { 4, 6, 8, 10 };

    // additions
    std::cout << "Addition: " << std::endl;
    std::cout << Addition(scal1, scal2) << std::endl;
    printVector(Addition(arr1, arr2));
    printVector(Addition(vec1, vec2));
    std::cout << std::endl;
    // => works for all three types

    // Additive inverse
    std::cout << "Additive inverse: " << std::endl;
    std::cout << AdditiveInverse(scal1) << std::endl;
    printVector(AdditiveInverse(arr1));
    printVector(AdditiveInverse(vec1));
    std::cout << std::endl;
    //=> works for all three types all well

    // Multiplication
    std::cout << "Multiplication: " << std::endl;
    std::cout << Multiplication(scal1, scal2) << std::endl;
    printVector(Multiplication(arr2, scal1));
    printVector(Multiplication(vec2, scal1));
    std::cout << Multiplication(vec1, vec2);
    std::cout << std::endl;

    // PART E)

    // defining complex vectors
    std::complex<double> cmp1(1, 3);
    std::complex<double> cmp2(2, 4);
    std::complex<double> cmp3(3, 5);
    std::complex<double> cmp4(4, 6);
    std::vector<std::complex<double>> veccmp1{ cmp1, cmp2 };
    std::vector<std::complex<double>> veccmp2{ cmp3, cmp4 };

    std::cout << "Complex numbers: " << std::endl;
    // addition
    printVector(Addition(veccmp1, veccmp2));

    // additive inverse
    printVector(AdditiveInverse(veccmp1));

    // multiplication
    printVector(Multiplication(veccmp2, scal1));
    //=> works as well with compound types and scalars

    std::cout << Multiplication(veccmp1, cmp2);
    std::cout << Multiplication(cmp1, cmp2);
    std::cout << std::endl;
    //=> issues can arise with complex numbers as a single number is a compound type
    //=> so multipling a complex array by a complex number or multipling complex numbers between them will make errors

};