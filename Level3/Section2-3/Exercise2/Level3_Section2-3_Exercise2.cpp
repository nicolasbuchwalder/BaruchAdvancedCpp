// Level3_Section2-3_Exercise2.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <memory>
#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>
#include <array>

// GIVEN CODE (EX1)

struct X {
    double val;

    X() : val(0.0) {}
    void operator()() { std::cout << "An X " << val << std::endl; }
};

// C++11
template <typename T>
using GenericPointerType = std::shared_ptr<T>;
using PointerType = GenericPointerType<X>;


// PART A)
// 
// function to modify the value of the class
void Modify(PointerType& p, double newVal)
{
    // Wait a while, long enough to trigger the race
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    p->val = newVal;

};

int main() {

    // PART B)
    
    // creating the instance which will be modified by the threads
    PointerType x{ new X };
    x->val = -1;
    // building an array of threads
    const int numThreads{ 100 };
    std::array<std::thread, numThreads> threads;

    // modifying the pointer with all hundred threads with increaseing value
    int val{ 0 };
    for (int i{ 0 }; i < numThreads; ++i) {
        // modifying pointer
        threads[i] = std::thread(Modify, std::ref(x), val);
        ++val;
    };
    for (auto& t : threads) { t.join(); };

    // PART C)
    std::cout << "final value: " << x->val << std::endl;
    // => we notice that sometimes, the value is staying at 0, which is the first value that is being updated, 
    // so we have indeed some problems of access with the next threads

}