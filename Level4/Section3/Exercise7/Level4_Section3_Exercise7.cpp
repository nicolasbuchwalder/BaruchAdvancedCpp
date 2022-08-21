// Level4_Section3_Exercise7.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <random>
#include <vector>
#include <numeric>
#include <iostream>

// PART A)

// function that compute the chi shaqured statistic
double chi_squared(const std::vector<int>& observations, const std::vector<double>& freqs) {
	// getting total number of observations
	int N = std::accumulate(observations.begin(), observations.end(), 0);
	double chi{0};
	for (int i{ 0 }; i < observations.size(); ++i) {
		chi += (static_cast<double>(observations[i]) - N * freqs[i]) * (static_cast<double>(observations[i]) - N * freqs[i]) / (N * freqs[i]);
	};
	return chi;
}

int main() {

	// PART B)
	std::vector<int> observations{ 2,2,4 };
	std::vector<double> freqs{ 0.25, 0.25, 0.5 };
	std::cout << chi_squared(observations, freqs) << std::endl;
	//=> expected to be zero as observations match exaclty the output
	
	observations = { 1,0 };
	freqs = { 0.001, 0.999 };
	std::cout << chi_squared(observations, freqs) << std::endl;
	//=> very high, as expected

	// PART C)
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(0, 10);

	observations = {};
	for (int i{ 0 }; i < 10; ++i) {
		observations.push_back(dist(gen));
	}



}