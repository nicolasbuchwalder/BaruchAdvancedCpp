// FullState.h: This file contains the class that defines the state of a stack that is full
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course
#pragma once

#include "StackState.h"
#include "Singleton.h"


class FullState :
    public StackState
{

    // necessary for Single class to create the unique instance of EmptyState class
    friend class Singleton<FullState>;

public:
    // pushing element to stack => not possible as stack is already full!
    void Push(Stack* stack, const int element);

    // removing element to stack
    int Pop(Stack* stack);


};


