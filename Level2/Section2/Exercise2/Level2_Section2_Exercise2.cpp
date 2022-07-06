// Level2_Section2_Exercise2.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include "BasicClass.h"

#include <iostream>
#include <array>


enum Enumeration { one, two, three };

int main() {

    std::cout << std::boolalpha;
    // PART A)

    // testing all types
    std::cout << "type        is_array" << std::endl;
    // fundamental types
    std::cout << "Fundamental:" << std::endl;
    std::cout << "void:       " << std::is_array<void>::value << std::endl;
    std::cout << "int:        " << std::is_array<int>::value << std::endl;
    std::cout << std::endl;
    // scalar types
    std::cout << "Scalar:" << std::endl;
    std::cout << "char:       " << std::is_array<char>::value << std::endl;
    std::cout << "bool:       " << std::is_array<bool>::value << std::endl;
    std::cout << std::endl;
    // object types
    std::cout << "Object:" << std::endl;
    std::cout << "BasicClass: " << std::is_array<BasicClass>::value << std::endl;
    std::cout << "Enumeration:" << std::is_array<Enumeration>::value << std::endl;
    std::cout << std::endl;

    // arithmetic types
    std::cout << "Arithmetic:" << std::endl;
    std::cout << "float:      " << std::is_array<float>::value << std::endl;
    std::cout << "double:     " << std::is_array<double>::value << std::endl;
    std::cout << "long:       " << std::is_array<long double>::value << std::endl;
    std::cout << std::endl;

    // compound types
    std::cout << "Compound:" << std::endl;
    std::cout << "array:      " << std::is_array<int[]>::value << std::endl;
    std::cout << "std::array: " << std::is_array<std::array<int, 3>>::value << std::endl;
    std::cout << "pointer:    " << std::is_array<int*>::value << std::endl;
    std::cout << "array ptr:  " << std::is_array<std::array<int, 3>*>::value << std::endl;
    std::cout << "int ref:    " << std::is_array<int&>::value << std::endl;
    std::cout << "array ref:  " << std::is_array<std::array<int, 3>&>::value << std::endl;
    std::cout << std::endl << std::endl;
    //=> we notice that only arrays are arrays type, even references or pointers to arrays are not arrays

    // PART B)

    std::cout << "Array ranks and extents:" << std::endl;

    // checking the rank and extent of a int array
    std::cout << "With normal array..." << std::endl;
    std::cout << "Rank:       " << std::rank<int[][3][4][5]>::value << std::endl;
    std::cout << "Extent:     " << std::extent<int[][3][4][5]>::value << std::endl;
    std::cout << std::endl;

    // PART C)
    // checking the rank and extent of a int array with removed all extents
    std::cout << "With all extents removed..." << std::endl;
    std::cout << "Rank:       " << std::rank<std::remove_all_extents<int[][3][4][5]>>::value << std::endl;
    std::cout << "Extent:     " << std::extent<std::remove_all_extents<int[][3][4][5]>>::value << std::endl;
    //=> remove_all_extents gives the type of the array if it is one, so it makes sense that rank and extent goes to 0
}