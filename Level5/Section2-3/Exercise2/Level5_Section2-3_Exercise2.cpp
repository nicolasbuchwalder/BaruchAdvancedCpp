// Level5_Section2-3_Exercise2.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <iostream>
#include <boost/regex.hpp>
#include <boost/algorithm/string.hpp>


int main()
{
    boost::regex mySearchReg("(rain)|(Spain)");

    std::string myText("The rain in Spain stays mainly on the plain");

    boost::smatch match;
    std::cout << "match found: " << std::boolalpha << boost::regex_search(myText, match, mySearchReg) << std::endl;
    std::cout << "result: " << match[0] << std::endl;

}