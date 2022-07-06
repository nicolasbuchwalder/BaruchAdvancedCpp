// Level1_Section5_Exercise1.cpp: This file contains all the code for this exercise. @Nicolas Buchwalder

#include <boost/date_time/gregorian/gregorian.hpp>
#include <tuple>
#include <array>
#include <span>
#include <vector>
#include <string>
#include <iostream>

// PART A)
// alias for a tuple representing a person

using Person = std::tuple<std::string, boost::gregorian::date>;

// PART B)
// printing function for the person tuple
void printPerson(Person const& person) { std::cout << "Name: " << std::get<0>(person) << ", \t Birthday: " << std::get<1>(person) << std::endl; }


// PART C)
// vector of person tuple
using People = std::vector<Person>;

// printing function for vector of person tuple
void printPeople(People const& people) {
	for (auto const& person : people) { printPerson(person); };
};

// PART D)
// function necessary for the sorting by birthdate
bool compareBrithdate(Person const& person1, Person const& person2) {
	return (std::get<1>(person1) < std::get<1>(person2));
};

// PART F)
// function printing a span with range-based loop
void printSpanRange(const std::span<int>& span) {
	std::cout << "Range-Based: ";
	for (auto elem : span) {
		std::cout << elem << ", ";
	};
	std::cout << std::endl;
};
// function printing a span with iterator loop
void printSpanIterator(const std::span<int>& span) {
	std::cout << "Iterator: ";
	for (auto ptr{ span.begin()}; ptr != span.end(); ++ptr) {
		std::cout << *ptr << ", ";
	};
	std::cout << std::endl;
};
// function printing a span with indexing loop
void printSpanIndexing(const std::span<int>& span) {
	std::cout << "Indexing: ";
	for (int i{ 0 }; i < span.size(); ++i) {
		std::cout << span[i] << ", ";
	};
	std::cout << std::endl;
};


// PART G)
// getting the first N elements of a span
std::span<int> firstNSpan(const std::span<int>& span, const int N) {
	return std::span< int, std::dynamic_extent> {span.first(N)};
};
// getting the last N elements of a span
std::span<int> lastNSpan(const std::span<int>& span, const int N) {
	return std::span< int, std::dynamic_extent> {span.last(N)};
};


// PART H)
// function to check what subspan does
void testSubspan(const std::span<int>& span, int start, int length) {
	auto subspan{ span.subspan(start, length) };
	printSpanRange(subspan);
};



int main() {

	// PART A, B)
	// generating persons
	Person person1 = std::make_tuple("Nicolas Buchwalder", boost::gregorian::date{ 1999, 11, 2 });
	printPerson(person1);
	Person person2 = std::make_tuple("Name Surname", boost::gregorian::date{ 2001, 1, 4 });
	printPerson(person2);

	// modifying them
	std::get<0>(person2) = "John Doe";
	printPerson(person2);
	// => we notice that the modification has indeed worked
	std::cout << std::endl;

	// PART C)
	// generating the array of persons
	Person person3 = std::make_tuple("Barack Obama", boost::gregorian::date{ 1969, 7, 21 });
	People people{person1, person2, person3};
	printPeople(people);

	// PART D)
	std::sort(people.begin(), people.end(), compareBrithdate);
	std::cout << "Sorted:" << std::endl;
	printPeople(people);
	// => sorting works

	std::cout << std::endl;

	// PART E, F)
	int list[4]{ 4,3,2,1 };
	std::array<int, 5> fixed_array{1,2,3,4,5 };
	std::vector<int> variable_array{ 3,2,1 };

	auto span1 = std::span(list);
	printSpanRange(span1);
	auto span2 = std::span(fixed_array);
	printSpanIterator(span2);
	auto span3 = std::span(variable_array);
	printSpanIndexing(span3);
	// => all three work

	//span3[0] = 4;
	//=> produces errors => read only

	// PART G)
	std::cout << "first 3 of span 2: ";
	printSpanRange(firstNSpan(span2, 3));
	
	std::cout << "last 2 of span 1: ";
	printSpanRange(lastNSpan(span1, 2));

	std::cout << "Subspans: " << std::endl;

	testSubspan(span2, 0, 5);
	// => works fine
	// testSubspan(span2, 1, 5);
	// => doesn't work, last element is out of bounds
	testSubspan(span2, 3, 2);
	// => works fine as well

	// PART I)
	std::cout << "Given code:" << std::endl;
	// given code:

	float data[1]{ 3.141592f };

	auto const const_bytes = std::as_bytes(std::span{ data });

	for (auto const b : const_bytes)
	{
		std::cout << std::setw(2)
			<< std::hex
			<< std::uppercase
			<< std::setfill('0')
			<< std::to_integer<int>(b) << ' ';
	}

	// => this code seems to show the value of the bytes that are set for the float number of pi

}