#include "ProtectedAccount.h"
#include "RealAccount.h"

#include <iostream>

// svalue constructor that sets a reference to an account and sets password
ProtectedAccount::ProtectedAccount(double init_balance, std::string password) {
    _account = std::make_shared<RealAccount>(init_balance); 
    _password = password;
}

// withdraw that simply calls the RealAccount method
void ProtectedAccount::Withdraw(double amount) {
    _account->Withdraw(amount); 
};

// calls the RealAccount method only if it is called with correct password
double ProtectedAccount::GetBalance(std::string password) {
    // if untrue, called No Anccess Exception
    if (password != _password) {
        throw NoAccessException();
    }
    // claiing RealAccount method
    _account->GetBalance();
};
