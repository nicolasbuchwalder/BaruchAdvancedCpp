// Level1_Section1_Exercise2.cpp: This file contains all the code for this exercise. @Nicolas Buchwalder
#include <iostream>
#include <algorithm>
#include <vector>
#include <complex>
#include <numeric>

// function to print vector
void printVector(std::vector<int>& v) {
    for (auto i : v)
        std::cout << i << ' ';
    std::cout << std::endl;
};


// Given code

auto MyMultiply = [](auto x, auto y) { return x * y; };

struct FOMultiply
{
    template <typename T>
    T operator () (const T& x, const T& y)
    {
        return x * y;
    }

};

template <typename T>
T MyMultiply2(const T& x, const T& y) { return x * y; };


using Complex = std::complex<double>;
std::vector<Complex> complexArray{ Complex(1.0, 1.0), Complex(2.0, 2.0) };
Complex initCVal(1.0, 1.0);



int main() {

    // Given algorithm

    std::vector<int> vec{ 1,2,3,4,5 };
    int initVal = 1;

    // accumulate with stl
    int acc{ std::accumulate(vec.begin(), vec.end(), initVal, std::multiplies<int>()) };
    // accumulate with lambda function
    int accGeneric{ std::accumulate(vec.begin(), vec.end(), initVal, MyMultiply) };
    // accumulate with function object
    int accTemplate{ std::accumulate(vec.begin(), vec.end(), initVal, FOMultiply()) };
    // complex accumulate with function object
    Complex accC{ std::accumulate(complexArray.begin(), complexArray.end(), initCVal, FOMultiply()) };
    // complex accumulate with function lambda function
    Complex accCGeneric{ std::accumulate(complexArray.begin(), complexArray.end(), initCVal, MyMultiply) };
    // complex accumulate with function template function
    Complex accCGenericTemplate{ std::accumulate(complexArray.begin(), complexArray.end(), initCVal, MyMultiply2<Complex>) };

    // PART A)
    std::cout << "Sum stl::multiplies : " << acc << std::endl;
    std::cout << "Sum generic lambda : " << accGeneric << std::endl;
    std::cout << "Sum template: " << accTemplate << std::endl;
    std::cout << "Sum complex template: " << accC << std::endl;
    std::cout << "Sum complex generic: " << accCGeneric << std::endl;
    std::cout << "Sum complex generic template: " << accCGenericTemplate << std::endl;
    std::cout << std::endl;

    // => everything is the same 

    // PART B)

    auto sum_ints{ 0 };
    Complex sum_complex{ 0.0, 0.0 };

    // computing the sum of the arrays for int and complex
    std::for_each(vec.begin(), vec.end(), [&](int const& i) {sum_ints += i; });
    std::for_each(complexArray.begin(), complexArray.end(), [&](Complex const& i) {sum_complex += i; });

    std::cout << "Sum of ints array is: " << sum_ints << std::endl;
    std::cout << "Sum of complex array is: " << sum_complex << std::endl;

    std::cout << std::endl;
    // => it works fine

    // PART C)
    // stored lambda function that substracts susbtractor from vector. We use for_each as stl algorithm
    int substractor{ 5 };
    auto substract = [&](int& i) {i -= substractor; };

    printVector(vec);
    std::for_each(vec.begin(), vec.end(), substract);
    printVector(vec);
}
