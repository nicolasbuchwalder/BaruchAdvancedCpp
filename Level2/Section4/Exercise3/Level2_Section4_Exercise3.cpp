// Level2_Section4_Exercise3.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course


#include <iostream>
#include <memory>

int main() {
    // PART A)

    // GIVEN CODE
    using std::auto_ptr;
    // Define auto_ptr pointers instead of raw pointers
    std::auto_ptr<double> d(new double(1.0));

    // Dereference
    *d = 2.0;

    // Change ownership of auto_ptr
    // (after assignment, d is undefined)
    std::auto_ptr<double> d2 = d;
    *d2 = 3.0;

    // std::cout << "Auto values: " << *d.get() << ", " << *d2.get();
    //=> we have a run time error: d has no value to which it points but is no nullptr

    // PART B)

    // Define unique_ptr pointers instead of auto_ptr pointers
    std::unique_ptr<double> e(new double(1.0));

    // Dereference
    *e = 2.0;

    // Change ownership of auto_ptr
   
    // std::unique_ptr<double> e2 = e;
    //=> after assignment, d is undefined, shared_ptr shows that error at compile time
    //*e2 = 3.0;

    //std::cout << "Auto values: " << *e.get() << ", " << *e2.get();
};