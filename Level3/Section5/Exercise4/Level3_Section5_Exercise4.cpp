// Level3_Section5_Exercise4.cpp: This file contains the main function for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

// PART A,B C)
#include "PriorityQueue.h"
#include "Consumer.h"
#include "Producer.h"

#include <chrono>
#include <thread>
#include <functional>
#include <random>

int main() {

	// PART D)

	// creating queue
	PriorityQueue<int, std::greater<int>> queue;

	// setting end of algorithm
	std::chrono::steady_clock::time_point end{ std::chrono::steady_clock::now() + std::chrono::seconds(30) };

	// setting function that will be produced 
	// returning a random number between 0 and 10
	std::function<int(void)> producingFunction = []() {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distribution(0, 10); 
		return distribution(gen); };

	// creating producer and its thread
	Producer<int, std::greater<int>> p{ 1, end, producingFunction, &queue };
	std::thread tp(p);

	// creating consumer and its thread
	Consumer<int, std::greater<int>> c{ 1, end, &queue };
	std::thread tc(c);

	tp.join();
	tc.join();

	// => we notice that indeed the smallest element is always the one dequeued, as expected


}