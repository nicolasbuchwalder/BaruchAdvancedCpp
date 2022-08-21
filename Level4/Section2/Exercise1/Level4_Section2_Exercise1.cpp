// Level4_Section2_Exercise1.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <tuple>
#include <vector>
#include <algorithm>
#include <iostream>

// GIVEN CODE
using Range = std::tuple<std::size_t, std::size_t>;
using Result = std::tuple<Range, bool>;

// PART A)

// standard find_sequantial_greater
template <typename T>
Result find_sequential_greater(const std::vector<T>& v, T x)
{
    for (std::size_t j = 0; j < v.size(); ++j)
    {
        if (v[j] <= x && v[j + 1] > x)
        {
            return std::make_tuple(
                std::make_tuple(j, j + 1), true);
        }
    }
    return std::make_tuple(std::make_tuple(999, 999), false);
}

// find_sequential_greater with find if
template <typename T>
Result find_sequential_greater_find_if(const std::vector<T>& v, T x) {
    int idx{ 0 };
    // lambda function for find if 
    // captures value of x and reference to v (more efficient for vector) and idx (needs to update it)
    auto inbetween = [x, &v, &idx](T data) {
        if (v[idx] <= x && v[idx + 1] > x) {
            ++idx;
            return true;
        }
        ++idx;
        return false;

    };
    // getting value of findif
    auto res{ std::find_if(v.begin(), v.end(), inbetween) };

    // if not results are found, find_if returns end
    // so only returning res with true flag if it isn't v end()
    if (res != v.end()) {

        // getting index number
        int resIdx = std::distance(v.begin(), res);
        return std::make_tuple(std::make_tuple(resIdx, resIdx + 1), true);
    };
    return std::make_tuple(std::make_tuple(999, 999), false);

}

// wrapper to find index of corresponding value
template <typename T>
Result find_matching_index(const std::vector<T>& v, T x)
{
    auto res{ std::find(v.begin(), v.end(), x) };

    // same as before
    if (res != v.end()) {

        // getting index number
        int resIdx = std::distance(v.begin(), res) ;
        return std::make_tuple(std::make_tuple(resIdx, resIdx), true);
    };
    return std::make_tuple(std::make_tuple(999, 999), false);
};

// PART B)

// lower bound wrapper
template <typename T>
Result find_sequential_greater_lower_bound(const std::vector<T>& v, T x) {

    // getting value of lower_bound
    auto res{ std::lower_bound(v.begin(), v.end(), x) };

    // if not results are found, find_if returns end
    // so only returning res with true flag if it isn't v end()
    if (res != v.end()) {

        // getting index number
        int resIdx = std::distance(v.begin(), res) ;
        return std::make_tuple(std::make_tuple(resIdx-1, resIdx ), true);
    };
    return std::make_tuple(std::make_tuple(999, 999), false);
};

// upper bound wrapper
template <typename T>
Result find_sequential_greater_upper_bound(const std::vector<T>& v, T x) {

    // getting value of upper_bound
    auto res{ std::upper_bound(v.begin(), v.end(), x) };

    // if not results are found, find_if returns end
    // so only returning res with true flag if it isn't v end()
    if (res != v.end()) {

        // getting index number
        int resIdx = std::distance(v.begin(), res);
        return std::make_tuple(std::make_tuple(resIdx - 1, resIdx), true);
    };
    return std::make_tuple(std::make_tuple(999, 999), false);
}

// PART C)

// std::equal_range wrapper
template <typename T>
Result find_sequential_greater_equal_range(const std::vector<T>& v, T x) {

    // getting value of equal_range
    auto res{ std::lower_bound(v.begin(), v.end(), x) };

    // if not results are found, find_if returns end
    // so only returning res with true flag if it isn't v end()
    if (res != v.end()) {

        // getting index number
        int resIdx =  std::distance(v.begin(), res);
        return std::make_tuple(std::make_tuple(resIdx-1, resIdx), true);
    };
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

    // PART A, B, C

    // checking that all three algorithms give the same

    std::vector<int> vec{ 1,2,3,4,6,7 };
    int x{ 5 };

    std::cout << "standard: ";
    printResult(find_sequential_greater(vec, x));

    std::cout << "find_if: ";
    printResult(find_sequential_greater_find_if(vec, x));

    std::cout << "lower_bound: ";
    printResult(find_sequential_greater_lower_bound (vec, x));

    std::cout << "upper_bound: ";
    printResult(find_sequential_greater_upper_bound(vec, x));

    std::cout << "equal range: ";
    printResult(find_sequential_greater_equal_range(vec, x));

    //=> all work and give the same result

    // PART D)

    // function that returns if function is even
    auto iseven = [](int val) {
        if (val % 2 == 0) {
            return true;
        }
        else {
            return false;
        }
    };

    std::vector<int> vec2 = { 2,4,6,8,9,10 };

    // finding first not even element
    auto res = std::find_if_not(vec2.begin(), vec2.end(), iseven);

    std::cout << "not even value: " << vec2[std::distance(vec2.begin(), res)] << std::endl;
    //=> returns 9, as expected

}