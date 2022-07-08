#include <iostream>
#include <bitset>
#include <boost/dynamic_bitset.hpp>

int main() {
    // PART A)

    // two bitsets of the same size
    std::bitset<32> bs1(0x12345678);
    std::bitset<32> bs2(0x87654321);

    // PART B)

    // flip all bits
    bs1.flip();
    bs2.flip();

    // PART C)

    // xor
    std::cout << "XOR: " << (bs1 ^ bs2) << std::endl;
    // or
    std::cout << "OR:  " << (bs1 | bs2) << std::endl;
    // and
    std::cout << "AND: " << (bs1 & bs2) << std::endl;

    // PART D)

    // shift bs1 left by 16 bits
    std::bitset<32> shiftedr_bs1(bs1 >> 16);
    // shift bs1 right by 16 bits
    std::bitset<32> shiftedl_bs1(bs1 << 16);
    // shift bs2 left by 16 bits
    std::bitset<32> shiftedr_bs2(bs2 >> 16);
    // shift bs2 right by 16 bits
    std::bitset<32> shiftedl_bs2(bs2 << 16);

    // PART E)

    // get bs1 hash
    std::cout << "bs1 hash: " << std::hash<std::bitset<32>>{}(bs1) << std::endl;
    // get bs2 hash
    std::cout << "bs2 hash: " << std::hash<std::bitset<32>>{}(bs2) << std::endl;

    // PART F)

    auto blit = 0b0011;
    std::byte b{0b0011}; // Create from a binary literal
    std::bitset<4> bs(blit);
    boost::dynamic_bitset<unsigned int> dbs(4); // all 0 by default
    dbs[1] = dbs[0] = 1;
    std::cout << "byte: " << std::to_integer<int>(b) << std::endl;
    std::cout << "bitset: " << bs << std::endl;
    std::cout << "dynamic bitset: " << dbs << std::endl;

    // PART G)

    // binary literal
    std::byte b1{0b0011};
    // integer
    std::byte b2{244};
    // binary logical operators on existing bytes
    std::byte b3{b1 | b2};

    // PART H)

    // bitwise operations on bytes (AND, OR)
    std::byte b4{b1 & b2};
    std::byte b5{b1 | b2};

    // PART I)
    // left and right shift
    std::byte b6{b4 << 4};
    std::byte b7{b5 >> 4};
    // "extreme" cases
    std::byte b8{b4 << 8};
    std::byte b9{b5 >> 8};

    // PART J)

    // examples/applications where bytes and bitsets can be used:
    // - raw memory access
    // - performance improvements
    // - bitmaps, image processing
    // - cryptography
    // - serialization
    // - networking
}