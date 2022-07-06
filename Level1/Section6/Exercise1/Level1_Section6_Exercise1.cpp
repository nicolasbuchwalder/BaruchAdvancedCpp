// Level1_Section6_Exercise1.cpp: This file contains all the code for this exercise. @Nicolas Buchwalder

#include <iostream>
#include <memory>

// PART A)
struct Base
{
    virtual void draw() { std::cout << "print a base\n"; };
    void print() {};
    ~Base() { std::cout << "bye base\n"; };
};

// had to remove the final keyword as a class with final keyword cannot have a derived class
struct Derived : public Base
{
    Derived() {};
    void draw() override { std::cout << "print a derived\n"; };
    // no need to override again as already overriden above
    void draw() const  {};
    // no changes have been made in the print function from the base class definition => we can remove it
    //void print() override {};
    ~Derived() { std::cout << "bye derived\n"; };
};


class Derived2 : public Derived
{

};

int main() {
    std::shared_ptr<Base> basePtr{ new Base() };
    std::shared_ptr<Base> derivedPtr{ new Derived };

    basePtr->draw();
    //=> behaves as expected
    derivedPtr->draw();
    //=> we notice that even if we use a shared pointer using base, we get the correct function
};