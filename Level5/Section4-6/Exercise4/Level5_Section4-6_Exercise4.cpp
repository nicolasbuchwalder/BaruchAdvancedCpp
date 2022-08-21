// Level5_Section4-6_Exercise4.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <boost/functional/hash.hpp>
#include <iostream>
#include <string>

// PART A)

// end function of variadic hash
template <typename T>
void hash_value(std::size_t& seed, const T& val)
{
    // combining hash of seed with last value
    boost::hash_combine(seed, val);
};

// variadic hash
template <typename T, typename... Types>
void hash_value(std::size_t& seed, const T& val, const Types&... args)
{
    // combining seed with first value
    boost::hash_combine(seed, val);

    // calling recursively
    hash_value(seed, args...);
};


// PART B)

template <typename... Types>
std::size_t hash_value(const Types&... args)
{
    std::size_t seed = 0;
    hash_value(seed, args...);
    return seed;
};

int main() {

    // PART A)

    double v1{ 3.14 };
    double v2{ 1.44 };
    double v3{ 1.68 };

    std::size_t seed{ 0 };
    hash_value(seed, v1);
    std::cout << "hash with one argument: " << seed << std::endl;

    seed = 0;
    hash_value(seed, v1, v2);
    std::cout << "hash with two arguments: " << seed << std::endl;

    seed = 0;
    hash_value(seed, v1, v2, v3);
    std::cout << "hash with three arguments: " << seed << std::endl;

    //=> seems to work with any number of arguments

    // PART B)

    int int_var{ 1 };
    double double_var{ 3.14 };
    std::string string_var{ "hello" };

    seed = hash_value(int_var);
    std::cout << "hash with one argument: " << seed << std::endl;

    seed = hash_value(int_var, double_var);
    std::cout << "hash with two heterogenuous arguments: " << seed << std::endl;

    seed = hash_value(int_var, double_var, string_var);
    std::cout << "hash with three heterogenuous arguments: " << seed << std::endl;

    //=> seems to work with any number of arguments of heterogenuous types

}