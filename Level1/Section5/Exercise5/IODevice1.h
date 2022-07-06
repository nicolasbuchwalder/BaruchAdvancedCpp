// IODevice1.h: This is a derived IODevice class for the device 1 on which CAD is shown. @Nicolas Buchwalder

#pragma once
#include "IODevice.h"
#include "Circle.h"
#include "Line.h"

#include <iostream>

// This class will simply overload << to show how the shapes will be shown on the specific device 
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

