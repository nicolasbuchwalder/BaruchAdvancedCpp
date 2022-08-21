// Level3_Section2-3_Exercise5.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course


// PART A-B)
#include "Producer.h"
#include "Consumer.h"


#include <chrono>
#include <thread>

int main() {

	// PART C)
	
	// creating shared queue and mutex
	Queue<std::string> queue;

	
	// setting at what time the algorithm stops
	int numSecondsDay{ 120 };
	std::chrono::steady_clock::time_point closingTime{ std::chrono::steady_clock::now() + std::chrono::seconds(numSecondsDay) };

	// creating producer thread, with the number of chairs available
	int numChairs{3};
	Producer p(1, numChairs, closingTime, &queue);
	std::thread producer(p);

	// creating consumer, with the number of seconds it takes for the barber to make a cut
	int cutTime{ 23 };
	Consumer c(1, cutTime, closingTime, &queue);
	std::thread consumer(c);

	// ending threads
	producer.join();
	consumer.join();
	
}