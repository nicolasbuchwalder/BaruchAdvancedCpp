// Consumer.h: This file contains the class for reading elements in the thread safe queue
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#pragma once

#include "PriorityQueue.h"

#include <thread>
#include <string>
#include <iostream>
#include <vector>

template < typename T, typename F>
class Consumer
{
private:

	// id of consumer
	int id;

	// activity until end
	std::chrono::steady_clock::time_point end;

	// pointer to queue of strings
	PriorityQueue<T, F>* queue;


public:

	// value constructor: id and pointer to queue
	Consumer(int id, std::chrono::steady_clock::time_point& end, PriorityQueue<T, F>* queue)
		: id{ id }, end{ end }, queue{ queue }{};

	// consumer comsuming data (getting data from queue)
	void operator()() {

		// trying to unqueue data until end
		while (std::chrono::steady_clock::now() < end) {

			if (queue->queue_size() > 0) {

				T out_data{ queue->dequeue() };

				// getting data every second
				std::this_thread::sleep_for(std::chrono::seconds(5));

			}
		}
	}
};


