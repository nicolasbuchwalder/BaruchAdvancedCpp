// Level4_Section2_Exercise4.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <vector>
#include <tuple>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>

// PART A)

//  function that returns the frequency of each element of int vector
std::vector<std::pair<int, int>> count_frequency(const std::vector<int>& vec) {
	std::vector<std::pair<int, int>> res;
	// going over all elements in the vector
	for (int elem : vec) {
		// checking if element exists in the frequency pair
		auto pos = std::find_if(res.begin(), res.end(), [&elem](auto& existing) {return existing.first == elem; });
		// if it exists, then simply add one to the frequency of element
		if (pos != res.end()) {
			(*pos).second++;
		}
		// otherwise create a new element in the frequency pair with frequency 1
		else {
			res.push_back(std::make_pair(elem, 1));
		};
	};
	return res;
};

// function to print value of frequency
void print_freqs(std::vector<std::pair<int, int>> freqs) {
	for (auto& freq : freqs) {
		std::cout << "{" << freq.first << ": " << freq.second << "}, ";
	};
	std::cout << std::endl;
};

// PART B)

// function to compute min, max, sum and average of int vector
std::tuple<int, int, int, int> statistics(const std::vector<int>& vec) {
	return std::make_tuple(
		*std::min_element(vec.begin(), vec.end()),
		*std::max_element(vec.begin(), vec.end()),
		std::accumulate(vec.begin(), vec.end(), 0),
		std::accumulate(vec.begin(), vec.end(), 0) / vec.size());
};

// function to print statistics
void print_stats(std::tuple<int, int, int, int> stats) {
	std::cout << "{" << std::get<0>(stats) << ", "
		<< std::get<1>(stats) << ", "
		<< std::get<2>(stats) << ", "
		<< std::get<3>(stats) << "}" << std::endl;
};

// PART C)


int main() {

	// PART A)

	std::vector<int> vec{ 1,2,3,4,1,1,1 };
	print_freqs(count_frequency(vec));

	// PART B)

	print_stats(statistics(vec));

	// PART C)
	
	vec = { 1,2,-3,4,5,5,5,6 };

	// STL algo to find first occurance of 5
	std::cout << std::distance(
		vec.begin(), 
		std::find(vec.begin(), vec.end(), 5)) 
		<< std::endl;

	// using bind2nd
	std::cout << std::distance(
		vec.begin(),
		std::find_if(vec.begin(), vec.end(), std::bind2nd(std::equal_to<int>(), 5))) 
		<< std::endl;

	// using bind
	std::cout << std::distance(
		vec.begin(),
		std::find_if(vec.begin(), vec.end(), std::bind(std::equal_to<int>(), std::placeholders::_1,  5)))
		<< std::endl;

	// using lambda
	std::cout << std::distance(
		vec.begin(),
		std::find_if(vec.begin(), vec.end(), [](int i) {return i == 5; }))
		<< std::endl;

	// PART D)

	vec = { 1,2,5,5,-3,4,5,5,5,6,3,4,5 };

	// first three consecutive elements having the value 5
	std::cout << std::distance(
		vec.begin(), 
		std::search_n(vec.begin(), vec.end(), 3, 5))
		<< std::endl;

	// first element of the first subrange matching 3,4,5
	std::vector<int> subrange{ 3,4,5 };
	std::cout << std::distance(
		vec.begin(), 
		std::search(vec.begin(), vec.end(), subrange.begin(), subrange.end())) 
		<< std::endl;

	// first element of the last subrange matching 3,4,5
	std::cout << std::distance(
		vec.begin(), 
		std::find_end(vec.begin(), vec.end(), subrange.begin(), subrange.end())) 
		<< std::endl;

	// PART E)

	vec = { 1,2,5,5,-3,4,5,5,5,6,3,4,5 };

	// first element that has equal value than next
	std::cout << std::distance(
		vec.begin(),
		std::adjacent_find(vec.begin(), vec.end()))
		<< std::endl;

	// PART F)
	vec = { 1,2,5,5,-3,4,5,5,5,6,3,4,5 };
	subrange = { 1,2,5 };

	std::cout << std::boolalpha << 
		std::equal(subrange.begin(), subrange.end(), vec.begin()) 
		<< std::endl;

}

