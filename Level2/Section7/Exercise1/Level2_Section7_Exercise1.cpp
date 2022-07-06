#include <iostream>
#include <fstream>
#include <string>
#include <system_error>
#include <boost/system/error_code.hpp>

// PART A)

boost::system::error_condition readFile(std::string fn) {
    std::ifstream file(fn);

    std::cout << "FILE START" << std::endl;
    std::cout << file.rdbuf() << std::endl;
    std::cout << "FILE END" << std::endl;

    return boost::system::error_condition();
}

// PART B)

boost::system::error_condition readFile2(std::string fn) {
    std::ifstream file(fn);

    if (!file.is_open()) {
        return boost::system::errc::make_error_condition(boost::system::errc::no_such_file_or_directory);
    }

    std::cout << "FILE START" << std::endl;
    std::cout << file.rdbuf() << std::endl;
    std::cout << "FILE END" << std::endl;

    return boost::system::error_condition();
}

// PART D)

std::error_condition readFile3(std::string fn) {
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

    // without checking if file exists
    // with existent file
    readFile("test.txt");
    // with nonexistent file
    // readFile("nothing"); // breaks cout

    // with checking if file exists
    // with existent file
    boost::system::error_condition e1 = readFile2("test.txt");
    // with nonexistent file
    boost::system::error_condition e2 = readFile2("not a file");
    std::cout << "With existing file:    " << e1.message() << std::endl;
    std::cout << "With nonexistent file: " << e2.message() << std::endl;

    // PART D)

    // with existent file
    std::error_condition e3 = readFile3("test.txt");
    // with nonexistent file
    std::error_condition e4 = readFile3("not a file");
    std::cout << "With existing file:    " << e3.message() << std::endl;
    std::cout << "With nonexistent file: " << e4.message() << std::endl;
}