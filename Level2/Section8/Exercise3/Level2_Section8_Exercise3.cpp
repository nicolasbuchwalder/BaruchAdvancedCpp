#include <iostream>
#include <bitset>
#include <string>
#include <boost/dynamic_bitset.hpp>

int main() {
    // PART A)

    // ex. 1
    // TODO  marche pas (bad_alloc), je crois que c'est une question de byte size je vais juste reduire la taille 32 c'est trop grand
    std::cout << "Exercise 1" << std::endl;
    // bitset from unsigned long
    boost::dynamic_bitset<unsigned long> bitset_from_unsigned_long(0x12345678);
    // bitset from unsigned long long
    boost::dynamic_bitset<unsigned long long> bitset_from_unsigned_long_long(0x1234567812345678);

    std::string bit_string = "01010";
    // bitset from full string
    boost::dynamic_bitset<> bitset_from_string(bit_string);
    // bitset from parts of strings based on a start index (2) and the number of bits to use (4)
    boost::dynamic_bitset<> bitset_from_string_parts{bit_string, 2, 4};

    try {
        boost::dynamic_bitset<> bitset_from_string_parts_exception{bit_string, 9};
    } catch (std::out_of_range& e) {
        std::cout << "Out of range error: " << e.what() << std::endl;
    } catch (std::invalid_argument& e) {
        std::cout << "Invalid arguments: " << e.what() << std::endl;
    } catch (...) {
        std::cout << "Unknown exception" << std::endl;
    }
    
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

    // convert a bitset to std::string, unsigned long and unsigned long long
    std::string str_buffer;
    boost::to_string(bitset_from_string, str_buffer);
    std::cout << "Bitset to string:    " << str_buffer << std::endl;
    std::cout << "Bitset to ulong:     " << bitset_from_unsigned_long.to_ulong() << std::endl;
    // no such function 'to_ullong' in 'boost::dynamic_bitset'; to_ulong used instead (it works in this case)
    std::cout << "Bitset to ullong:    " << bitset_from_unsigned_long_long.to_ulong() << std::endl;

    // test if two bitsets are equal or unequal
    boost::dynamic_bitset<> bitset_from_string_equal{bit_string, 2, 4};
    std::cout << "string bitset:       " << (bitset_from_string_equal == bitset_from_string) << std::endl;
    std::cout << "string parts bitset: " << (bitset_from_string_equal == bitset_from_string_parts) << std::endl;

    std::cout << "----------------------------------------------------" << std::endl;

    // ex. 2
    std::cout << "Exercise 2" << std::endl;
    // two bitsets of the same size
    boost::dynamic_bitset<> bs1(1234);
    boost::dynamic_bitset<> bs2(8765);

    // flip all bits
    bs1.flip();
    bs2.flip();

    // xor
    std::cout << "XOR: " << (bs1 ^ bs2) << std::endl;
    // or
    std::cout << "OR:  " << (bs1 | bs2) << std::endl;
    // and
    std::cout << "AND: " << (bs1 & bs2) << std::endl;

    // shift bs1 left by 16 bits
    boost::dynamic_bitset<> shiftedr_bs1(bs1 >> 16);
    // shift bs1 right by 16 bits
    boost::dynamic_bitset<> shiftedl_bs1(bs1 << 16);
    // shift bs2 left by 16 bits
    boost::dynamic_bitset<> shiftedr_bs2(bs2 >> 16);
    // shift bs2 right by 16 bits
    boost::dynamic_bitset<> shiftedl_bs2(bs2 << 16);

    // get bs1 hash
    std::cout << "bs1 hash: " << std::hash<boost::dynamic_bitset<>>{}(bs1) << std::endl;
    // get bs2 hash
    std::cout << "bs2 hash: " << std::hash<boost::dynamic_bitset<>>{}(bs2) << std::endl;

    auto blit = 0b0011;
    std::byte b{0b0011}; // Create from a binary literal
    boost::dynamic_bitset<> bs(blit);
    boost::dynamic_bitset<unsigned int> dbs(4); // all 0 by default
    dbs[1] = dbs[0] = 1;
    std::cout << "byte: " << std::to_integer<int>(b) << std::endl;
    std::cout << "bitset: " << bs << std::endl;
    std::cout << "dynamic bitset: " << dbs << std::endl;

    // binary literal
    std::byte b1{0b0011};
    // integer
    std::byte b2{244};
    // binary logical operators on existing bytes
    std::byte b3{b1 | b2};

    // bitwise operations on bytes (AND, OR)
    std::byte b4{b1 & b2};
    std::byte b5{b1 | b2};

    // left and right shift
    std::byte b6{b4 << 4};
    std::byte b7{b5 >> 4};
    // "extreme" cases
    std::byte b8{b4 << 8};
    std::byte b9{b5 >> 8};

    // PART B)

    // resize
    bs1.resize(10);
    // clear
    bs1.clear();
    // push_back
    bs1.push_back(1);
    // pop_back
    bs1.pop_back();
    // append
    bs1.append(1);

    // PART C)
    // test if a bitset is a subset (or proper subset) of another bitset

}