// Level2_Section7_Exercise4.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <iostream>
#include <tuple>
#include <system_error>

// PART B)
using erroInfoTuple = std::tuple<std::string, int, std::string>;

// function that returns information pertaining to instances of std::error_code
erroInfoTuple errorInfo(std::error_code ec) {
    // error code
    int errorCode = ec.value();
    // error message
    std::string errorMessage = ec.message();
    // error category
    std::string errorCategory = ec.category().name();

    return std::make_tuple(errorMessage, errorCode, errorCategory);
}

int main() {

    std::cout << std::boolalpha;
    // PART A)
    // default error code
    std::error_code ec1;
    // error code with a platform-dependent error code value and an error category.
    std::error_code ec2(1, std::generic_category());

    // PART B)
    erroInfoTuple infos1 {errorInfo(ec1)};
    std::cout << std::get<0>(infos1) << ", " << std::get<1>(infos1) << ", " << std::get<2>(infos1) << std::endl;

    erroInfoTuple infos2{ errorInfo(ec2) };
    std::cout << std::get<0>(infos2) << ", " << std::get<1>(infos2) << ", " << std::get<2>(infos2) << std::endl;

    // PART C)
    // test equality of instances of std::error_code and std::error_condition using operators == and !=
    std::error_code ec3(0, std::generic_category());
    std::error_condition ec4(std::errc::no_such_file_or_directory);

    // checkin equality, inequality
    std::cout << "ec1 == ec2: " << (ec1 == ec2) << std::endl;
    std::cout << "ec1 == ec3: " << (ec1 == ec3) << std::endl;
    std::cout << "ec3 != ec4: " << (ec3 != ec4) << std::endl;
    // => works
}