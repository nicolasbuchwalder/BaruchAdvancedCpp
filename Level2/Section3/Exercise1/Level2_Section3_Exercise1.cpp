#include <iostream>

// PART A)

// depr function
[[deprecated("Deprecated function")]] void deprecatedFunction() {
    std::cout << "Hello, World 0" << std::endl;
}

// depr class with depr member
class [[deprecated("Deprecated class")]] DeprecatedClass {
public:
    DeprecatedClass() {}
    void deprecatedMember();
};

// depr member
[[deprecated("Deprecated member")]] void DeprecatedClass::deprecatedMember() {
    std::cout << "Hello, World 1" << std::endl;
}

// non depr class
class NonDeprecatedClass {
public:
    NonDeprecatedClass() {}
    void deprecatedMember();
};

// depr member
[[deprecated("Deprecated member")]] void NonDeprecatedClass::deprecatedMember() {
    std::cout << "Hello, World 2" << std::endl;
}

// depr global
[[deprecated("Deprecated global")]]
int deprecatedGlobal = 0;

// depr enum
enum [[deprecated("Deprecated enum")]] DeprecatedEnum {
    VALUE1,
    VALUE2
};

// depr enum class
enum class [[deprecated("Deprecated enum class")]] DeprecatedEnumClass {
    VALUE1,
    VALUE2
};

// depr template specialization
template <typename T>
class DeprecatedTemplateSpecialization {};
template <>
class [[deprecated("Deprecated template specialization")]] DeprecatedTemplateSpecialization<int> {};

// depr lambda function
[[deprecated("Deprecated lambda")]] auto deprecatedLambda = [](int x) {
    return x;
};

int main() {
    // tests
    // depr function
    deprecatedFunction();
    // depr class with depr member
    DeprecatedClass dc;
    dc.deprecatedMember();
    // non depr class
    NonDeprecatedClass ndc;
    ndc.deprecatedMember();
    // depr global
    std::cout << deprecatedGlobal << std::endl;
    // depr enum
    DeprecatedEnum value1 = VALUE1;
    // depr enum class
    DeprecatedEnumClass value2 = DeprecatedEnumClass::VALUE2;
    // depr template specialization
    DeprecatedTemplateSpecialization<int> dts;
    // depr lambda function
    std::cout << deprecatedLambda(0) << std::endl;
}