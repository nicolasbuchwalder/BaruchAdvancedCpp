// Level2_Section3_Exercise2.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <iostream>
#include <vector>
#include <array>
#include <functional>

// template function to print array
template <typename T>
void printArray(const T& vec) {
    for (auto elem : vec)
        std::cout << elem << ", ";

    std::cout << std::endl;
}

int main() {

    // PART A)

    int size = 4;
    double val = 2.71;
    std::vector<double> data(size, val);
    // show size of data
    std::cout << "data size before: " << data.size() << std::endl;

    // Move capture mode (preferred)
    auto fun = [data = std::move(data)]() mutable {
        for (std::size_t i = 0; i < data.size(); ++i) {
            data[i] = 3.14;
            std::cout << data[i] << ",";
        }
        std::cout << std::endl;
    };

    fun();

    // checking the data size with move semantics
    std::cout << "data size after:  " << data.size() << std::endl;
    //=> data has been moved and is therefore empty

    // PART B)
    // nothing to do except copy paste given code
    int x = 1'000'000;
    auto fun4 = [&r = x]()
    {
        r *= 2;
        std::cout << "\nr: " << r;
    };

    fun4();


    // PART C)

    // Init capture using C++14
    int size2 = 3;
    double val2 = 1.41;
    std::vector<double> data2(size2, val2);
    std::array<double, 3> data3 = { 1.2, 2.4, 4.7 };

    // again, here we are using two move semantics for data2 and data3
    auto fun3 = [array = std::move(data2), array2 = std::move(data3)]() mutable {
        for (std::size_t i = 0; i < array.size(); ++i) {
            array[i] = 3.14;
            std::cout << array[i] << "/";
        }

        std::cout << '\n';

        for (std::size_t i = 0; i < array2.size(); ++i) {
            array2[i] = 2.71;
            std::cout << array2[i] << "/";
        }
    };

    fun3();

    if (0 == data2.size() || 0 == data3.size()) {
        std::cout << "\nDouble arrays have no elements, OK\n";

    }
    else {
        std::cout << "\n Ouch!\n";

        for (std::size_t i = 0; i < data2.size(); ++i) {
            std::cout << data2[i] << ",";
        }

        for (std::size_t i = 0; i < data3.size(); ++i) {
            std::cout << data3[i] << ",";
        }
    }
}