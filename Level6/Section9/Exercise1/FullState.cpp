// FullState.cpp: This file contains the class that defines the state of a stack that is partially filled
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course
#pragma once

#include "FullState.h"

#include "Stack.h"
#include "EmptyState.h"
#include "NotFullNotEmptyState.h"


#include <stdexcept>

// pushing element to stack  => not possible as stack is already full! throwing error
void FullState::Push(Stack* stack, const int element) {
    throw std::runtime_error("Cannot push to full stack");
}
// removing element to stack 
int FullState::Pop(Stack* stack) {

    // calling base class pop function and sorting result that will be returned
    int out{ StackState::Pop(stack) };

    if (stack->_idx == 0) {
        // switching to empty state if index is 0
        stack->_state = Singleton<EmptyState>::instance();
    }
    else {
        // switching to partially filled state
        stack->_state = Singleton<NotFullNotEmptyState>::instance();
    }
    return out;
}





