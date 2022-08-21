// Producer.h: This file contains the class for adding elements in the thread safe queue
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#pragma once

#include "PriorityQueue.h"

#include <thread>
#include <string>
#include <functional>
#include <vector>

class Command;

template < typename T, typename F>
class Producer
{
	using producingWrapper = std::function<T(void)>;

private:

	// id of producer
	int id;

	// activity until end
	std::chrono::steady_clock::time_point end;

	// function that will be stored
	producingWrapper producingFunction;

	// pointer to queue of strings
	PriorityQueue<T, F>* queue;

public:

	// values constructor: id and pointer to queue
	Producer(int id, std::chrono::steady_clock::time_point& end, producingWrapper function, PriorityQueue<T, F>* queue)
		: id{ id }, end{ end }, producingFunction{ function }, queue{ queue }{};

	// producer producing data (putting it into queue) 
	void operator()() {

		// trying to unqueue data until end
		while (std::chrono::steady_clock::now() < end) {

			// adding data to the queue 

			queue->add_queue(producingFunction());

			// waiting for next production
			std::this_thread::sleep_for(std::chrono::seconds(2));
		}
	}
};

