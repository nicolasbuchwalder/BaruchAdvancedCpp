#include <iostream>
#include <memory>

class C1 {
private:
    std::shared_ptr<double> d;

public:
    C1(std::shared_ptr<double> value) : d(value) {}
    virtual ~C1() { std::cout << "C1 destructor" << std::endl; }
    void print() const { std::cout << "Value: " << *d << std::endl; }
};

class C2 {
private:
    std::shared_ptr<double> d;

public:
    C2(std::shared_ptr<double> value) : d(value) {}
    virtual ~C2() { std::cout << "C2 destructor" << std::endl; }
    void print() const { std::cout << "Value: " << *d << std::endl; }
};

class Point {
public:
    double x;
    double y;

    Point(double x_, double y_) : x(x_), y(y_) {}
    virtual ~Point() { std::cout << "\nPoint destructor\n"; }
    void print() const { std::cout << "x: " << x << " y: " << y << std::endl; }
};

class C3 {
private:
    std::shared_ptr<Point> pt;

public:
    C3(std::shared_ptr<Point> value) : pt(value) {}
    virtual ~C3() { std::cout << "C3 destructor" << std::endl; }
    void print() const { std::cout << "x: " << pt->x << " y: " << pt->y << std::endl; }
};

int main() {
    std::cout << std::boolalpha;

    // PART A & B)

    std::shared_ptr<double> val(new double(1.0));

    std::cout << "Pointers count before: " << val.use_count() << std::endl;

    {
        C1 c1(val);
        c1.print();

        C2 c2(val);
        c2.print();
        std::cout << "Pointers count at end of scope: " << val.use_count() << std::endl;
    }

    std::cout << "Pointers count after: " << val.use_count() << std::endl;

    std::cout << std::endl;

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

    // PART D)

    std::shared_ptr<double> val1(new double(1.0));
    // assign
    std::shared_ptr<double> sp1 = val1;
    // copy
    std::shared_ptr<double> sp2 = std::make_shared<double>(*sp1);

    std::cout << "Pointers count before: " << val1.use_count() << std::endl;

    // compare
    if (sp1 == sp2) {
        std::cout << "sp1 and sp2 are the same" << std::endl;
    } else {
        std::cout << "sp1 and sp2 are not the same" << std::endl;
    }

    // Transfer ownership from sp1 to sp2.
    sp2 = std::move(val1);
    std::cout << "Pointers count after ownership transfer: " << val1.use_count() << std::endl;

    // Determine if a shared_ptr is the only pointer to a resource
    std::shared_ptr<double> sp3(new double(1.0));
    std::cout << "is sp1 unique: " << sp1.unique() << std::endl;
    std::cout << "is sp2 unique: " << sp2.unique() << std::endl;
    std::cout << "is sp3 unique: " << sp3.unique() << std::endl;

    // Swap sp1 and sp2.
    std::cout << "Pointers count before swap: " << sp1.use_count() << std::endl;
    sp1.swap(sp2);
    std::cout << "Pointers count after swap: " << sp1.use_count() << std::endl;

    // Give up ownership and reinitialise the shared pointer as being empty.
    sp1.reset();
    std::cout << "Pointers count after reset: " << sp1.use_count() << std::endl;

}