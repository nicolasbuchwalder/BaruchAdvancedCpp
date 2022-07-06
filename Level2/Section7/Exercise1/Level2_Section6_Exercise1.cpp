// Level2_Section6_Exercise1.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <iostream>
#include <fstream>
#include <string>
#include <system_error>
#include <boost/system/error_code.hpp>

// PART A)
// function to read file given the path file, does not look if file exists (will fail if it doesn't)
boost::system::error_condition readFile(std::string fn) {
    std::ifstream file(fn);

    std::cout << "FILE START" << std::endl;
    // reading the file
    std::cout << file.rdbuf() << std::endl;
    std::cout << "FILE END" << std::endl;
    // returning no error
    return boost::system::error_condition();
}

// PART B)
// same function as before but with checking if file exists
boost::system::error_condition readFileWithCheckBoost(std::string fn) {
    std::ifstream file(fn);
    // checking if file does not exist
    // if so, returning error that no such file or directory exists
    if (!file.is_open()) {
        return boost::system::errc::make_error_condition(boost::system::errc::no_such_file_or_directory);
    }
    // else everything as before
    std::cout << "FILE START" << std::endl;
    std::cout << file.rdbuf() << std::endl;
    std::cout << "FILE END" << std::endl;

    return boost::system::error_condition();
}

// PART D)
// same thing but using c++ 11 instead of boost
std::error_condition readFileWithCheckStd(std::string fn) {
    std::ifstream file(fn);

    if (!file.is_open()) {
        return std::make_error_condition(std::errc::no_such_file_or_directory);
    }

    std::cout << "FILE START" << std::endl;
    std::cout << file.rdbuf() << std::endl;
    std::cout << "FILE END" << std::endl;

    return std::error_condition();
}

int main() {
    // PART C)

    // function that does not check if file exists
    // with existant file
    readFile("file.txt");
    // with nonexistent file
    // readFile("nothing");
    // => fails 

    // function that does check if file exists (boost one)
    // with existent file
    boost::system::error_condition e1 = readFileWithCheckBoost("file.txt");
    std::cout << "With existing file:    " << e1.message() << std::endl;
    // with nonexistent file
    boost::system::error_condition e2 = readFileWithCheckBoost("not a file");
    std::cout << "With nonexistent file: " << e2.message() << std::endl;
    // => now works

    // PART D)

    // with existent file
    std::error_condition e3 = readFileWithCheckStd("file.txt");
    std::cout << "With existing file:    " << e3.message() << std::endl;
    // with nonexistent file
    std::error_condition e4 = readFileWithCheckStd("not a file");
    std::cout << "With nonexistent file: " << e4.message() << std::endl;

    // => works with std as well (no error becomes success)
}