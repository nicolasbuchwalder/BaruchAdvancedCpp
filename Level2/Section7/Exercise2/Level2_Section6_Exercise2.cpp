// Level2_Section6_Exercise2.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <iostream>
#include <tuple>
#include <system_error>

// PART B)

std::tuple<std::string, int, std::string> errorInfo(std::error_condition ec) {
    // error code
    int errorCode = ec.value();
    // error message
    std::string errorMessage = ec.message();
    // error category
    std::string errorCategory = ec.category().name();

    return std::make_tuple(errorMessage, errorCode, errorCategory);
}

int main() {
    // PART A)

    // default constructor
    std::error_condition ea1;
    std::cout << "Default constructor: " << ea1.message() << std::endl;
    // value (stored error code) and error category
    std::error_condition ea2(1, std::generic_category());
    std::cout << "Value and error category: " << ea2.message() << std::endl;
    // based on std::erc code
    std::error_condition ea3(std::errc::no_such_file_or_directory);
    std::cout << "Based on std::erc code: " << ea3.message() << std::endl;

    // PART B)
    // generating the infos tuples for two different error_conditions 
    auto infos1{ errorInfo(ea1) };
    std::cout << std::get<0>(infos1) << ", " << std::get<1>(infos1) << std::endl;

    auto infos3{ errorInfo(ea3) };
    std::cout << std::get<0>(infos3) << ", " << std::get<1>(infos3) << std::endl;
    //=> works well

}