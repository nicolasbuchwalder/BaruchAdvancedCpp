// C1.h: Class that contains shared pointer with class C1
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#pragma once
#include <memory>
#include <iostream>

class C1 {
private:
    std::shared_ptr<double> d;

public:
    C1(std::shared_ptr<double> value) : d(value) {}
    virtual ~C1() { std::cout << "C1 destructor" << std::endl; }
    void print() const { std::cout << "Value: " << *d << std::endl; }
};

