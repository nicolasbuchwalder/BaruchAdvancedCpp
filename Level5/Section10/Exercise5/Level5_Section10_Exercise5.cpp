// Level5_Section10_Exercise5.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#define BOOST_TYPEOF_EMULATION

#include <string>
#include <iostream>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <vector>
#include <algorithm>

// GIVEN CODE

// template template print function 
template <typename T, template <typename S, typename Alloc > class Container, typename TAlloc>
void print(const std::string& comment,
    const Container<T, TAlloc>& container)
{
    // A generic print function for general containers
    std::cout << comment << ": ";

    // We use lambda for readability
    // a. iterators
    auto f = [](const T& t) { std::cout << t << ", "; };
    std::for_each(container.begin(), container.end(), f);
    std::cout << std::endl;

    // b. indexing
    for (std::size_t i = 0; i < container.size(); ++i)
    {
        std::cout << container[i] << ",";
    }
    std::cout << std::endl;
};

using Range = std::tuple<std::size_t, std::size_t>;
using Result = std::tuple<Range, bool>;

// template template function to find x
template <typename T, template <typename S, typename Alloc > class Container, typename TAlloc>
Result find_sequential_greater(const Container<T, TAlloc>& v, T x)
{
    std::size_t idx = std::distance(
        v.begin(),
        std::find_if(v.begin(), v.end(), [x](T elem) {return x > elem; }));

    if (idx = v.size()) {
        return std::make_tuple(std::make_tuple(idx, idx + 1), true);
    }
    return std::make_tuple(std::make_tuple(999, 999), false);
};

// function to print result
void printResult(const Result& res) {
    if (std::get<1>(res)) {
        auto indexes{ std::get<0>(res) };
        std::cout << "found element at index number: " << std::get<0>(indexes) << std::endl;
    }
    else {
        std::cout << "nothing found" << std::endl;
    };
};

int main() {

    std::vector<double> v1{ 2.0, 3.0, 4.0, -6.0 };
    std::sort(v1.begin(), v1.end());
    print(std::string("STL"), v1);
    double x{2.5};
    
    printResult(find_sequential_greater(v1, x));

    boost::numeric::ublas::vector<double> v2(4);
    v2[0] = 2.0; v2[1] = 3.0; v2[2] = 4.0; v2[3] = -6.0;
    std::sort(v2.begin(), v2.end());
    print(std::string("Boost"), v2);
    printResult(find_sequential_greater(v2, x));
}