// Level2_Section4_Exercise6.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <iostream>
#include <memory>

int main() {
    std::cout << std::boolalpha;

    // PART A)
    // creating a shared pointer and weak pointer 
    std::shared_ptr<int> ptr(new int(1));
    std::cout << "Pointers count before: " << ptr.use_count() << std::endl;
    std::weak_ptr<int> weakPtr(ptr);
    std::cout << "Pointers count after: " << ptr.use_count() << std::endl;
    std::cout << std::endl;
    //=> we see that it does not change the values

    // PART B)
    // creating a shared pointer and assigning it to a weak pointer
    std::shared_ptr<int> ptr2(new int(2));
    weakPtr = ptr2;
    std::cout << "Is weak ptr empty: " << weakPtr.expired() << std::endl;
    std::cout << std::endl;
    //=> we see that is the weak pointer is not empty

    // PART C)
    // assigning a weak pointer to another weak pointer
    std::weak_ptr<int> weakPtr2(weakPtr);
    std::cout << "Pointers count for weak_ptr: " << weakPtr.use_count() << std::endl;
    //=> only one pointer as expected
    // assigning a weak pointer to shared pointer
    std::shared_ptr<int> ptr3(weakPtr);
    std::cout << "Pointers count for shared_ptr: " << weakPtr.use_count() << std::endl;
    //two pointers as expected
}