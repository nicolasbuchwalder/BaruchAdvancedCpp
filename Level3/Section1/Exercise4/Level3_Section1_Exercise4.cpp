// Level3_Section1_Exercise4.cpp: This file contains the main function for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

// PART A, B, C
#include "Queue.h"
#include "Producer.h"
#include "Consumer.h"


#include <iostream>
#include <boost\thread.hpp>


int main() {

	// creating queue that will be shared
	Queue<std::string> queue;

	// creating producers and consumers
	const int numProducers{ 7 };
	const int numConsumers{ 4 };

	// creating threads for producers and consumters
	boost::thread_group producers;
	for (int i = 0; i < numProducers; i++) {
		Producer p(i, &queue);
		producers.create_thread(p);
	}

	boost::thread_group consumers;
	for (int i = 0; i < numConsumers; i++) {
		Consumer c(i, &queue);
		consumers.create_thread(c);
	}

	producers.interrupt_all();
	consumers.interrupt_all();
	producers.join_all();
	consumers.join_all();
	
	
}