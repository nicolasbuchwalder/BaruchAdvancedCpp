#include <iostream>
#include <memory>
#include <list>

// Base class
class Base
{
private:
public:
    Base() { }
    virtual void print() const = 0;
protected:
    virtual ~Base() { std::cout << "Base destructor\n\n"; }
};

// Derived class
class Derived : public Base
{
private:
public:
    Derived() : Base() { }
    ~Derived() { std::cout << "Derived destructor" << std::endl; }
    void print() const { std::cout << "Print derived object" << std::endl;}
};

// PART B)
// factory function to create instances of Derived and then add them to the list.
std::shared_ptr<Base> create_derived()
{
    std::shared_ptr<Base> ptr(new Derived());
    return ptr;
}

int main() {
    // PART A)

    // list of smart pointers to Base. In particular, both shared and unique pointers.
    std::list<std::shared_ptr<Base>> baseListShared(1); // compiles
    // std::list<std::unique_ptr<Base>> baseListUnique(1); // compile error

    // PART C)

    // test create_derive and check for memory leaks
    std::shared_ptr<Base> derived = create_derived();
    derived->print();
    std::cout << "Pointers count: " << derived.use_count() << std::endl;
    derived.reset();
    std::cout << "Pointers count: " << derived.use_count() << std::endl;

}