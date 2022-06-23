#include <iostream>
#include <array>

class SomeObject {
public:
    SomeObject() {}
};

int main() {
    std::cout << std::boolalpha;

    // PART A)

    std::cout << "type        is_array" << std::endl;
    // fundamental types
    std::cout << "Fundamental..." << std::endl;
    std::cout << "void:       " << std::is_array<void>::value << std::endl;
    std::cout << "int:        " << std::is_array<int>::value << std::endl;
    std::cout << std::endl;
    // scalar types
    std::cout << "Scalar..." << std::endl;
    std::cout << "char:       " << std::is_array<char>::value << std::endl;
    std::cout << "bool:       " << std::is_array<bool>::value << std::endl;
    std::cout << std::endl;
    // object types
    std::cout << "Object..." << std::endl;
    std::cout << "SomeObject: " << std::is_array<SomeObject>::value << std::endl;
    std::cout << std::endl;
    // arithmetic types
    std::cout << "Arithmetic..." << std::endl;
    std::cout << "float:      " << std::is_array<float>::value << std::endl;
    std::cout << "double:     " << std::is_array<double>::value << std::endl;
    std::cout << "long:       " << std::is_array<long double>::value << std::endl;
    std::cout << std::endl;
    // compound types
    std::cout << "Compound..." << std::endl;
    std::cout << "array:      " << std::is_array<int[]>::value << std::endl;
    std::cout << "std::array: " << std::is_array<std::array<int, 3>>::value << std::endl;
    std::cout << "Pointer:    " << std::is_array<int*>::value << std::endl;
    std::cout << "Reference:  " << std::is_array<int&>::value << std::endl;
    std::cout << std::endl << std::endl;


    std::cout << "Array ranks and extents:" << std::endl;

    // PART B)
    
    std::cout << "With normal array..." << std::endl;
    std::cout << "Rank:       " << std::rank<int[][3][4][5]>::value << std::endl;
    std::cout << "Extent:     " << std::extent<int[][3][4][5]>::value << std::endl;
    std::cout << std::endl;

    // PART C)

    std::cout << "With all extents removed..." << std::endl;
    std::cout << "Rank:       " << std::rank<std::remove_all_extents<int[][3][4][5]>>::value << std::endl;
    std::cout << "Extent:     " << std::extent<std::remove_all_extents<int[][3][4][5]>>::value << std::endl;
}