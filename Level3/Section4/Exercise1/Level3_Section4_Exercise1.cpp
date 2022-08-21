// Level3_Section4_Exercise1.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course


#include <iostream>
#include <future>


// PART A)
void func1()
{
    std::cout << "function1" << std::endl;
};

double func2(double a, double b)
{
    std::cout << "function2" << std::endl;
    return a * b;
};


int main() {

    // PART B)
    
    // using async to launch both func1 and func2
    std::future<void> resfunc1(std::async(func1));
    std::future<double> resfunc2(std::async(func2, 2, 3));

    // checking the validity of the future before
    std::cout << "f1 valid before " << std::boolalpha << resfunc1.valid() << std::endl;
    std::cout << "f2 valid before " << std::boolalpha << resfunc2.valid() << std::endl;

    resfunc1.get();
    resfunc2.wait();
    //std::cout << "value of func1: " << resfunc1.get() << std::endl;
    //=> not possible as it is void
    std::cout << "value of func2: " << resfunc2.get() << std::endl;

    // checking the validity of the future after
    std::cout << "f1 valid after " << std::boolalpha << resfunc1.valid() << std::endl;
    std::cout << "f2 valid after " << std::boolalpha << resfunc2.valid() << std::endl;
    //=> future not valid after getting the value

    // PART C)
    
    //resfunc1.get();
    //=> it throws an exception

    // PART D)

    // using launch::async to launch both func1 and func2
    std::future<void> resfunc1Launch(std::async(std::launch::async, func1));
    std::future<double> resfunc2Launch(std::async(std::launch::async, func2, 2, 3));

    resfunc1Launch.get();
    resfunc2Launch.wait();
    resfunc2Launch.get();
 
    //=> we get really async behavior as the function is launched on its own thread

    // PART E)
    std::future<void> resfunc1Launch2(std::async(std::launch::async, func1));
    std::future<double> resfunc2Deferred(std::async(std::launch::deferred, func2, 2, 3));

    resfunc1Launch2.get();
    resfunc2Deferred.wait();
    resfunc2Deferred.get();

    //=> no noticeable change

    
}
