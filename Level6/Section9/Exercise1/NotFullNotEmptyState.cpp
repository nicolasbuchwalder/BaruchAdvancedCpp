// PartiallyFilledState.h: This file contains the class that defines the state of a stack that is partially filled
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course
#pragma once

#include "NotFullNotEmptyState.h"

#include "Stack.h"
#include "EmptyState.h"
#include "FullState.h"

#include <stdexcept>


// pushing element to stack
void NotFullNotEmptyState::Push(Stack* stack, const int element) {

    // calling base class push function
    StackState::Push(stack, element);

    //checking if stack is not full
    if (stack->_idx == stack->_stack.size()) {
        // switching to full state if index is size
        stack->_state = Singleton<FullState>::instance();
    }

}
// removing element to stack 
int NotFullNotEmptyState::Pop(Stack* stack) {

    // calling base class pop function and sorting result that will be returned
    int out{ StackState::Pop(stack) };

    if (stack->_idx == 0) {
        // switching to empty state if index is 0
        stack->_state = new EmptyState;
    }
    return out;
}





