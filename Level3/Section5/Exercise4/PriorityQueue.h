// Queue.h: This file contains the template class for a thread safe queue with template container and comparator
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#pragma once

#include <thread>
#include <mutex>
#include <queue>
#include <string>
#include <iostream>
#include <vector>



template <typename T, typename F>
class PriorityQueue
{
private:
	std::priority_queue<T, std::vector<T>,  F> queue;
	std::mutex mutex;
	std::condition_variable condition;

public:

	// function to add data at the back of the queue
	void add_queue(const T data) {

		// lock for synchronisation
		std::unique_lock<std::mutex> lock{ mutex };

		// adding data at the back of the queue
		queue.push(data);

		// printing
		std::cout << data << " has been added to queue" << std::endl;

		// notifying only the current thread
		condition.notify_one();

	};

	// function to pop and return the front of the queue
	T dequeue() {

		// lock for synchronisation
		std::unique_lock<std::mutex> lock{ mutex };

		// waiting until there is at least one data in the queue to return it
		while (queue.size() == 0) { condition.wait(lock); };

		// getting the first element, poping it and returning it
		T out{ queue.top() };
		queue.pop();

		// printing
		std::cout << out << " has been removed from queue" << std::endl;

		return out;
	}

	// function to look at the queue size
	std::size_t queue_size() { return queue.size(); };
};

