#include <iostream>
#include <memory>

// PART A) Funciton to determine if a type is a pointer, null pointer, lvalue reference or rvalue reference

template <typename T>
void checkType(const T& t) {
    if (std::is_pointer<T>::value) {
        std::cout << "T is a pointer" << std::endl;

    } else if (std::is_null_pointer<T>::value) {
        std::cout << "T is a null pointer" << std::endl;

    } else if (std::is_lvalue_reference<T>::value) {
        std::cout << "T is an lvalue reference" << std::endl;

    } else if (std::is_rvalue_reference<T>::value) {
        std::cout << "T is an rvalue reference" << std::endl;

    } else {
        std::cout << "T is not a pointer, null pointer, lvalue reference nor an rvalue reference" << std::endl;
    }
}


// PART B) Function to determine if a type is a member function pointer or if it is a pointer to a non-static member object.

template <typename T>
void checkMember(const T& t) {
    if (std::is_member_function_pointer<T>::value) {
        std::cout << "T is a pointer to a non-static member object" << std::endl;

    } else {
        std::cout << "T is a pointer to a static member object" << std::endl;
    }
}

class TestClass {
public:
    int f();
    int (TestClass::*x)();
};

int TestClass::f() {
    return 1;
}

// PART C) Is a shared pointer a pointer type? Is it a pointer type when converted to a raw pointer?

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
        std::cout << "_not_ a pointer type argument\n";
    }
}


// Tests

int main() {
    // PART A)

    // pointer
    int a = 0;
    int *ptr;
    ptr = &a;

    // lvalue and rvalue refs
    int lvalue = 0;
    int &&rvalue = 0;

    // pointer
    checkType(ptr);
    // null pointer
    checkType(nullptr);
    // lvalue reference
    checkType<int&>(lvalue);
    // lvalue reference
    checkType<int&&>(rvalue);
    
    std::cout << std::endl;

    // PART B)

    // static
    int b = 0;
    static int* static_ptr;
    static_ptr = &b;
    // pointer to member function
    TestClass tc;
    tc.x = &TestClass::f;

    checkMember(static_ptr);
    checkMember(tc.x);

    std::cout << std::endl;

    // PART C)

    // shared pointer
    int c = 0;
    std::shared_ptr<int> sp(new int(c));
    isPointer(sp);

    // raw pointer
    int *raw_ptr = sp.get();
    isPointer(raw_ptr);
}