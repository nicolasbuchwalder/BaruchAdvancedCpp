// Level3_Section4_Exercise3.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <future>
#include <thread>
#include <chrono>
#include <iostream>

// PART C)

// function that will be in the thread
void function(std::future<double>& f) {

	// simulating waiting time
	std::this_thread::sleep_for(std::chrono::seconds(2));
	// getting the data of the future
	double data{ f.get() };
	// outputing data
	std::cout << "data from thread is: " << data << std::endl;

}

// thread function

int main() {

	// PART A)

	// creating default promise
	std::promise<int> p1;
	// creating promise with empty shared state
	std::promise<int> p2{std::allocator_arg, std::allocator<int>() };
	// creating promise from moved 
	std::promise<int> p3{std::move(p1)};

	// PART B)

	// promise with double as stored value
	std::promise<double> p;

	// future associated with that promise
	std::future<double> f{ p.get_future() };

	// PART C)

	// starting thread
	std::thread t(function, std::ref(f));

	// PART D)

	// setting value of data through promise
	p.set_value(3.14);
	//=> we see indeed that the value we get is 3.14 from thread function

	// joining thread
	t.join();




}