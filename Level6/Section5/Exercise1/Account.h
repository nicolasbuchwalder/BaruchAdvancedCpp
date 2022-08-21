// Account.h: This file contains the abstract class for the account
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#pragma once
#include "NoFundsException.h"
#include "NoAccessException.h"

class Account
{
public:

	// withdraw money => pure virtual to make this class abstract
	virtual void Withdraw(double amount) throw(NoFundsException) = 0;

	// get balance of account
	virtual double GetBalance() throw(NoAccessException) { return 0; };
	// => cannot be pure virtual as GetBalance has not the same arguments for 
	// all derived classes

};

