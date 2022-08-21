// Level3_Section5_Exercise5.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include "PriorityQueue.h"
#include "Producer.h"
#include "Consumer.h"
#include "Command.h"
#include "Comparator.h"

#include <thread>
#include <chrono>
#include <functional>
#include <random>

// settting random seeds
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> distribution(0, 10);



// produces a command with random priority and a simple squared function
Command generateCommand() {
	
};



int main() {

	// setting end of algorithm
	std::chrono::steady_clock::time_point end{ std::chrono::steady_clock::now() + std::chrono::seconds(30) };

	// creating queue with priority function
	PriorityQueue<Command, Comparator> queue;

	// PART A)

	// creating array of three threads of producers
	const int numProducers{ 1 };
	std::thread producers[numProducers];

	// wrapper to function to create commands from producers
	// the function for producing sets a command with random priority between 0 and 10 and the same algo function
	// which is simply the squared of the input

	std::function<Command(void)> functionProducing{ []() {
		std::function<double(double)> commandFunction = [](double x) {return x * x; };
		return Command{ commandFunction,  distribution(gen) };
	} };

	for (int i{ 0 }; i < numProducers; ++i) {
		// producer of commands with 

		Producer<Command, Comparator> p{i, end, functionProducing, &queue};
		producers[i] = std::thread(p);
	}

	// PART B)

	// creating array of three threads of consumers
	const int numConsumers{ 1 };
	std::thread consumers[numConsumers];

	for (int i{ 0 }; i < numConsumers; ++i) {
		// producer of commands with 
		Consumer<Command, Comparator> c{ i, end, &queue };
		consumers[i] = std::thread(c);
	}
	
	// PART C)

	for (auto& producer : producers) { producer.join(); };
	for (auto& consumer : consumers) { consumer.join(); };
	
	//=> we notice that the comparator works proprely and that the lowest number of the commands in the queue is always first
}