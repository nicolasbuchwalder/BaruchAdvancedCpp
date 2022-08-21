// Level4_Section2_Exercise7.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

// function to print vector
std::string print(const std::vector<int>& vec) {
	std::string out{ "[" };
	for (int i{ 0 }; i < vec.size(); ++i) {
		out += std::to_string(vec[i]);
		if (i != vec.size() - 1) { out += ", "; };
	}
	return out + "]\n";
}

// function that computes power set
std::vector<std::vector<int>> power_set(const std::vector<int>& vec) {
	// non const copy of vector
	std::vector<int> copy(vec);
	// output
	std::vector<std::vector<int>> out;
	// adding empty set
	out.push_back(std::vector<int>());
	// iterating over all possible number of element in set
	for (int i{ 1 }; i < copy.size(); ++i) {
		// reassigning original vec (makes next_permutation start again)
		copy = vec;
		// looping over all permutations
		do {
			// getting the first i elements of the permutation
			std::vector<int> set{ copy.begin(), copy.begin() + i };
			// sorting it
			std::sort(set.begin(), set.end());
			// adding it to output
			out.push_back(set);
		} while (std::next_permutation(copy.begin(), copy.end()));
	};
	// sorting output for removing duplicates
	std::sort(out.begin(), out.end());
	// removing duplicates due to the way the algorithm is constructed
	auto last = std::unique(out.begin(), out.end());
	out.erase(last, out.end());
	return out;
}

int main() {

	// PART A)

	std::vector<int> S{ 1, -1, 7, 8, 9, 10 };
	std::cout << print(S) << std::endl;

	// reversed vector
	std::reverse(S.begin(), S.end());
	std::vector<int> reversed{ S };
	std::cout << "reversed: " << print(reversed) << std::endl;
	std::reverse(S.begin(), S.end());

	// PART B)

	// rotated vector
	std::rotate(S.begin(), S.begin()+3, S.end());
	std::cout << "rotated: " << print(S) << std::endl;

	// PART C)

	S = { 1, -1, 7, 8, 9, 10 };

	// computing power set
	std::vector<std::vector<int>> powerset{ power_set(S) };
	for (auto& set : powerset) { std::cout << print(set); };
	//=> even if they are not prined in the most optimal order for the human eye, 
	//=> we have all possible sets

	// PART D)

	// moving the elements to the front can also be done with rotate
	std::rotate(S.begin(), S.begin() + 3, S.end());
	std::cout << "moved 8,9, 10 to front: " << print(S) << std::endl;

}