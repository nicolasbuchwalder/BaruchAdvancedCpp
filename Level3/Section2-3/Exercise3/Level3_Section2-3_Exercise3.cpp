// Level3_Section2-3_Exercise3.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

// PART B)
#include "ActiveObject.h"


#include <iostream>
#include <thread>

// PART A)

// free function that will be a thread function
void freeFunction() { std::cout << "free function" << std::endl; };

// PART C)

// function obkect that will be a thread function
struct Function {
	void Object() { std::cout << "function object" << std::endl; };
};

// lambda function that will be a thread function
auto lambdaFunction = []() { std::cout << "lambda function" << std::endl; };




int main() {
	
	// PART A)

	std::thread t1(freeFunction);
	ActiveObject ao1(t1);
	// => works as planned

	// PART B)

	// creating a thread with no function and associating ActiveObject instance with it
	std::thread t2;
	ActiveObject ao2(t2);
	// => we notice that the error invalid arguement comes so we can define this error

	// PART C)

	// function object
	//std::thread t3(&Function::Object);
	//ActiveObject ao3(t3);

	// stored lambda function
	std::thread t4(lambdaFunction);
	ActiveObject ao4(t4);


	
};