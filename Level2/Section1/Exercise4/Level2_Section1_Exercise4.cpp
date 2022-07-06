// Level2_Section1_Exercise4.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <iostream>
// GIVEN CODE
#include "Point.h"
// PART D)
#include "PointNoCopyAssign.h"
// PART E)
#include "PointMove.h"

int main() {
    std::cout << std::boolalpha;
    std::cout << "With default class..." << std::endl;

    // PART A)
    //checking if Point has a virtual destructor
    std::cout << "Has virtual destructor:          " << std::has_virtual_destructor<Point>::value << std::endl;
    std::cout << std::endl;

    // PART B)
    //checking if Point has default, copy, move constructors
    std::cout << "Has 'default' constructor:       " << std::is_default_constructible<Point>::value << std::endl;
    std::cout << "Has 'move' constructor:          " << std::is_move_constructible<Point>::value << std::endl;
    std::cout << "Has 'copy' constructor:          " << std::is_copy_constructible<Point>::value << std::endl;
    std::cout << std::endl;
    // => all three are true even is no move constructor has explicitely been instantiated

    // PART C)
    // checking if Point is copy/move assignable
    std::cout << "Is copy assignable:              " << std::is_copy_assignable<Point>::value << std::endl;
    std::cout << "Is move assignable:              " << std::is_move_assignable<Point>::value << std::endl;
    std::cout << std::endl;
    //=> also both true because can bind to rvalue

    // PART D)
    // checking PART B-C) with deleted copy and assign constructors
    std::cout << "With deleted copy and assign constructors..." << std::endl;

    std::cout << "Has 'default' constructor:       " << std::is_default_constructible<PointNoCopyAssign>::value << std::endl;
    std::cout << "Has 'move' constructor:          " << std::is_move_constructible<PointNoCopyAssign>::value << std::endl;
    std::cout << "Has 'copy' constructor:          " << std::is_copy_constructible<PointNoCopyAssign>::value << std::endl;
    std::cout << std::endl;

    std::cout << "Is copy assignable:              " << std::is_copy_assignable<PointNoCopyAssign>::value << std::endl;
    std::cout << "Is move assignable:              " << std::is_move_assignable<PointNoCopyAssign>::value << std::endl;
    std::cout << std::endl;
    //=> deleted constructors change the type traits: now copy and assign constructors do not exist (so implicitely move as well)
    
    // PART E)
     // checking PART B-C) with move constructors
    std::cout << "With move constructors..." << std::endl;

    std::cout << "Has 'default' constructor:       " << std::is_default_constructible<PointMove>::value << std::endl;
    std::cout << "Has 'move' constructor:          " << std::is_move_constructible<PointMove>::value << std::endl;
    std::cout << "Has 'copy' constructor:          " << std::is_copy_constructible<PointMove>::value << std::endl;
    std::cout << std::endl;

    std::cout << "Is copy assignable:              " << std::is_copy_assignable<PointMove>::value << std::endl;
    std::cout << "Is move assignable:              " << std::is_move_assignable<PointMove>::value << std::endl;
    std::cout << std::endl;
    //=> copy and copy assignement are not possible with move constructors, just as expected 
}