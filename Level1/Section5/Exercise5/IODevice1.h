#pragma once
#include "IODevice.h"
#include "Circle.h"
#include "Line.h"

#include <iostream>

class IODevice1 :
    public IODevice
{
public:
    void IODevice::operator<<(const Circle& c) {
        std::cout << "IODevice1 shows " << c << std::endl;
    };
    void IODevice::operator<<(const Line& l) {
        std::cout << "IODevice1 shows " << l << std::endl;
    };
    
};

