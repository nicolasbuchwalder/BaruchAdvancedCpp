// NoAccessException.h: This file contains the exception class if access to account has been denied
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course
#pragma once

#include "Exception.h"

class NoAccessException :
    public Exception
{
public:
    // message to understand the exception
    const char* what() const noexcept {
        return "You dot not have access to this account.";
    }
};

