#include <iostream>
#include <vector>
#include <array>
#include <complex>
#include <string>
#include <sstream>


// PART A)

// Addition for compound types (e.g. std::vector<int>)
template <typename T>
T Addition_Impl(const T& t1, const T& t2, std::true_type) {
    T result;

    for (auto i = 0; i < t1.size(); ++i)
        result[i] += t1[i] + t2[i];

    return result;
}

// Addition for non compound types (e.g. int)
template <typename T>
T Addition_Impl(const T& t1, const T& t2, std::false_type) {
    return t1 + t2;
}

// Non static
// Addition declaration
template <typename T>
T Addition(const T& t1, const T& t2) {
    return Addition_Impl(t1, t2, std::is_compound<T>());
}


// PART B)

// Additive inverse for compound types
template <typename T>
void AdditiveInverse_Impl(T& t, std::true_type) {
    for (auto i = 0; i < t.size(); ++i)
        t[i] = -t[i];
}

// Additive inverse for non compound types
template <typename T>
void AdditiveInverse_Impl(T& t, std::false_type) {
    t = -t;
}

// Static
// Additive inverse declaration
template <typename T>
void AdditiveInverse(T& t) {
    AdditiveInverse_Impl(t, std::is_compound<T>());
}


// PART C)

// Static
// Multiplication declaration
template <typename Arrlike, typename Scalar>
Arrlike Multiplication(const Arrlike& t1, const Scalar& t2) {
    Arrlike result;

    for (auto i = 0; i < t1.size(); ++i)
        result[i] = t1[i] * t2;

    return result;
}


// To print the results
template <typename T>
std::string arraylikeToString(const T& t) {
    std::ostringstream os;
    os << "[";

    for (auto i = 0; i < t.size(); ++i) {
        os << t[i];

        if (i != t.size() - 1)
            os << ", ";
    }

    os << "]";
    std::string result(os.str());
    return result;
}

int main() {
    // PART D)
    
    // Definitions
    // array
    std::array<double, 4> arr1 = {1, 3, 5, 7};
    std::array<double, 4> arr2 = {3, 5, 7, 9};
    // vector
    std::vector<double> vec1 = {2, 4, 6, 8};
    std::vector<double> vec2 = {4, 6, 8, 10};
    // vector of complex
    std::complex<double> cmp1(1, 3);
    std::complex<double> cmp2(2, 4);
    std::complex<double> cmp3(3, 5);
    std::complex<double> cmp4(4, 6);
    std::vector<std::complex<double>> veccmp1{cmp1, cmp2};
    std::vector<std::complex<double>> veccmp2{cmp3, cmp4};
    // scalar
    double scal1 = 5;
    double scal2 = 10;

    // Addition
    std::cout << "Addition: " << std::endl;
    std::cout << arraylikeToString(Addition(arr1, arr2)) << std::endl;
    std::cout << arraylikeToString(Addition(vec1, vec2)) << std::endl;
    std::cout << Addition(scal1, scal2) << std::endl;
    std::cout << std::endl;

    // Additive inverse
    std::cout << "Additive inverse: " << std::endl;
    AdditiveInverse(arr1);
    AdditiveInverse(vec1);
    AdditiveInverse(scal1);
    std::cout << arraylikeToString(arr1) << std::endl;
    std::cout << arraylikeToString(vec1) << std::endl;
    std::cout << scal1 << std::endl;
    std::cout << std::endl;

    // Multiplication
    std::cout << "Multiplication: " << std::endl;
    Multiplication(arr2, scal1);
    Multiplication(vec2, scal1);
    std::cout << arraylikeToString(arr1) << std::endl;
    std::cout << arraylikeToString(vec1) << std::endl;

    // PART E)

    // addition
    std::cout << arraylikeToString(Addition(veccmp1, veccmp2)) << std::endl;
    // additive inverse
    AdditiveInverse(veccmp1);
    std::cout << arraylikeToString(veccmp1) << std::endl;
    // multiplication
    Multiplication(veccmp2, scal1);
    std::cout << arraylikeToString(veccmp2) << std::endl;
}