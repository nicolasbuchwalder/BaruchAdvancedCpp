#include <iostream>
#include <memory>

class Point {
public:
    double x, y;

    Point(double x_, double y_) {
        x = x_;
        y = y_;
    };

    void X(double x_) {
        x = x_;
    }

    void Y(double y_) {
        y = y_;
    }
};

int main() {
    // PART A)

    double* d = new double (1.0);
    Point* pt = new Point(1.0, 2.0); // Two-d Point class

    // Dereference and call member functions
    *d = 2.0;
    (*pt).X(3.0); // Modify x coordinate
    (*pt).Y(3.0); // Modify y coordinate

    // Can use operators for pointer operations
    pt->X(3.0); // Modify x coordinate
    pt->Y(3.0); // Modify y coordinate

    try {
        Point* pt = new Point(1.0, 2.0);
        throw 1;
    }
    catch (int e) {
        std::cout << "Exception caught" << std::endl;
    }

    // Explicitly clean up memory (if you have not forgotten)
    delete d;
    delete pt;

    // PART B)

    std::unique_ptr<double> d1(new double(1.0));
    std::unique_ptr<Point> pt1(new Point(1.0, 2.0)); // Two-d Point class  

    // Dereference and call member functions
    *d1 = 2.0;
    (*pt1).X(3.0); // Modify x coordinate
    (*pt1).Y(3.0); // Modify y coordinate

    // Can use operators for pointer operations
    pt1->X(3.0); // Modify x coordinate
    pt1->Y(3.0); // Modify y coordinate

    try {
        std::unique_ptr<Point> pt1(new Point(1.0, 2.0));
        throw 1;
    }
    catch (int e) {
        std::cout << "Exception caught" << std::endl;
    }

    // delete d1;
    // delete pt1;
    // Throws error: type 'class std::unique_ptr<Point>' argument given to 'delete', expected pointer
}