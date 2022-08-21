// RealAccount.h: This file contains the class for the standard account
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course
#pragma once

#include "Account.h"


class RealAccount :
    public Account
{
private:
    double _balance;

public:
    // default constructor
    RealAccount();
    // value constructor
    RealAccount(double init_balance);
    
    // withdraw method
    void Withdraw(double amount);

    // get balance method
    double GetBalance();
};

