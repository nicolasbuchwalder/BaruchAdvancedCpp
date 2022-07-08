#include <iostream>

// PART A)

// map integer type to unsigned integer type
template <typename T>
typename std::make_unsigned<T>::type map_to_unsigned() {
    return std::make_unsigned<T>();
}

// map usigned integer type to integer type
template <typename T>
typename std::make_signed<T>::type map_to_signed() {
    return std::make_signed<T>();
}

// add const specifier to a type
template <typename T>
typename std::add_const<T>::type addConst() {
    return std::add_const<T>::type();
}

// remove const from a type
template <typename T>
typename std::remove_const<T>::type removeConst() {
    return std::remove_const<T>::type();
}

// add pointer to a type
template <typename T>
typename std::add_pointer<T>::type addPointer() {
    return std::add_pointer<T>::type();
}

// remove pointer from a type
template <typename T>
typename std::remove_pointer<T>::type removePointer() {
    return std::remove_pointer<T>::type();
}

// add the volatile pointer from a type
template <typename T>
typename std::add_volatile<T>::type addVolatile() {
    return std::add_volatile<T>::type();
}

// remove the volatile pointer from a type
template <typename T>
typename std::remove_volatile<T>::type removeVolatile() {
    return std::remove_volatile<T>::type();
}

// 

int main() {

}