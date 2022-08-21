// Level3_Section5_Exercise1.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <queue>
#include <iostream>


int main(){

	// PART A)

	// long long priority queue
	std::priority_queue<long long> priorityQueue;

	// pushing values 66, 22, 44
	priorityQueue.push(66);
	priorityQueue.push(22);
	priorityQueue.push(44);

	// printing top elements and pop it
	std::cout << "top element : " << priorityQueue.top() << std::endl;
	priorityQueue.pop();

	// push values 11, 22, 33
	priorityQueue.push(11);
	priorityQueue.push(22);
	priorityQueue.push(33);

	// pop element
	priorityQueue.pop();

	// iterate in the priority until empty
	while (!priorityQueue.empty()) {
		std::cout << "top element : " << priorityQueue.top() << std::endl;
		priorityQueue.pop();
	}

	std::cout << std::endl;


	// PART B)
	
	// priority queue whose elements are long long whose container is std::deque
	std::priority_queue<long long, std::deque<long long>, std::greater<long long>> priorityQueue2;

	// pushing values 66, 22, 44
	priorityQueue2.push(66);
	priorityQueue2.push(22);
	priorityQueue2.push(44);

	// printing top elements and pop it
	std::cout << "top element : " << priorityQueue2.top() << std::endl;
	priorityQueue2.pop();

	// push values 11, 22, 33
	priorityQueue2.push(11);
	priorityQueue2.push(22);
	priorityQueue2.push(33);

	// pop element
	priorityQueue2.pop();

	// iterate in the priority until empty
	while (!priorityQueue2.empty()) {
		std::cout << "top element : " << priorityQueue2.top() << std::endl;
		priorityQueue2.pop();
	}
	//=> here it is in the opposite order, as expected

	std::cout << std::endl;


	// PART C)

	// lambda function for ordering queue
	auto ordering = [](long long l, long long r) {return l > r; };

	// priority queue whose elements are long long whose container is std::deque
	std::priority_queue<long long, std::deque<long long>, decltype(ordering)> priorityQueue3(ordering);

	// pushing values 66, 22, 44
	priorityQueue3.push(66);
	priorityQueue3.push(22);
	priorityQueue3.push(44);

	// printing top elements and pop it
	std::cout << "top element : " << priorityQueue3.top() << std::endl;
	priorityQueue3.pop();

	// push values 11, 22, 33
	priorityQueue3.push(11);
	priorityQueue3.push(22);
	priorityQueue3.push(33);

	// pop element
	priorityQueue3.pop();

	// iterate in the priority until empty
	while (!priorityQueue3.empty()) {
		std::cout << "top element : " << priorityQueue3.top() << std::endl;
		priorityQueue3.pop();
	}
	//=> same things as before, but now is a lambda function replacing std::greater
}