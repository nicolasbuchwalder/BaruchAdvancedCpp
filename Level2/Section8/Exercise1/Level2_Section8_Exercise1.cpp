#include <iostream>
#include <bitset>
#include <boost/dynamic_bitset.hpp>

int main() {
    std::cout << std::boolalpha;

    // PART A)
    // bitset from unsigned long
    std::bitset<32> bitset_from_unsigned_long(0x12345678);
    // bitset from unsigned long long
    std::bitset<64> bitset_from_unsigned_long_long(0x1234567812345678);

    // PART B)
    std::string bit_string = "01010";
    // bitset from full string
    std::bitset<8> bitset_from_string(bit_string);
    // bitset from parts of strings based on a start index (2) and the number of bits to use (4)
    std::bitset<8> bitset_from_string_parts{bit_string, 2, 4};

    // PART C)
    try {
        std::bitset<8> bitset_from_string_parts_exception{bit_string, 9};
    } catch (std::out_of_range& e) {
        std::cout << "Out of range error: " << e.what() << std::endl;
    } catch (std::invalid_argument& e) {
        std::cout << "Invalid arguments: " << e.what() << std::endl;
    } catch (...) {
        std::cout << "Unknown exception" << std::endl;
    }

    // PART D)
    
    // set all bits
    bitset_from_unsigned_long.set();
    // reset all bits
    bitset_from_unsigned_long_long.reset();
    // flip the bits
    bitset_from_string.flip();
    // test if none, all or any bits are set
    std::cout << "None bits are set:   " << bitset_from_string.none() << std::endl;
    std::cout << "All bits are set:    " << bitset_from_string.all() << std::endl;
    std::cout << "Any bits are set:    " << bitset_from_string.any() << std::endl;
    // access the elements
    std::cout << "Element 0:           " << bitset_from_string[0] << std::endl;
    std::cout << "Element 1:           " << bitset_from_string[1] << std::endl;
    // count of set bits
    std::cout << "Number of set bits:  " << bitset_from_string.count() << std::endl;

    // PART E)
    // convert a bitset to std::string, unsigned long and unsigned long long
    std::cout << "Bitset to string:    " << bitset_from_string.to_string() << std::endl;
    std::cout << "Bitset to ulong:     " << bitset_from_unsigned_long.to_ulong() << std::endl;
    std::cout << "Bitset to ullong:    " << bitset_from_unsigned_long_long.to_ullong() << std::endl;

    // PART F)
    // test if two bitsets are equal or unequal
    std::bitset<8> bitset_from_string_equal{bit_string, 2, 4};
    std::cout << "string bitset:       " << (bitset_from_string_equal == bitset_from_string) << std::endl;
    std::cout << "string parts bitset: " << (bitset_from_string_equal == bitset_from_string_parts) << std::endl;
}