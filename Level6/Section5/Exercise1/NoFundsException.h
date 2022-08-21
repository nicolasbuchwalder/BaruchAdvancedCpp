// NoFundsException.h: This file contains the exception class if there are not enough funds
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course
#pragma once

#include "Exception.h"

class NoFundsException :
    public Exception
{
public:
    // message to understand the exception
    const char* what() const noexcept {
        return "Not enough funds on the account to withdraw.";
    }
};

