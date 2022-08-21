// Level5_Section10_Exercise4.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#define BOOST_TYPEOF_EMULATION

#include <tuple>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <algorithm>

using Range = std::tuple<std::size_t, std::size_t>;
using Result = std::tuple<Range, bool>;

// PART A)

// template function to find idx of elements that encloses x
template <typename Vector, typename value_type>
Result find_sequential_greater(const Vector& v, value_type x)
{
	std::size_t idx = std::distance(
		v.begin(),
		std::find_if(v.begin(), v.end(), [x](value_type elem) {return x > elem; }));

	if (idx = v.size()) {
		return std::make_tuple(std::make_tuple(idx, idx + 1), true);
	}
	return std::make_tuple(std::make_tuple(999, 999), false);
};

// PART B)

// template function to find idx of elements that encloses x with lower_bound
template <typename Vector, typename value_type>
Result find_sequential_greater_lower(const Vector& v, value_type x)
{
	std::size_t idx = std::distance(
		v.begin(),
		std::lower_bound(v.begin(), v.end(), x));

	if (idx = v.size()) {
		return std::make_tuple(std::make_tuple(idx, idx+1), true);
	}
	return std::make_tuple(std::make_tuple(999, 999), false);
};

// template function to find idx of elements that encloses x with upper_bound
template <typename Vector, typename value_type>
Result find_sequential_greater_upper(const Vector& v, value_type x)
{
	std::size_t idx = std::distance(
		v.begin(),
		std::upper_bound(v.begin(), v.end(), x));

	if (idx = v.size()) {
		return std::make_tuple(std::make_tuple(idx, idx+1), true);
	};
	return std::make_tuple(std::make_tuple(999, 999), false);
};

// PART C)


// template function to find idx of elements that encloses x with upper_bound
template <typename Vector, typename value_type>
Result find_sequential_greater_equal_range(const Vector& v, value_type x)
{
	std::size_t idx = std::distance(
		v.begin(),
		std::lower_bound(v.begin(), v.end(), x));

	if (idx = v.size()) {
		return std::make_tuple(std::make_tuple(idx, idx + 1), true);
	}
};

// function to print result
void printResult(const Result& res) {
	if (std::get<1>(res)) {
		auto indexes{ std::get<0>(res) };
		std::cout << "found element at index number: " << std::get<0>(indexes) << std::endl;
	}
	else {
		std::cout << "nothing found" << std::endl;
	};
};

int main() {

	boost::numeric::ublas::vector<int> vec(10);
	for (int i = 0; i < vec.size(); i++) { vec(i) = i; };
	int x{ 5 };

	std::cout << "standard: ";
	printResult(find_sequential_greater(vec, x));

	std::cout << "lower_bound: ";
	printResult(find_sequential_greater_lower(vec, x));

	std::cout << "upper_bound: ";
	printResult(find_sequential_greater_upper(vec, x));

	std::cout << "equal range: ";
	printResult(find_sequential_greater_equal_range(vec, x));



	// PART D)

	// function that returns if function is even
	auto iseven = [](int val) {return (val % 2 == 0); };

	boost::numeric::ublas::vector<int> vec2(6);
	vec2(0) = 2; vec2(1) = 4; vec2(2) = 6; vec2(3) = 8; vec2(4) = 9; vec2(5) = 10;

	// finding first not even element
	auto res = std::find_if_not(vec2.begin(), vec2.end(), iseven);

	std::cout << "not even value: " << vec2[std::distance(vec2.begin(), res)] << std::endl;
	//=> returns 9, as expected


}