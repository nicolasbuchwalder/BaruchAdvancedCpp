// Consumer.h: This file contains the class for reading elements in the thread safe queue
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#pragma once

#include "Queue.h"

#include <thread>
#include <string>
#include <iostream>


class Consumer
{
private:

	// id of consumer
	int id;
	// time to cut hair
	int cutTime;

	// closing time of the salon
	std::chrono::steady_clock::time_point closingTime;

	// pointer to queue of strings
	Queue<std::string>* queue;

public:

	// value constructor: id and pointer to queue
	Consumer(int id, int cutTime, std::chrono::steady_clock::time_point& closingTime, Queue<std::string>* queue)
		: id{ id }, cutTime{ cutTime }, closingTime{ closingTime }, queue{ queue }{};

	// consumer comsuming data (getting data from queue)
	void operator()() {

		// this is just to not have the message "barber is free now" repeating 
		bool saidBarberFree{ false };
		// barber closes the barber shop at closingTime
		while (std::chrono::steady_clock::now() < closingTime) {

			if (queue->queue_size() > 0) {

				std::string customer{ queue->dequeue() };
				std::cout << customer << " has been taken in by the barber" << std::endl;

				// barber takes cutTime seconds to cut hair
				std::this_thread::sleep_for(std::chrono::seconds(cutTime));
				std::cout << customer << " is leaving like a new person" << std::endl;

				saidBarberFree = false;

			}
			else {
				if (!saidBarberFree) {
					std::cout << "barber is free now" << std::endl;
					saidBarberFree = true;
				}
			};
		}
		std::cout << "barber has finished his day: " << queue->queue_size() << " clients have waited for nothing..." << std::endl;
	}
};

