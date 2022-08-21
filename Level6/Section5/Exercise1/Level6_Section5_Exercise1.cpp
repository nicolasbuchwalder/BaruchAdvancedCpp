// Level6_Section5_Exercise1.cpp: This file contains the main function for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

// PART A, B, C)
#include "NoFundsException.h"
#include "NoAccessException.h"

// PART E-I)
#include "RealAccount.h"
#include "ProtectedAccount.h"


#include <iostream>

int main() {

	RealAccount acc1{ 150 };
	std::cout << "Current balance: " << acc1.GetBalance() << std::endl;

	acc1.Withdraw(50);

	try {
		acc1.Withdraw(200);
	}
	catch (Exception& err) {
		std::cerr << err.what() << std::endl;
	};

	ProtectedAccount pacc1(0, "mypassword");

	try{
		pacc1.GetBalance("false password");
	}
	catch (Exception& err) {
		std::cerr << err.what() << std::endl;
	};

}