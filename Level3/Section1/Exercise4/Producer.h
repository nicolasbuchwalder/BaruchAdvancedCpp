// Producer.h: This file contains the class for adding elements in the thread safe queue
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#pragma once

#include "Queue.h"

#include <thread>
#include <string>


class Producer
{
private:

	// id of producer
	int id;
	// pointer to queue of strings
	Queue<std::string>* queue;

public:

	// values constructor: id and pointer to queue
	Producer(int id, Queue<std::string>* queue)
		: id{ id }, queue{ queue }{};

	// producer producing data (putting it into queue)
	void operator()() {
		int data{ 0 };
		while (data < 10) {
			// mimic web request
			std::this_thread::sleep_for(std::chrono::seconds(1));

			// creating data (as log file)
			std::string out_data{" record " + std::to_string(data++) };

			// adding data to queue
			queue->add_queue(out_data);

			std::cout << "data : '" << out_data << "' has just been added to queue by producer " << id << ", queue size: " << queue->queue_size() << std::endl;

		}
	}
};

