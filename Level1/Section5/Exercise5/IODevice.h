// IODevice.h: This is the base IODevice class for the devices on which CAD is shown. @Nicolas Buchwalder

#pragma once
#include "Shape.h"

class Circle;
class Line;

class IODevice
{
    // Interface for displaying CAD objects
public:
    virtual void operator << (const Circle& c) = 0;
    virtual void operator << (const Line& c) = 0;
};

