// Level1_Section1_Exercise1.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course


#include <iostream>
#include <memory>

// PART A) 

// template function to determine if a type is a pointer, null pointer, lvalue reference or rvalue reference
template <typename T>
void checkType(const T& t) {
    if (std::is_pointer<T>::value) {
        std::cout << "This is a pointer" << std::endl;

    }
    else if (std::is_null_pointer<T>::value) {
        std::cout << "This is a null pointer" << std::endl;

    }
    else if (std::is_lvalue_reference<T>::value) {
        std::cout << "This is an lvalue reference" << std::endl;

    }
    else if (std::is_rvalue_reference<T>::value) {
        std::cout << "This is an rvalue reference" << std::endl;

    }
    else {
        std::cout << "This is not a pointer, null pointer, lvalue reference nor an rvalue reference" << std::endl;
    };
};


// PART B)

// template function to determine if a type is a member function pointer or if it is a pointer to a non-static member object
template <typename T>
void checkMember(const T& t) {
    if (std::is_member_function_pointer<T>::value) {
        std::cout << "This is a pointer to a non-static member object" << std::endl;
    }
    else {
        std::cout << "This is a pointer to a static member object" << std::endl;
    };
};


// class for testing checkMember template function
class TestClass {
public:
    // member function
    int f() { return 1; };
    // member function pointer
    int (TestClass::* x)();
};


// PART C) 

// GIVEN CODE
template <typename T>
void isPointer(const T& t)
{
    // First example of type_traits;check if t is a pointer
    // Return type is std::true_type or std::false_type

    if (std::is_pointer<T>::value)
    {
        std::cout << "This is a pointer type argument\n";
    }
    else
    {
        std::cout << "This is _not_ a pointer type argument\n";
    };
};



int main() {
    // PART A)

    // pointer
    int a = 0;
    int* ptr {&a};

    // lvalue and rvalue refs
    int lvalue = 0;
    int&& rvalue = 0;

    // pointer
    checkType(ptr);
    // null pointer
    checkType(nullptr);
    // lvalue reference
    checkType<int&>(lvalue);
    // lvalue reference
    checkType<int&&>(rvalue);
    // integer
    checkType<int>(3);
    std::cout << std::endl;
    // => the function detects correctly

    // PART B)

    // static pointer
    int b = 0;
    static int* static_ptr{ &b };
  
    // pointer to member function
    TestClass tc;
    tc.x = &TestClass::f;

    checkMember(static_ptr);
    checkMember(tc.x);
    std::cout << std::endl;
    //=> detection works proprely as well

    // PART C)

    // shared pointer
    int c = 0;
    std::shared_ptr<int> sp(new int(c));
    isPointer(sp);

    // raw pointer
    int* raw_ptr = sp.get();
    isPointer(raw_ptr);
    //=> we see that a shared pointer is not detected as a pointer by the type traits
}