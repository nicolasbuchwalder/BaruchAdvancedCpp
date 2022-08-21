// Level5_Section7_Exercise3.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <boost/bimap.hpp>
#include <boost/bimap/multiset_of.hpp>
#include <string>
#include <iostream>
#include <tuple>

// PART A

// 1 N assiciation between title and author and book price in bimap

using bm_type = boost::bimap<
	boost::bimaps::multiset_of<std::string>,
	boost::bimaps::set_of<std::string>,
	boost::bimaps::with_info<double>
>;

using value_type = bm_type::value_type;

using bm_type_abstract = boost::bimap<
	boost::bimaps::multiset_of<std::string>,
	boost::bimaps::set_of<std::string>,
	boost::bimaps::with_info<std::tuple<std::string,double>>
>;

using value_type_abstract = bm_type_abstract::value_type;

int main() {

	bm_type books;

	books.insert(value_type("Dan Stefanica", "100 Interview Questions", 30));
	books.insert(value_type("Dan Stefanica", "Probability and Stochastic Interview Questions", 35));
	books.insert(value_type("John Hull", "Options, Futures and Other Derivatives", 90));

	// PART B)
	
	// printing book price from given author
	auto search = books.left.find("Dan Stefanica");
	std::cout << search->first << " has written '" << search->second << "' which costs " << search->info << std::endl;


	// PART C)

	bm_type_abstract books2;

	books2.insert(value_type_abstract(
		"Dan Stefanica",
		"100 Interview Questions", 
		std::make_tuple("This is a description", 30)));

	books2.insert(value_type_abstract(
		"Dan Stefanica", 
		"Probability and Stochastic Interview Questions", 
		std::make_tuple("This is a description", 35)));

	books2.insert(value_type_abstract(
		"John Hull", 
		"Options, Futures and Other Derivatives", 
		std::make_tuple("This is a description", 90)));

	// printing book price from given author
	auto search2 = books2.left.find("Dan Stefanica");
	std::cout << search2->first << " has written '" << search2->second << "' which costs " << std::get<0>(search2->info) << std::endl;
}