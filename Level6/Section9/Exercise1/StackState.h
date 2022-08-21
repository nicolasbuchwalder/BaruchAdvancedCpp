// StackState.h: This file contains the abstract class that defines the state of a stack
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course
#pragma once

// forward declaration of Stack to not have cirulcar dependence
class Stack;

class StackState
{
public:
	// function to push data to stack
	virtual void Push(Stack* stack, const int element);

	// function to pop last value of stack
	virtual int Pop(Stack* stack);

};

