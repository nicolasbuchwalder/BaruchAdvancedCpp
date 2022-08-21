// Consumer.h: This file contains the class for reading elements in the thread safe queue
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#pragma once

#include "Queue.h"

#include <thread>
#include <string>


class Consumer
{
private:

	// id of consumer
	int id;
	// pointer to queue of strings
	Queue<std::string>* queue;

public:

	// value constructor: id and pointer to queue
	Consumer(int id, Queue<std::string>* queue)
		: id{ id }, queue{ queue }{};

	// consumer comsuming data (getting data from queue)
	void operator()() {
		while (queue->queue_size() > 0) {
			// mimic web request
			std::this_thread::sleep_for(std::chrono::seconds(1));

			// getting data from queue
			std::cout << "data : '" << queue->dequeue() << "' has just been read from consumer " << id << ", queue size: " << queue->queue_size() << std::endl;

		}
	}
};

