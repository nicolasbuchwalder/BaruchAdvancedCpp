// Level7_Exercise4.cpp: This file contains the main function for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include "TmpProcessor.h"


#include <iostream>
#include <future>
#include <thread>
#include <chrono>

// function that takes time (waits and squares the value)
double slow_func(double x) {
	std::this_thread::sleep_for(std::chrono::seconds(1));
	return x * x;
}

int main() {
	
	// PART A)

	// simple functions
	FactoryFunction<double> get = []() {return 3.14; };
	ComputeFunction<double> square = [](double x) {return x*x; };
	DispatchFunction<double> print = [](double x) {std::cout << "result is " << x << std::endl; };

	TmpProcessor<double> processor(get, square, print);
	processor.algorithm();
	//=> works

	// PART B)

	// parallel computing 
	ComputeFunction<double> parallel = [](double x) {
		std::future<double> f(std::async(slow_func, x));
		double x1 = slow_func(x);
		double x2 = f.get();
		return x1 + x2;
	};

	// sequential computing 
	ComputeFunction<double> sequential = [](double x) {
		double x1 = slow_func(x);
		double x2 = slow_func(x);
		return x1 + x2;
	};


	std::chrono::steady_clock::time_point start, end;

	TmpProcessor<double> parallel_processor(get, parallel, print);

	start = std::chrono::steady_clock::now();
	parallel_processor.algorithm();
	end = std::chrono::steady_clock::now();
	std::cout << "parallel processor took " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

	TmpProcessor<double> seq_processor(get, sequential, print);

	start = std::chrono::steady_clock::now();
	seq_processor.algorithm();
	end = std::chrono::steady_clock::now();
	std::cout << "sequential processor took " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;
	// => we see that this class allows parallel processing as well
}