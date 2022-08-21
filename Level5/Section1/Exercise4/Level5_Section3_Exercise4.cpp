// Level5_Section3_Exercise4.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include <vector>
#include <list>
#include <boost/algorithm/string.hpp>
#include "boost/date_time/gregorian/gregorian.hpp"



using Data = std::tuple<boost::gregorian::date, std::vector<double>>;
using ResultSet = std::list<Data>;


// function to read csv file
ResultSet read_csv(const std::string& filename) {

	// setting fstream to read file
	std::fstream file(filename);

	// checking that file has opened correctly
	if (!file.is_open()) {
		std::cout << "failed to open" << filename << std::endl;
		return ResultSet();
	}
	// if opened correctly
	else {
		ResultSet data;
		std::string line;
		// removing the header
		std::getline(file, line);
		// reading rows while they are non empty
		while (std::getline(file, line)) {

			// splitting row in elements by "," seperator
			std::vector<std::string> row;
			boost::split(row, line, boost::is_any_of(","));

			// generating the vector of data
			std::vector<double> numbers;
			for (int i{ 1 }; i < row.size(); ++i) { numbers.push_back(boost::lexical_cast<double>(row[i])); };
			
			// adding data to whole dataset that is read
			data.push_back(std::make_tuple(
				boost::gregorian::from_simple_string(row[0]),
				numbers
			));
		};
		return data;
	}
}

// function to print data
void print_row(const ResultSet& data, int row_num){

	// creating copy
	ResultSet copy(data);
	
	// removing the first rows
	for (int i{ 0 }; i < row_num; ++i) {
		copy.pop_front();
	};
	// getting wanted row
	Data row{ copy.front() };

	// printing date
	std::cout << "OHLCVA at " << std::get<0>(row) << ": ";

	// printing values
	for (double value : std::get<1>(row)) {
		std::cout << value << ", ";
	}
	std::cout << std::endl;
	
}
int main() {

	auto data{ read_csv("data.csv") };
	
	print_row(data, 0);
	print_row(data, 15);
}