// Queue.h: This file contains the template class for a thread safe queue
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#pragma once

#include <thread>
#include <mutex>
#include <queue>
#include <string>
#include <iostream>

template <typename T>
class Queue
{
private:
	std::queue<T> queue;
	std::mutex mutex;

	// PART C)
	// condition variable for notifications
	std::condition_variable condition;

public:
	// PART A)

	// function to add data at the back of the queue
	void add_queue(const T data) {

		// PART B)
		// lock for synchronisation
		std::unique_lock<std::mutex> lock{ mutex };

		// adding data at the back of the queue
		queue.push(data);

		// PART C)
		// notifying only the current thread
		condition.notify_one();

	};

	// function to pop and return the front of the queue
	T dequeue() {

		// PART B)
		// lock for synchronisation
		std::unique_lock<std::mutex> lock{ mutex };

		// waiting until there is at least one data in the queue to return it
		while (queue.size() == 0) { condition.wait(lock); };

		// getting the first element, poping it and returning it
		T out{ queue.front() };
		queue.pop();
		return out;
	}

	// function to look at the queue size
	std::size_t queue_size() { return queue.size(); };
};

