// Level2_Section8_Exercise2.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <iostream>
#include <bitset>
#include <boost/dynamic_bitset/dynamic_bitset.hpp>


// function to print bytes
std::ostream& operator<< (std::ostream& os, std::byte b) {
	return os << std::bitset<8>(std::to_integer<int>(b));
}

int main()
{
	// PART A)
	std::bitset<3> bs1;
	bs1.set();
	std::bitset<3> bs2;

	// PART B)
	// toggleing all the bits of both sitsets with flip
	bs1.flip();
	bs2.flip();

	// PART C)
	std::cout << "XOR: " << (bs1 ^ bs2) << std::endl;
	std::cout << "OR: " << (bs1 | bs2) << std::endl;
	std::cout << "AND: " << (bs1 & bs2) << std::endl;

	// PART D)
	// left shift operation
	std::bitset<3> bsLeft{ bs1 << 2 };
	// right shift operation
	std::bitset<3> bsRight{ bs1 >> 2 };

	// PART E)
	// creating hashed values
	std::size_t bs1Hash = std::hash<std::bitset<3>>{}(bs1);
	std::size_t bs2Hash = std::hash<std::bitset<3>>{}(bs2);

	// PART F)

	// GIVEN CODE
	auto blit = 0b0011;

	std::byte b{ 0b0011 }; // Create from a binary literal

	std::bitset<4> bs(blit);

	boost::dynamic_bitset<unsigned int> dbs(4); // all 0 by default

	dbs[1] = dbs[0] = 1;

	std::cout << "\nbyte: " << std::to_integer<int>(b) << '\n';

	std::cout << "bitset: " << bs << '\n';

	std::cout << "dynamic bitset: " << dbs << '\n';


	// PART G)
	// 
	// creating byte from binary literal
	std::byte bs3{ 0b101 };
	std::cout << bs3 << std::endl;
	// creating byte from intenger
	std::byte bs4{ 7 };
	std::cout << bs4 << std::endl;
	// creating byte as binary logical operators
	std::byte bs5 = bs3 & bs4;
	std::cout << bs5 << std::endl;

	// PART H)

	std::cout << "OR: " << (bs4 | bs5) << std::endl;
	std::cout << "AND: " << (bs4 & bs5) << std::endl;

	// PART I)

	// left shift operation
	std::byte byteLeft{ bs3 << 2 };
	// right shift operation
	std::byte byteRight{ bs3 >> 8 };
	// => everything will be shifted out of the byte



	// PART J)

	// Bytes and bitsets could be used for example in microinformatics, to represent value of inputs or outputs 
	// and perform operations on them

}