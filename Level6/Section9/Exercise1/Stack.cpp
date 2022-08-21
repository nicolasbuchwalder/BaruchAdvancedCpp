// Stack.cpp: This file contains the stack class
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include "Stack.h"

#include "EmptyState.h"


// default constructor (stack of size 1)
Stack::Stack() {
	Init(1);
}

// value constructor with size argument
Stack::Stack(int size) {
	Init(size);
}

// init method
void Stack::Init(int size) {
	// checking if the size is at least 1 or sets to 1
	if (size < 1) size = 1;

	// creating vector
	_stack = std::vector<int>(size);

	// setting the current index to 0
	_idx = 0;

	// setting state to empty
	_state = Singleton<EmptyState>::instance();
}

// method that adds an element
void Stack::Push(const int element) {
	// using the current state to push
	_state->Push(this, element);
}

// method that returns an element
int Stack::Pop() {

	// using the current state to pop
	return _state->Pop(this);
}

