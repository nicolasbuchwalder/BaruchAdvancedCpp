// C3.h: Class that contains shared pointer which is of Point
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course
#pragma once
class C3 {
private:
    std::shared_ptr<Point> pt;

public:
    C3(std::shared_ptr<Point> value) : pt(value) {}
    virtual ~C3() { std::cout << "C3 destructor" << std::endl; }
    void print() const { std::cout << "x: " << pt->x << " y: " << pt->y << std::endl; }
};

