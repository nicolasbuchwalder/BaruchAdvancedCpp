// Level3_Section5_Exercise2.cpp: This file contains the main function for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include "Command.h"

# include <functional>
#include <queue>

int main() {

	// PART A)

	// comparator for Command (order by priority)
	auto compare = [](Command l, Command r) {return l.priority() > r.priority(); };

	// PART B)

	// function (wrapped) for the commands
	std::function<double(double)> squared = [](double x) {return x * x; };

	// creating several instances of command
	Command c1(squared, 1);
	Command c2(squared, 3);
	Command c3(squared, 2);

	// PART C)

	// priority queue of commands
	std::priority_queue<Command, std::vector<Command>, decltype(compare)> queue(compare);

	// inserting commands in queue
	queue.push(c1);
	queue.push(c2);
	queue.push(c3);

	// PART D)

	// executing each command until empty
	for (; !queue.empty(); queue.pop()) {
		queue.top().Execute(3.14);
	}
}