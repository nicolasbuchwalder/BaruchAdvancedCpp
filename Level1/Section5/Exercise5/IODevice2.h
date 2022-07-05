#pragma once
#include "IODevice.h"
#include "Circle.h"
#include "Line.h"

#include <iostream>
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

