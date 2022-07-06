// IODevice2.h: This is a derived IODevice class for the device 2 on which CAD is shown. @Nicolas Buchwalder


#pragma once
#include "IODevice.h"
#include "Circle.h"
#include "Line.h"

#include <iostream>

// This class will simply overload << to show how the shapes will be shown on the specific device 
class IODevice2 :
    public IODevice
{
public:
    void IODevice::operator<<(const Circle& c) {
        std::cout << "IODevice2 shows " << c << std::endl;
    };
    void IODevice::operator<<(const Line& l) {
        std::cout << "IODevice2 shows " << l << std::endl;
    };

};

