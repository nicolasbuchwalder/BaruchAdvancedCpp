// Level3_Section1_Exercise1.cpp: This file contains the main function for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

// PART A) for static member function
#include "Class.h"

#include <iostream>
#include <thread>
#include <functional>
#include <chrono>

// PART A)

// interface for printing functions
void lprint(const std::string& s, int count) {
	for (int i{ 0 }; i < count; ++i) {

		// PART E)
		
		// printing the thread id
		std::cout << "thread " << std::this_thread::get_id() << ": " << s << std::endl;
	};
};

// callable objects, each called three times

// free function
void FreeFunction() { lprint("free function", 3); };

// lambda function
auto LambdaFunction = []() {lprint("stored lambda function", 3); };

// function object
struct FunctionObject {
	void operator() () { lprint("function object", 3); };
};

// binded function
auto BindedFunction = std::bind(lprint, "binded function", 3);

// PART C)
// checking if thread have completed, if so: joining it
void joinThreadNoExcept(std::thread& t) {
	if (t.joinable()) { t.join(); };
}

// PART D)
void joinThread(std::thread& t) {
	if (t.joinable()) { t.join(); }
	else {
		try { t.join(); }
		catch (...) { std::cout << "thread " << t.get_id() << " could not be joined" << std::endl; };
	};
}


int main() {

	// PART F)
	std::chrono::time_point< std::chrono::system_clock> start{ std::chrono::system_clock::now() };

	// PART B)

	// creating threads
	std::thread t1{ FreeFunction };
	std::thread t2{ []() {lprint("lambda function", 3); } };
	std::thread t3{ LambdaFunction };
	// detaching t3
	t3.detach();
	std::thread t4{ FunctionObject()};
	std::thread t5{ Class::StaticFunction};
	std::thread t6{ BindedFunction };

	//=> runtime errors because threads are not joined

	// PART C)
	
	//joinThreadNoExcept(t1);
	//joinThreadNoExcept(t2);
	//joinThreadNoExcept(t3);
	//joinThreadNoExcept(t4);
	//joinThreadNoExcept(t5);
	//joinThreadNoExcept(t6);
	//=> now works, we notice how "random" the outputs are because of the lack of synchronisation
	//=> commented out to use part d code

	// PART D)

	joinThread(t1);
	joinThread(t2);
	joinThread(t3);
	joinThread(t4);
	joinThread(t5);
	joinThread(t6);
	//=> we notice that a thread could not be joined => the detached one

	
	// PART F)
	std::chrono::time_point< std::chrono::system_clock> end{ std::chrono::system_clock::now() };
	std::chrono::duration<double> duration{end - start};
	std::cout << "program took " << duration.count() << "s" << std::endl;
};