// Level2_Section2_Exercise2.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <iostream>

// PART A)
template <typename T>
void toggleUnsigned(T& t, std::true_type) {
    typedef typename std::make_unsigned<T>::type u;
}

int main() {
    int i = -1;
    toggleUnsigned(i, std::is_signed<int>());

}