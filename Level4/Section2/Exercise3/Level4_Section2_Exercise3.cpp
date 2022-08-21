// Level4_Section2_Exercise3.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <string>
#include <iostream>


std::random_device rd;
std::mt19937 gen(rd());


// function to print vector
template <typename T>
std::string print(const std::vector<T> vec) {
	std::string out;
	out += "[ ";
	for (int i{ 0 }; i < vec.size(); ++i) {
		out += std::to_string(vec[i]);
		if (i != vec.size() - 1) { out += ", "; };
	};
	out += " ]";
	return out;
}

// PART L)
int genfunction() {
	std::uniform_int_distribution<> distribution(1, 10);
	return distribution(gen);

};


int main() {

	std::vector<int> vec{ 1, 2, 3, 4, 5, 6, 7 };
	std::cout << "init vector: " << print(vec) << std::endl;

	// PART A) 

	// scaling by number
	std::transform(vec.begin(), vec.end(), vec.begin(), [](int i) {return 2 * i; });
	std::cout << "after scaling: " << print(vec) << std::endl;
	vec = { 1, 2, 3, 4, 5, 6, 7 };

	// PART B)

	// counter number of values in a certain range
	int countif = std::count_if(vec.begin(), vec.end(), [](int i) {return (i > 2) && (i < 4); });
	std::cout << "number of values in range 2,4 (excluded): " << countif << std::endl;

	// PART C)

	// average
	int avg = std::accumulate(vec.begin(), vec.end(), 0) / vec.size();
	std::cout << "average: " << avg << std::endl;

	// minimum
	int min = *std::min_element(vec.begin(), vec.end());
	std::cout << "minumum: " << min << std::endl;

	// maximum 
	int max = *std::max_element(vec.begin(), vec.end());
	std::cout << "maximum: " << max << std::endl;

	// PART D)

	// first element in range
	auto firstrange = std::find_if(vec.begin(), vec.end(), [](int i) {return (i > 2) && (i < 4); });
	std::cout << "place of first element between 2 and 4 (excluded): " << std::distance(vec.begin(), firstrange) << std::endl;

	// first element outisde range
	auto firstnotrange = std::find_if(vec.begin(), vec.end(), [](int i) {return (i < 2) || (i > 4); });
	std::cout << "place of first element NOT between 2 and 4 (excluded): " << std::distance(vec.begin(), firstnotrange) << std::endl;

	// PART E)

	std::vector<int> subvec{ 3,4,5,6 };

	// search for all occurences of sub 3,4,5,6

	auto start = vec.begin();
	for (std::vector<int>::iterator it; (it = std::search(start, vec.end(), subvec.begin(), subvec.end())) != vec.end();) {
		std::cout << "occurance of 3456 at: " << std::distance(vec.begin(), it) << std::endl;
		start = it + 1;
	};

	// PART F)

	// checking if two elements in two ranges are equal

	bool rangesequal = std::equal(vec.begin() + 2, vec.end() - 1, subvec.begin());
	std::cout << "two elements in range equal: " << std::boolalpha << rangesequal << std::endl;

	// PART G)

	std::vector<int> permuted_vec{ 7,6,5,4,3,2,1 };

	// vector some permutation of another
	bool ispermutation = std::is_permutation(vec.begin(), vec.end(), permuted_vec.begin());
	std::cout << "is permutation: " << std::boolalpha << ispermutation << std::endl;

	// PART H)

	// vector already sorted
	bool issorted = std::is_sorted(vec.begin(), vec.end());
	std::cout << "vector is sorted: " << std::boolalpha << issorted << std::endl;

	// PART I)

	// copy a vector into another one
	std::copy(subvec.begin(), subvec.end(), vec.begin());
	std::cout << "vector aftercopying 3456 at the front: " << print(vec) << std::endl;

	// PART J)

	// move last 5 elements in the front
	std::rotate(vec.begin(), vec.begin() + (vec.size() - 5), vec.end());
	std::cout << "vector rotated with last elements in the front: " << print(vec) << std::endl;

	// PART K)

	// swap two given ranges at position
	std::swap_ranges(subvec.begin(), subvec.begin() + 3, vec.begin());


	// PART L)

	std::vector<int> newvec(10);
	// generate values based on formula
	int n{ 0 };
	std::generate_n(newvec.begin(), 10, std::ref(genfunction));
	std::cout << "generated vector randomly between 1 and 10 : " << print(newvec) << std::endl;


	// PART M)

	// replace all uneven numbers by zero
	std::replace_if(newvec.begin(), newvec.end(), [](int i) {return i % 2 == 0; }, 0);
	std::cout << "replaced uneven numbers by zero : " << print(newvec) << std::endl;

	// PART N)

	// remove elements whose value is less than 3
	std::remove_if(newvec.begin(), newvec.end(), [](int i) {return i < 3; });
	std::cout << "removed elements with value less then 3 : " << print(newvec) << std::endl;

	// PART O)

	// shuffle a container randomly
	std::shuffle(newvec.begin(), newvec.end(), gen);
	std::cout << "shuffled vector : " << print(newvec) << std::endl;

	// PART P)

	vec = { 1,4,2,7,-4 };
	// sroting the result
	std::vector<int> div_diff{ vec.begin(), vec.end() - 1 };

	auto div_diff_function = [](const int& before, const int& after) {
		if (before != 0){ return (after - before) / before; }
		else {
			if (after > 0) { return std::numeric_limits<int>::max(); }
			else { return std::numeric_limits<int>::min(); };
		}
	};
	
	// one sided divided difference
	std::transform(vec.begin() + 1, vec.end(), vec.begin(), div_diff.begin(), div_diff_function);
	std::cout << "divided difference of vector : " << print(div_diff) << std::endl;


	


}