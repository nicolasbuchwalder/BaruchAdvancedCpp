// Level4_Section2_Exercise6.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

// PART B)
#include "Point.h"
#include "HashPoint.h"

#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <random>
#include <unordered_set>
#include <iostream>
#include <iomanip>

std::random_device rd;
std::mt19937 gen;

// function to print vector of cahrs
std::string print(const std::vector<char>& vec) {
	std::string out{ "[" };
	for (int i{ 0 }; i < vec.size(); ++i) {
		out += vec[i];
		if (i != vec.size() - 1) { out += ", "; };
	}
	return out + "]\n";
}
// function to print vector of Points
std::string print(const std::vector<Point>& vec) {
	std::string out{ "[" };
	for (int i{ 0 }; i < vec.size(); ++i) {
		out += "{" + std::to_string(vec[i].x()) + ", " + std::to_string(vec[i].y()) + "}";
		if (i != vec.size() - 1) { out += ", "; };
	}
	return out + "]\n";
}

// PART C)

// global variables that contains all types of whitespace
const std::string WHITESPACE{ " \f\n\r\t\v" };

// function that trims withspaces
std::string trim(const std::string& s) {
	size_t start{ s.find_first_not_of(WHITESPACE) };
	size_t end{ s.find_last_not_of(WHITESPACE) };
	if (start < end) { return s.substr(start, end); }
	else { return ""; };
};

// function that trims anything
std::string trim_if(std::function<bool(char)> trim_function, const std::string& s) {
	// searching for the first index that returns false by trimming function (so first element we want to keep)
	auto start = std::distance(s.begin(), std::find_if_not(s.begin(), s.end(), trim_function));
	// we do that same thing but by reversing the string (so we are going to get the number of unwanted elements from the end)
	auto end = std::distance(s.rbegin(), std::find_if_not(s.rbegin(), s.rend(), trim_function));
	// only return if the there is a string between start and n - end
	if (start < s.size() - end) { return s.substr(start, s.size() - end); }
	else { return ""; };
}

// function to print vector of strings
std::string print(const std::vector<std::string>& vec) {
	std::string out{ "[" };
	for (int i{ 0 }; i < vec.size(); ++i) {
		out += vec[i];
		if (i != vec.size() - 1) { out += ", "; };
	}
	return out + "]\n";
}

// function that creates vector of strings from character seperating string
std::vector<std::string> seperate_string(const std::string& s, char separator) {
	// finding the first seperator
	auto end{ s.find( separator)};
	// non const copy of s
	std::string to_process{ s };
	std::vector<std::string> out;
	// iterating until we find no other seperators
	while (end != std::string::npos) {
		// adding substring to vector
		out.push_back(to_process.substr(0, end));
		// removing the added substring
		to_process = to_process.substr(end + 1, to_process.size());
		//finding next seperator
		end = to_process.find(separator);
	}
	out.push_back(to_process);
	return out;
}


int main() {

	// PART A)

	std::vector<char> S1{ 'a', 'b', 'c', 'd', 'e', 'k' };
	std::vector<char> S2{ 'a', 'e' };

	std::for_each(S2.begin(), S2.end(), [&](const char c) {
		S1.erase(std::remove(S1.begin(), S1.end(), c));
		});
	std::cout << print(S1);
	//=> we have indeed b c d k

	// PART B)

	std::vector<Point> points(5);

	// setting random values to points
	std::uniform_int_distribution<> distribution{ -2, 2 };
	for (auto& point : points) { point = Point(distribution(gen), distribution(gen)); };

	std::cout << std::setprecision(0) << print(points);

	// filtering based on duplicates
	std::unordered_set<Point, HashPoint> s(points.begin(), points.end());
	points.assign(s.begin(), s.end());

	std::cout << print(points);
	//=> we see that we have less points than before, the ordered map removed the duplicates

	Point origin{ 0, 0 };
	double distance{ 1.42 };
	points.erase(std::remove_if(points.begin(), points.end(), [&origin, distance](Point p) {return p.compute_distance(origin) > distance; }));

	std::cout << print(points);
	// => the elements far away are indeed not there any more


	// PART C)

	// trimming leading and trailing whitespaces
	std::string s1{ "\t This is a paragraph title    \n" };
	std::cout << trim(s1) << std::endl;
	std::string s2{ "" };
	std::cout << trim(s2) << std::endl;
	//=> works

	// function that trims everything that is not alpha (so either small or capped lettters)
	std::function<bool(char)> is_not_alpha { [](const char c) {return !std::isalpha(c); }};

	std::string s3{ "1.2\t This is a title 5 \n" };
	std::cout << trim_if(is_not_alpha, trim(s3)) << std::endl;
	//=> we indeed have just "This is a title"

	// seperating strings
	std::string to_seperate{ "abc,def, ghi" };
	auto string_vector{ seperate_string(to_seperate, ',') };
	std::cout << print(string_vector);
	// => we have a vector of size three, abc, def, ghi


	//joining two strings
	std::string sum{ s2 + s3 };
	std::cout << sum << std::endl;
}

