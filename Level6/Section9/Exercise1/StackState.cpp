// StackState.cpp: This file contains the abstract class that defines the state of a stack
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course
#pragma once

#include "StackState.h"

#include "Stack.h"


// function to push data to stack
void StackState::Push(Stack* stack, const int element) {
	// adding element to stack
	stack->_stack[stack->_idx] = element;
	// increasing current index
	stack->_idx++;
};

// function to pop last value of stack
int StackState::Pop(Stack* stack) {
	--stack->_idx;
	return stack->_stack[stack->_idx];
}



