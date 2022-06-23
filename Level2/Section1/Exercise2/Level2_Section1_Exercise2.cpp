#include <iostream>

// directly print value if passed true (is_scalar)
template <typename T>
void print(const T& t, std::true_type) {
    std::cout << "scalar: " << t << std::endl;
}

template <typename T>
void print(const T& t, std::false_type) {
    std::cout << "not a pointer nor a scalar type " << std::endl;
}

// print dereferenced pointer if passed true
template <typename T>
void wrapper(const T& t, std::true_type) {
    std::cout << "pointer: " << *t << std::endl;
}

// check scalar if passed false, print if true
template <typename T>
void wrapper(const T& t, std::false_type) {
    print(t, std::is_scalar<T>());
}

// call wrapper with is_pointer output
template <typename T>
void isPointer(const T& t) {
    wrapper(t, std::is_pointer<T>());
}

int main() {
    int a = 0;
    // pointer
    int *ptr = &a;
    // scalar reference
    int &ref = a;
    // non scalar type
    int arr[2] = {1, 2};

    isPointer(ptr);
    isPointer(ref);
    isPointer(arr);
} 