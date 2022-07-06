// Level2_Section4_Exercise4.cpp: This file contains the main function for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include "Base.h"
#include "Derived.h"

#include <iostream>
#include <memory>
#include <list>

// PART B)
// factory function to create instances of Derived and then add them to the list.
std::shared_ptr<Base> create_derived()
{
    std::shared_ptr<Base> ptr(new Derived());
    return ptr;
}

int main() {

    // PART A)
    // list of smart pointers to Base
    std::list<std::shared_ptr<Base>> baseListShared(1); 
    //=> compiles
    // std::list<std::unique_ptr<Base>> baseListUnique(1); 
    //=> compile error: it cannot access the protected destructor

    // PART C)

    // test create_derive and check for memory leaks
    std::shared_ptr<Base> derived = create_derived();
    derived->print();
    std::cout << "Pointers count: " << derived.use_count() << std::endl;
    derived.reset();
    std::cout << "Pointers count: " << derived.use_count() << std::endl;
    //=> no memory leaks 

}