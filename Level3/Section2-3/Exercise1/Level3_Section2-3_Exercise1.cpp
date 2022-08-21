// Level3_Section2-3_Exercise1.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <atomic>
#include <iostream>
#include <memory>


// GIVEN CODE
struct X
{
    double val;

    X() : val(0.0) {}
    void operator ()() {
        std::cout << "An X " << val << std::endl;
    }
};

// C++11
template <typename T>
using GenericPointerType = std::shared_ptr<T>;
using PointerType = GenericPointerType<X>;

int main() {
    // PART A)
    
    // creating an instance x of class PointerType and givien it a value of pi
    PointerType x{ new X };
    x->val = 3.14;

    // PART B)
    
    // creating an instance x2 of class PointerType and atomically store it value in x
    PointerType x2{ new X };
    x2->val = 1.44;
    std::cout << "old value of x: " << x->val << std::endl;
    std::atomic_store(&x, x2);
    std::cout << "new value of x: " << x->val << std::endl;
    //=> value had indeed been updated

    // PART C)

    // creating a new pointer x3 and exchanging it both x and x2
    PointerType x3{ new X };
    x3->val = 1.0;
    PointerType old_x3 = std::atomic_exchange(&x3, x);
    std::cout << "new value of x3: " << x3->val << ", old value of x3: " << old_x3->val << std::endl;
    old_x3 = std::atomic_exchange(&x3, x2);
    std::cout << "new value of x3: " << x3->val << ", old value of x3: " << old_x3->val << std::endl;
    //=> works as expected (both x and x2 are at 1.44)

    // PART D)

    // use counts of each shared_pointer is:
    std::cout << "number of shared pointer instances for x: " << x.use_count() << std::endl;
    std::cout << "number of shared pointer instances for x2: " << x2.use_count() << std::endl;
    std::cout << "number of shared pointer instances for x3: " << x3.use_count() << std::endl;
    //=> they all have four instances
    
    // PART E)
    // there could be data races if the threads uses a non-const member function of shared_ptr, so shared_ptr is not thread-safe
    // which means that it doesn't make sense to have atomic on thread-unsafe objects

    // PART F)
  
    std::cout << "atomic shared_ptr is lock free: " << std::boolalpha << std::atomic_is_lock_free(&x) << std::endl;
    //=> not lock free as expected

}