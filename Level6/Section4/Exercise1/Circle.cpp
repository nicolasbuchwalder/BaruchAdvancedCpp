// Circle.cpp: This file contains the Circle class, which is a shape with a point and radius
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include "Circle.h"


Circle::Circle() :  // Default constructor
    _c{ new Point }, _r{ new double(0) }{};
Circle::Circle(const Point& c, double r) :  // Constructor point and radius
    _c{ new Point(c) }, _r{ new double(r) }{};
Circle::Circle(const Circle& pt) :  // Copy constructor
    _c{ new Point(*pt._c) }, _r{ new double(*pt._r) }{};
Circle& Circle::operator=(const Circle& pt) { // Assignment operator
    Circle c(pt);
    return c;
};
Point Circle::CenterPoint() const { return *this->_c; };  // Return center point
double Circle::Radius() const { return *this->_r; };  // Return radius
void Circle::CenterPoint(Point centre) {  // Set center point
    delete _c;
    this->_c = new Point(centre);
};
void Circle::Radius(double radius) {  // Set radius
    delete _r;
    this->_r = new double(radius);
};
// overriding the printing function of shape abstract class
std::string Circle::print() const {
    return "Circle( c=" + (*this->_c).print() + ", r=" + std::to_string(*_r) + " )";
};

// clone method: copy of shape without knowing the exact type
std::shared_ptr<Shape> Circle::Clone() {
    return std::make_shared<Circle>(*this);
}


