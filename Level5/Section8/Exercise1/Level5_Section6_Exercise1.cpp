// Level5_Section6_Exercise1.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

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

int main() {

	// PART A)

	std::vector<int> vec2{ 3,4,5,6,7,5,6,7,8,9,1,2,3,4 };

	std::cout << "before make_heap: " << print(vec2) << std::endl;

	// PART B)

	std::make_heap(vec2.begin(), vec2.end());

	std::cout << "after make_heap: " << print(vec2) << std::endl;
	//=> we can easily see that each parent node has a higher value than its children

	// PART C)

	std::pop_heap(vec2.begin(), vec2.end());

	std::cout << "after pop_heap: " << print(vec2) << std::endl;
	//=> this puts the largest element in the end and makes a heap starting with the second larges value

	vec2.pop_back();

	std::cout << "after pop_back: " << print(vec2) << std::endl;
	// => this is useful because we want to remove the largest element

	// PART C)

	vec2.push_back(6);

	std::cout << "after push_back: " << print(vec2) << std::endl;
	//=> this adds the value 6 at the end of the heap (so heap is not good just like that)

	std::push_heap(vec2.begin(), vec2.end());

	std::cout << "after push_heap: " << print(vec2) << std::endl;
	// => now heap is now well constructed with additionnal value

	// PART E)

	std::sort_heap(vec2.begin(), vec2.end());

	std::cout << "after sort_heap: " << print(vec2) << std::endl;
	// => this sorts the values of the heap in ascending value

	// PART F)

	std::cout << "largest element of vec2: " << *std::max_element(vec2.begin(), vec2.end()) << std::endl;


}
