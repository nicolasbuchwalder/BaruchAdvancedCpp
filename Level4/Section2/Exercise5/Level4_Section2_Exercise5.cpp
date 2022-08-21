// Level4_Section2_Exercise5.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <vector>
#include <numeric>
#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <unordered_set>

// PART A)

// user defined function for muliplication
int multiply(const std::vector<int> vec) {
	int product{1};
	for (int elem : vec) { product *= elem; };
	return product;
}

// PART B)

// function that filters out elements whose absolute value are below a threshold
std::vector<int> abs_threshold(const std::vector<int> vec, int threshold) {
	std::vector<int> out;
	for (int elem : vec) {
		if ((std::abs(elem) > threshold) && (std::find(out.begin(), out.end(), elem) == out.end()))
		{ out.push_back(elem); };
	};
	return out;
}

// function to print vector
std::string print(const std::vector<int>& vec) {
	std::string out{ "[" };
	for (int i{ 0 }; i < vec.size(); ++i) {
		if (vec[i] != -1) { 
			out += std::to_string(vec[i]); 
			if (i != vec.size() - 1) { out += ", "; };
		};
		
	}
	return out + "]\n" ;
}

int main() {

	// PART A)

	std::vector<int> vec{ 1,2,3,4,5,6 };

	// user-defined
	std::cout << multiply(vec) << std::endl;

	// predefined stl
	std::cout << std::accumulate(vec.begin(), vec.end(), 1, std::multiplies<int>()) << std::endl;

	// lambda function
	std::cout << std::accumulate(vec.begin(), vec.end(), 1, [](int elem, int total) {return elem * total; }) << std::endl;

	//=> user defined is more readable, but less maintanable
	//=> the lambda function here just add complexity for nothing
	//=> so STL functions seems the best: maintainable and quite readable
	
	// PART B)

	vec = { 1,2,1,4,5,5,-1 };
	int threshold{2};

	// user-defined
	std::cout << print(abs_threshold(vec, threshold));

	// predefined stl
	vec.erase(std::remove_if(vec.begin(), vec.end(), std::bind2nd(std::less_equal<int>(), threshold)));
	std::unordered_set<int> s1(vec.begin(), vec.end());
	vec.assign(s1.begin(), s1.end());
	std::cout<< print(vec);
	vec = { 1,2,1,4,5,5,-1 };

	// lambda 
	vec.erase(std::remove_if(vec.begin(), vec.end(), [threshold](int x) {return std::abs(x) <= threshold; }));
	s1 = std::unordered_set<int>(vec.begin(), vec.end());
	vec.assign(s1.begin(), s1.end());
	std::cout << print(vec);
	//=> maybe sometimes lambda functions can be more redable with about the same maintanbility than the stl 


}