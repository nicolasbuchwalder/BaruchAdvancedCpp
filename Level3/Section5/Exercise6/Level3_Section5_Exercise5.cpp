// Level3_Section5_Exercise5.cpp: This file contains the main function for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include "StopWatch.h"

#include <thread>
#include <iostream>
#include <random>

// settting random seeds
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> distribution(1, 1000);

int main() {

	StopWatch stopwatch;
	
	for (int i{ 0 }; i < 10; ++i) {
		int theoriticalWaitTime{ distribution(gen) };
		stopwatch.StartStopWatch();
		std::this_thread::sleep_for(std::chrono::milliseconds(theoriticalWaitTime));
		stopwatch.StopStopWatch();
		std::cout << "calculated time by stopwatch: " << stopwatch.GetTime() << ", waiting time from random: " 
			<< theoriticalWaitTime / 1000.0 << std::endl;

	}
	// => we notice that it matches the theoritical wait time

	stopwatch.Reset();
	std::cout << "time by stopwatch after reset: " << stopwatch.GetTime() << std::endl;
	//=> is at zero, as expected

	

}