// Level2_Section7_Exercise5.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <iostream>
#include <fstream>
#include <system_error>

// function that prints the error code, message and category from a std::error code
void errorInfo(std::error_code ec) {
    std::cout << "error code:     " << ec.value() << std::endl;
    std::cout << "error message:  " << ec.message() << std::endl;
    std::cout << "error category: " << ec.category().name() << std::endl;
}

// function that prints the error code, message and category from a std::error category
void errorInfo(std::error_condition ec) {
    std::cout << "error code:     " << ec.value() << std::endl;
    std::cout << "error message:  " << ec.message() << std::endl;
    std::cout << "error category: " << ec.category().name() << std::endl;
}

int main() {
    // GIVEN CODE
    std::ifstream file(std::string("DOESNOTEXIST.txt"));
    try {
        // Set the exception mask of the file stream
        // In this case 1) logical error on I/O operation or
        // 2) read/write error on I/O operation
        file.exceptions(file.failbit | file.badbit);
    }
    catch (const std::ios_base::failure& e) {
        // PART A)
        // checking that error code is in the io enumeration
        if (e.code() == std::io_errc::stream) {
            // creating both error codes and conditions from e.code()
            std::error_code ec1 = std::error_code(e.code());
            std::error_condition ec2 = std::error_condition(ec1.value(), ec1.category());
            errorInfo(ec1);
            errorInfo(ec2);
        }
    }
    catch (...) {
        std::cout << "catch all\n";
    }
}