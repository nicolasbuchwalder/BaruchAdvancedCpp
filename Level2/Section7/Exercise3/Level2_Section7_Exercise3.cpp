#include <iostream>
#include <system_error>

int main() {
    // PART A)

    // io_error.
    std::error_condition c1 = std::error_condition(std::errc::io_error);
    std::cout << "io_error:                  " << c1.message() << std::endl;
    // network_unreachable.
    std::error_condition c2 = std::error_condition(std::errc::network_unreachable);
    std::cout << "network_unreachable:       " << c2.message() << std::endl;
    // no_such_file_or_directory.
    std::error_condition c3 = std::error_condition(std::errc::no_such_file_or_directory);
    std::cout << "no_such_file_or_directory: " << c3.message() << std::endl;
    // not_a_socket.
    std::error_condition c4 = std::error_condition(std::errc::not_a_socket);
    std::cout << "not_a_socket:              " << c4.message() << std::endl;
    // permission_denied.
    std::error_condition c5 = std::error_condition(std::errc::permission_denied);
    std::cout << "permission_denied:         " << c5.message() << std::endl;

    // PART B)

    std::error_condition ec1(128, std::generic_category());
    std::cout << "128:                       " << ec1.message() << std::endl;

    // PART C)

    // Use std::make_error_condition (with std::io_errc as argument) to create an instance of std::error_condition.
    std::error_condition ec2 = std::make_error_condition(std::io_errc::stream);
    std::cout << "io_errc stream:            " << ec2.message() << std::endl;
}