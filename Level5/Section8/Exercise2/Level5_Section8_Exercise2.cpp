// Level5_Section8_Exercise2.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <queue>
#include <iostream>
#include <vector>

// PART A)

// template function to print priority queue
template < typename T, class Container, class Compare>
void print(const std::priority_queue<T, Container, Compare>& queue) {
	auto copy{ queue };
	std::cout << "[ ";
	while (!copy.empty()) {
		std::cout << copy.top() << ", ";
		copy.pop();
	}
	std::cout << " ]" << std::endl;
}

int main() {

	// PART A)

	// creating priority_queue
	std::priority_queue<int> queue;
	for (int num : {10, 5, 20, 30, 25, 7, 40}) { queue.push(num); };
	print(queue);

	// PART B)

	// creating priority queue with custom comparitor
	std::priority_queue<int, std::vector<int>, std::greater<int>> greaterqueue;
	for (int num : {10, 5, 20, 30, 25, 7, 40}) { greaterqueue.push(num); };
	print(greaterqueue);
	//=> we see that the queue is in the opposite order, as the priority_queue defaults to smaller

	// PART C)

	// GIVEN CODE
	auto cmp = [](int left, int right)->bool {
		return (left > right);
	};
	//=> we notice that this is what std greater is under the hood

	// creating priority queue with custom comparitor
	std::priority_queue<int, std::vector<int>, decltype(cmp)> customqueue(cmp);
	for (int num : {10, 5, 20, 30, 25, 7, 40}) { customqueue.push(num); };
	print(customqueue);
	//=> as expected, we have the same as std::greater
}