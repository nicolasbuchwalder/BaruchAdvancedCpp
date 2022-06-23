#include <iostream>

class Shape {
public:
    virtual void draw() = 0;
};

class Point : public Shape {
public:
    Point() {}
    virtual void draw() override {}
};

class Point2 : public Shape {
public:
    Point2(const Point&&) = delete;
    Point2& operator=(const Point&&) = delete;
    virtual void draw() override {}
};

int main() {
    std::cout << std::boolalpha;
    std::cout << "With default class..." << std::endl; 

    // PART A)

    std::cout << "Has virtual destructor:          " << std::has_virtual_destructor<Point>::value << std::endl;
    std::cout << std::endl;

    // PART B)

    std::cout << "Has 'default' constructor:       " << std::is_default_constructible<Point>::value << std::endl;
    std::cout << "Has 'move' constructor:          " << std::is_move_constructible<Point>::value << std::endl;
    std::cout << "Has 'copy' constructor:          " << std::is_copy_constructible<Point>::value << std::endl;
    std::cout << std::endl;

    // PART C)

    std::cout << "Is copy assignable:              " << std::is_copy_assignable<Point>::value << std::endl;
    std::cout << "Is move assignable:              " << std::is_move_assignable<Point>::value << std::endl;
    std::cout << std::endl;

    // PART D) // TODO probablement pas les resultats attendus

    std::cout << "With deleted copy constructor..." << std::endl;

    std::cout << "Has virtual destructor:          " << std::has_virtual_destructor<Point2>::value << std::endl;
    std::cout << std::endl;

    std::cout << "Has 'default' constructor:       " << std::is_default_constructible<Point2>::value << std::endl;
    std::cout << "Has 'move' constructor:          " << std::is_move_constructible<Point2>::value << std::endl;
    std::cout << "Has 'copy' constructor:          " << std::is_copy_constructible<Point2>::value << std::endl;
    std::cout << std::endl;

    std::cout << "Is copy assignable:              " << std::is_copy_assignable<Point2>::value << std::endl;
    std::cout << "Is move assignable:              " << std::is_move_assignable<Point2>::value << std::endl;
    std::cout << std::endl;

    // PART E) // TODO
}