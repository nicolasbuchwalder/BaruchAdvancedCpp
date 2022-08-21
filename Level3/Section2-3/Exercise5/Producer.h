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
	// number of chars total
	int numChairs;

	// closing time of the salon
	std::chrono::steady_clock::time_point closingTime;
	
	// pointer to queue of strings
	Queue<std::string>* queue;

public:

	// values constructor: id and pointer to queue
	Producer(int id, int numChairs, std::chrono::steady_clock::time_point& closingTime, Queue<std::string>* queue)
		: id{ id }, numChairs{ numChairs }, closingTime{ closingTime }, queue{ queue }{};

	// producer producing data (putting it into queue) 
	void operator()() {

		int client_id{ 1 };

		// barber closes the barber shop at closingTime
		while (std::chrono::steady_clock::now() < closingTime) {

			// builing alias
			std::string who{ "customer " + std::to_string(client_id) };

			// a customer can come if there are less people waiting then the number of chairs
			if (queue->queue_size() < numChairs) {

				// adding customer to the queue 
				queue->add_queue(who);

				// if the queue is not zero, then the barber will not take care of the client
				if ((queue->queue_size() > 0) && (client_id > 1)) {std::cout << who << " is " << queue->queue_size() << "th in line for the cut" << std::endl;}

			}
			else {
				std::cout << who << " couldn't find a chair, so is leaving" << std::endl;
			};
			// next customer arrives in 10 seconds
			std::this_thread::sleep_for(std::chrono::seconds(10));
			++client_id;


		}
	}
};

