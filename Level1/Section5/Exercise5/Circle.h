#pragma once
#include "Shape.h"

#include <array>
#include <iostream>

// forward decleration of the IODevice base class
class IODevice;

// circle inherits the overloaded << operator and must override the display and print functions 
class Circle :
    public Shape
{
private:
    std::array<double, 2> pos;
    double radius;

public:
    // default
    Circle() { pos = { 0.0, 0.0 }; radius = 1.0; };
    // constructor (not used)
    Circle(double x, double y, double r) : pos{ x, y }, radius{ r }{};

    // overriding diplay function: so that the IODevice will recieve it
    void display(IODevice& io) const { io << *this; };

    // overring printing function that is necessary for the << overload on base class Shape
    std::ostream& print(std::ostream& out) const {
        out << "Circle  at (" << pos[0] << ", " << pos[1] << "), radius " << radius << std::endl;
        return out;
    }; 
    
};

