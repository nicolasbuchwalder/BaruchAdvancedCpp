// ProtectedAccount.h: This file contains the class for the standard account
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course
#pragma once

#include "Account.h"

#include <memory>
#include <string>


class ProtectedAccount :
    public Account
{
private:
    // pointer to account
    std::shared_ptr<Account> _account; 
    // password
    std::string _password;

public:
    // value constructor with init balance and password to set
    ProtectedAccount(double init_balance, std::string password);

    // withdraw method 
    void Withdraw(double amount);

    // get balance method
    double GetBalance(std::string password);
};

