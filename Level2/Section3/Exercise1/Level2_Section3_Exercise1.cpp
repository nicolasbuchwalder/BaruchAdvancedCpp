// Level2_Section3_Exercise2.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <iostream>


// deprecated free function
[[deprecated("Deprecated function")]] void deprecatedFunction() {
    std::cout << "Hello, World 0" << std::endl;
}

// deprecated class with deprecated member function
class [[deprecated("Deprecated class")]] DeprecatedClass {
public:
    DeprecatedClass() {}
    [[deprecated("Deprecated member")]] void deprecatedMember() {
        std::cout << "Hello, World 1" << std::endl;
    };
};

// non deprecated class with deprecated member function
class NonDeprecatedClass {
public:
    NonDeprecatedClass() {}
    [[deprecated("Deprecated member")]] void deprecatedMember() {
        std::cout << "Hello, World 2" << std::endl;
    };
};


// deprecated global variable
[[deprecated("Deprecated global variable")]]
int deprecatedGlobal = 0;

// deprecated enum
enum [[deprecated("Deprecated enum")]] DeprecatedEnum {
    VALUE1,
    VALUE2
};

// deprecated enumclass
enum class [[deprecated("Deprecated enum class")]] DeprecatedEnumClass {
    VALUE1,
    VALUE2
};

// deprecated template specialization
template <typename T>
class DeprecatedTemplateSpecialization {};
template <>
class [[deprecated("Deprecated template specialization")]] DeprecatedTemplateSpecialization<int> {};

// deprecated lambda function
[[deprecated("Deprecated lambda")]] auto deprecatedLambda = [](int x) {
    return x;
};

int main() {
    // testing all depracated
    // everything commented out as it throws exceptions
    // 
    //deprecatedFunction();
    // 
    //DeprecatedClass dc;
    //dc.deprecatedMember();
    NonDeprecatedClass ndc;
    // => does not throw error
    // 
    //ndc.deprecatedMember();
    //std::cout << deprecatedGlobal << std::endl;
    //DeprecatedEnum value1 = VALUE1;
    //DeprecatedEnumClass value2 = DeprecatedEnumClass::VALUE2;
    //DeprecatedTemplateSpecialization<int> dts;
    //std::cout << deprecatedLambda(0) << std::endl;
}