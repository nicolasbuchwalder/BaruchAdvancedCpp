#pragma once

#include <iostream>

// forward decleration of the IODevice base class
class IODevice;

class Shape
{
public:
    // virtual function to display shape
    virtual void display(IODevice& ioDevice) const = 0;

    // vitural function to print shape
    virtual std::ostream& print(std::ostream& out) const = 0;

    // function to print out any derived shape from std::cout
    friend std::ostream& operator<<(std::ostream& out, const Shape& s)
    {
        return s.print(out);
    };
};


