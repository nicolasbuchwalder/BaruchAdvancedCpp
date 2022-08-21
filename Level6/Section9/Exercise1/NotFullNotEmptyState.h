// NotFullNotEmpty.h: This file contains the class that defines the state of a stack that is partially filled
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course
#pragma once

#include "StackState.h"
#include "Singleton.h"


class NotFullNotEmptyState :
    public StackState
{

    // necessary for Single class to create the unique instance of EmptyState class
    friend class Singleton<NotFullNotEmptyState>;

public:
    // pushing element to stack
    void Push(Stack* stack, const int element);

    // removing element to stack
    int Pop(Stack* stack);


};

