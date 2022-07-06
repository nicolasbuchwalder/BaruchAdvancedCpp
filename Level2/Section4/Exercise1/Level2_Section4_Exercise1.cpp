// Level2_Section4_Exercise1.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course
#include "Point.h"

#include <iostream>
#include <memory>



int main() {
    // PART A)
    // GIVEN CODE
    double* d = new double(1.0);
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
        // throwing exception
        throw 1;
    }
    catch (int e) {
        std::cout << "Exception caught" << std::endl;
    }
    //=> exception is indeed caught

    // Explicitly clean up memory (if you have not forgotten)
    delete d;
    delete pt;
    //=> we notice that we can delete it as there was a memory leak

    // PART B)
    // now doing the same but with shared pointers
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
    //=> hrows error: type 'class std::unique_ptr<Point>' argument given to 'delete', expected pointer
    //=> we dont need to do that as shared_ptr calls destructor by itself 

    // PART C)
    Point* pt2 = new Point(1.0, 2.0);
    // two unique pointers to same pointer:
    // std::unique_ptr<Point> unique1(pt2);
    // std::unique_ptr<Point> unique2(pt2);
    //=> throws errors as both will try to delete the pointer

    // assigning unique pointer to another unique pointer
    //std::unique_ptr<Point> unique3(pt2);
    //std::unique_ptr<Point> unique4(unique3);
    // => compile time error: cannot reference to deleted function

    // transferring ownership 
    std::unique_ptr<Point> unique4(pt2);
    std::unique_ptr<Point> unique5(std::move(unique4));
    // this works because we do not have unique pointers pointing to the same element which causes errors

    // PART D)
    // we can set the following alias:
    using unique_ptrPoint = std::unique_ptr<Point>;





}