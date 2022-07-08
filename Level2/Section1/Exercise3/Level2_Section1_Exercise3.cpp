#include <iostream>

class Shape {
public:
    virtual void draw() = 0;
};

class Base {
private:
    static int y;
public:
    Base() {}
    void draw() {}
};

class Point : public Shape {
public:
    Point() {}
    virtual void draw() override {}
};

template <typename T>
void evalClass(const T& t) {
    std::cout << "is empty:        " << std::is_empty<T>::value << std::endl;
    std::cout << "is polymorphic:  " << std::is_polymorphic<T>::value << std::endl;
    std::cout << "is abstract:     " << std::is_abstract<T>::value << std::endl;
}

int Base::y = 0;
int main() {
    std::cout << std::boolalpha;

    // PART A)

    Shape* shape;
    Base base;
    Point point;

    std::cout << "Shape..." << std::endl;
    evalClass(shape);
    std::cout << std::endl << "Base..." << std::endl;
    evalClass(base);
    std::cout << std::endl  << "Point..." << std::endl;
    evalClass(point);
    std::cout << std::endl;

    // PART B)

    std::cout << "classes          is_same" << std::endl;
    std::cout << "Base and base:   " << std::is_same<Base, Base>::value << std::endl;
    std::cout << "Shape and point: " << std::is_same<Shape, Point>::value << std::endl;
    std::cout << std::endl;

    // PART C)

    std::cout << "classes          L is base of R" << std::endl;
    std::cout << "Point of Shape   " << std::is_base_of<Point, Shape>::value << std::endl;
    std::cout << "Shape of Point   " << std::is_base_of<Shape, Point>::value << std::endl;
    std::cout << "Shape of Base    " << std::is_base_of<Shape, Base>::value << std::endl;
    std::cout << std::endl;

    // PART D)

    std::cout << "classes          L can be converted to R" << std::endl;
    std::cout << "Point to Shape   " << std::is_convertible<Point, Shape>::value << std::endl;
    std::cout << "Point to Base    " << std::is_convertible<Point, Base>::value << std::endl;
    std::cout << "Shape to Point   " << std::is_convertible<Shape, Point>::value << std::endl;
}