// EmptyState.cpp: This file contains the class that defines the state of a stack that is empty
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course
#pragma once

#include "EmptyState.h"

#include "Stack.h"
#include "NotFullNotEmptyState.h"
#include "FullState.h"

#include <stdexcept>


// pushing element to stack
void EmptyState::Push(Stack* stack, const int element) {

    // calling base class push function
    StackState::Push(stack, element);
    
    //checking if stack is not full
    if (stack->_idx == stack->_stack.size()) {
        // switching to full state if index is size
        stack->_state = Singleton<FullState>::instance();
    }
    else {
        stack->_state = Singleton<NotFullNotEmptyState>::instance();
    }

}
// removing element to stack => not possible for empty stack! throwing error
int EmptyState::Pop(Stack* stack) {
    throw std::runtime_error("Cannot pop from an empty stack");
    return -1;
}






