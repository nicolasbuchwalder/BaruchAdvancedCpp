// Level2_Section1_Exercise2.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <iostream>

// template function that directly prints value (called when object is no pointer but scalar)
template <typename T>
void print(const T& t, std::true_type) {
    std::cout << "scalar: " << t << std::endl;
}
// template function prints nothing (called when object is no pointer and no scalar)
template <typename T>
void print(const T& t, std::false_type) {
    std::cout << "not a pointer nor a scalar type " << std::endl;
}

// printing dereferenced pointer (called when object is a pointer)
template <typename T>
void wrapper(const T& t, std::true_type) {
    std::cout << "pointer: " << *t << std::endl;
}

// launching printing template functions (called when object is not a pointer)
template <typename T>
void wrapper(const T& t, std::false_type) {
    print(t, std::is_scalar<T>());
}

// main template function to check value (pointer or not)
template <typename T>
void isPointer(const T& t) {
    wrapper(t, std::is_pointer<T>());
}

int main() {
    int a = 7;
    // pointer
    int* ptr = &a;
    // scalar reference
    int& ref = a;
    // non scalar type
    int arr[2] = { 1, 2 };

    isPointer(ptr);
    isPointer(ref);
    isPointer(arr);
    //=> works as expected
}