// Level2_Section4_Exercise2.cpp: This file contains the main function for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

// PART A)
#include "C1.h"
#include "C2.h"

// PART C)
#include "Point.h"
#include "C3.h"


#include <iostream>
#include <memory>


int main() {
    std::cout << std::boolalpha;

    // PART B)

    std::shared_ptr<double> val(new double(1.0));

    std::cout << "Pointers count before: " << val.use_count() << std::endl;

    {
        C1 c1(val);
        c1.print();

        C2 c2(val);
        c2.print();
        std::cout << "Pointers count at end of scope: " << val.use_count() << std::endl;
    }

    std::cout << "Pointers count after end of scope: " << val.use_count() << std::endl;
    std::cout << std::endl;
    // => we notice indeed that the pointers are destroyed after end of scope

    // PART C)

    std::shared_ptr<Point> pt(new Point(1.0, 2.0));

    std::cout << "Pointers count before: " << pt.use_count() << std::endl;

    {
        C3 c3(pt);
        c3.print();
        std::cout << "Pointers count at end of scope: " << pt.use_count() << std::endl;
    }

    std::cout << "Pointers count after: " << pt.use_count() << std::endl;
    std::cout << std::endl;
    //=> again, as before, the pointer is destructed at the end of the scope

    // PART D)
    
    // testing features:
    std::shared_ptr<double> val1(new double(1.0));
    // assigning
    std::shared_ptr<double> sp1 = val1;
    // copying
    std::shared_ptr<double> sp2 = std::make_shared<double>(*sp1);

    std::cout << "Pointers count before: " << val1.use_count() << std::endl;

    // comparing
    if (sp1 == sp2) {
        std::cout << "sp1 and sp2 are the same" << std::endl;
    }
    else {
        std::cout << "sp1 and sp2 are not the same" << std::endl;
    }

    // transfering ownership from sp1 to sp2.
    sp2 = std::move(val1);
    std::cout << "Pointers count after ownership transfer: " << val1.use_count() << std::endl;

    // determining if a shared_ptr is the only pointer to a resource
    std::shared_ptr<double> sp3(new double(1.0));
    std::cout << "is sp1 unique: " << (sp1.use_count() > 1) << std::endl;
    std::cout << "is sp2 unique: " << (sp2.use_count() > 1) << std::endl;
    std::cout << "is sp3 unique: " << (sp3.use_count() > 1) << std::endl;

    // swaping sp1 and sp2.
    std::cout << "Pointers count before swap: " << sp1.use_count() << std::endl;
    sp1.swap(sp2);
    std::cout << "Pointers count after swap: " << sp1.use_count() << std::endl;

    // giving up ownership and reinitialise the shared pointer as being empty.
    sp1.reset();
    std::cout << "Pointers count after reset: " << sp1.use_count() << std::endl;

}