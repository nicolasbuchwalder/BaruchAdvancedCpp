// Level2_Section1_Exercise3.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <iostream>

// GIVEN CODE
class Shape {
public:
    virtual void draw() = 0;
};

class Base {
private:
    static const int y{ 0 };
public:
    Base() {}
    void draw() {}
};

class Point : public Shape {
public:
    Point() {}
    virtual void draw() override {}
};

// PART A)

// template function to evaluate class
template <typename T>
void evalClass(const T& c) {
    std::cout << "is empty:        " << std::is_empty<T>::value << std::endl;
    std::cout << "is polymorphic:  " << std::is_polymorphic<T>::value << std::endl;
    std::cout << "is abstract:     " << std::is_abstract<T>::value << std::endl;
}


int main() {
    // setting boolalpha output
    std::cout << std::boolalpha;

    // PART A)

    Shape* shape; // only pointer as Shape is an abstract class
    Base base;
    Point point;

    std::cout << "Shape:" << std::endl;
    evalClass(shape);
    std::cout << std::endl << "Base:" << std::endl;
    evalClass(base);
    std::cout << std::endl << "Point:" << std::endl;
    evalClass(point);
    std::cout << std::endl;

    // PART B)

    // checking if std::is_same yields good results
    std::cout << "Base and base:   " << std::is_same<Base, Base>::value << std::endl;
    std::cout << "Shape and point: " << std::is_same<Shape, Point>::value << std::endl;
    std::cout << std::endl;

    // PART C)

    // checking if is_base_of yields good results
    std::cout << "classes          L is base of R" << std::endl;
    std::cout << "Point of Shape   " << std::is_base_of<Point, Shape>::value << std::endl;
    std::cout << "Shape of Point   " << std::is_base_of<Shape, Point>::value << std::endl;
    std::cout << "Shape of Base    " << std::is_base_of<Shape, Base>::value << std::endl;
    std::cout << std::endl;

    // PART D)

    // checking if is_convertible yields good results
    std::cout << "classes          L can be converted to R" << std::endl;
    std::cout << "Point to Shape   " << std::is_convertible<Point, Shape>::value << std::endl;
    std::cout << "Point to Base    " << std::is_convertible<Point, Base>::value << std::endl;
    std::cout << "Shape to Point   " << std::is_convertible<Shape, Point>::value << std::endl;
}