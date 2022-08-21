// RealAccount.cpp: This file contains the class for the standard account
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include "RealAccount.h"

#include <iostream>

// defuault constructor with setting balance at 0
RealAccount::RealAccount() : // default
	_balance{ 0 } {};

// value constructor
RealAccount::RealAccount(double init_balance) : 
	_balance{ init_balance } {};

// withdrawing money if enough balance
void RealAccount::Withdraw(double amount) {
	// if not enough money, throws NoFund Exception
	if (amount > _balance) {
		throw NoFundsException();
	}

	_balance -= amount;
	std::cout << "Successfully withdrawn " << amount << " from account, balance: $"
		<< _balance << std::endl;
};

// get balance method
double RealAccount::GetBalance() { return _balance; };
