// Level4_Section3_Exercise2.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <map>
#include <random>
#include <string>
#include <iostream>


// PART A)

// template function to print map
template <typename Map>
void print(Map& map) {
    std::cout << "{";
    for (auto& elem : map) { std::cout << elem.first << ':' << elem.second << ", "; };
    std::cout << "}" << std::endl;
};

// template function to generate random numbers 
template <typename Dist, typename Eng>
void GenerateRandomNumbers(Dist d, Eng eng, int NTrials, const std::string& s)
{
    std::map<long long, int> counter;
    for (int i{ 0 }; i < NTrials; ++i) { ++counter[d(eng)]; };
    std::cout << s << std::endl;
    print(counter);
}

int main() {

    // PART B)

    std::mt19937 gen;

    std::geometric_distribution<> d1;
    std::uniform_real_distribution<double> d2(0, 1);
    std::poisson_distribution<> d3(1);

    GenerateRandomNumbers(d1, gen, 10, "geometric");
    GenerateRandomNumbers(d2, gen, 10, "uniform");
    GenerateRandomNumbers(d3, gen, 10, "poisson");

    // PART C)

    //=> it does look like the probability of the distributions
}

