// Stack.h: This file contains the stack class
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#pragma once

#include <vector>

// forward declaration of StackState to avoid circular dependance
class StackState;

class Stack
{
private:
	// array to store elements (of type int)
	std::vector<int> _stack;

	// current index
	int _idx;

	// init method
	void Init(int size);

	// pointer to state
	StackState* _state;

	// adding the state classes as friends
	friend class StackState;
	friend class EmptyState;
	friend class NotFullNotEmptyState;
	friend class FullState;

public:

	// default constructor (stack of size 1)
	Stack();

	// value constructor with size argument
	Stack(int size);

	// method that adds an element
	void Push(const int element);

	// method that returns an element
	int Pop();

};

