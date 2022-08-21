// Level4_Section1_Exercise4.cpp: This file contains the main functions for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include "Proposition.h"
#include "Matrix.h"

#include <iostream>
#include <string>

// GIVE CODE
using value_type = Proposition;

template <int NR, int NC>
using BitMap = Matrix<value_type, NR, NC>;

template <int NR, int NC>
using BitMap2 = std::array<std::bitset<NC>, NR>;


// function to print BitMap2
template <int NR, int NC>
void print(const BitMap2<NR, NC>& bm) {
	std::cout << "[";
	for (int i{ 0 }; i < NR; ++i) {
		if (i != 0) { std::cout << " "; };
		std::cout << "[ ";
		for (int j{ 0 }; j < NC; ++j) {
			std::cout << bm[i].test(j) << " ";
		}
		std::cout << "]";
		if (i != NR - 1) { std::cout << std::endl; };
	}
	std::cout << "]" << std::endl;
}

// PART B)

// (GIVEN) function wrapper for two grids of bitmaps
using BitFunction = std::function < Proposition(const Proposition&, const Proposition&) >;

// function to return bitmap where element wise operation has been performed
template <int NR, int NC>
BitMap<NR, NC> mask(const BitMap<NR, NC>& bm1, const BitMap<NR, NC>& bm2, const BitFunction& masker) {
	BitMap<NR, NC> out;
	// simply looping through all elements and applying the masker function  
	for (int i{ 0 }; i < NR; ++i) {
		for (int j{ 0 }; j < NC; ++j) {
			out[i][j] = masker(bm1[i][j], bm2[i][j]);
		}
	};
	return out;
}

// PART C)

// function to initialize BitMap2 row from string
template <int NR, int NC>
void initialise(BitMap2<NR, NC>& bm, int row, std::string bits) {
	bm[row] = bits;
};


int main() {

	// PART A)

	// instances of BitMap and BitMap2

	const BitMap<3, 3> bitmap;
	std::cout << bitmap << std::endl << std::endl;

	BitMap2<3, 3> bitmap2;
	print(bitmap2);

	// PART B)

	// GIVEN CODE
	BitMap<5, 5> bm(true);
	bm[4][3] = false;

	BitMap<5, 5> bm2(true);
	bm2[3][4] = false;

	// and (we need to unconst p1 to do the operation, so we do a temp)
	auto AND = [](const Proposition& p1, const Proposition& p2) {
		Proposition tmp{ p1 };
		return tmp & p2;
	};
	auto bmA = mask(bm, bm2, AND);
	std::cout << "and: " << std::endl << bmA << std::endl;


	// or
	auto OR = [](const Proposition& p1, const Proposition& p2) {
		Proposition tmp{ p1 };
		return tmp | p2;
	};
	auto bmB = mask(bm, bm2, OR);
	std::cout << "or: " << std::endl << bmB << std::endl;


	// xor
	auto XOR = [](const Proposition& p1, const Proposition& p2) {
		Proposition tmp{ p1 };
		return tmp ^ p2;
	};
	auto bmC = mask(bm, bm2, XOR);
	std::cout << "xor: " << std::endl << bmC << std::endl;


	// cond
	auto COND = [](const Proposition& p1, const Proposition& p2){ return p1 % p2; };
	auto bmD = mask(bm, bm2, COND);
	std::cout << "cond: " << std::endl << bmD << std::endl;

	// bicond
	auto BICOND = [](const Proposition& p1, const Proposition& p2) { return p1 %= p2; };
	auto bmE = mask(bm, bm2, BICOND);
	std::cout << "bicond: " << std::endl << bmE << std::endl;

	// all operations seem to work proprely

	// PART C)

	const int P = 8;
	const int Q = 8;
	BitMap2<P, Q> bitblt2;
	initialise(bitblt2, 0, std::string("01111100"));
	initialise(bitblt2, 1, std::string("00111110"));
	initialise(bitblt2, 2, std::string("00011111"));
	initialise(bitblt2, 3, std::string("10001111"));
	initialise(bitblt2, 4, std::string("11000111"));
	initialise(bitblt2, 5, std::string("11100011"));
	initialise(bitblt2, 6, std::string("11110001"));
	initialise(bitblt2, 7, std::string("11111000"));
	
	// => this would take extremely long with BitMap
}