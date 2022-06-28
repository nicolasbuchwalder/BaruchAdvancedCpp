#pragma once
#include "Shape.h"
//#include "IODevice.h"

#include <array>
class Line :
    public Shape
{
private:
    std::array<double, 2> start;
    std::array<double, 2> end;

public:
    // default
    Line() { start = { 0,0 }; end = { 1,1 }; }

    // constructor
    Line(double x1, double y1, double x2, double y2) : start{ x1, y1 }, end{ x2, y2 }{};

    // overriding diplay function: so that the IODevide will recieve it
    void display(IODevice& io) const { io << *this; };

    // overring printing function that is necessary for the << overload on base class Shape    
    std::ostream& print(std::ostream& out) const {
        out << "Line  from (" << start[0] << ", " << start[1] << ") to (" << end[0] << ", " << end[1] << ")" << std::endl;
        return out;
    };
};

