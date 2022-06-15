#include "C.hpp"

#include <vector>
#include <iostream>

int main()
{
    // PART B)
    std::vector<double> initvec {1.0, 1.41, 3.14, 2.71, 10.0};

    C<std::vector<double>> class1;
    class1(initvec);
    class1.print();

    C<std::vector<double>> class2(class1);
    class2.print();
    class1.print();
    // => we notice that copy constructor has been called and that class1 vector is still there

    C<std::vector<double>> class3(std::move(class1));
    class3.print();
    class1.print();
    // => we notice that move copy constructor has been called and that class1 vector is also still there (we take the rvalue of std::move())
    // => we make sure that the move constructor is called by putting std::move as argument (and rvalue reference && in the function declaration)

    // PART C)

    C<std::vector<double>> class4(class1);
    // => the normal copy constructor is called instead of the move contructor
    // => if we remove the normal contructor, we get: 
    //      copy constructor is implicitly deleted because 'C<std::__1::vector<double>>' has a user-declared move constructor
    // => very readable error that will induce the user to use move


}