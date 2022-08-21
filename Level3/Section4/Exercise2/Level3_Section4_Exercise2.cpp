// Level3_Section4_Exercise2.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <future>
#include <iostream>
#include <atomic>


// function that will be called (here squared)
auto squared = [](int i) {return i * i; };


// PART D)

// function that never ends
int InfiniteLoop(const std::atomic<bool>& stop) {
	std::cout << "loop launched" << std::endl;
	while (!stop) {};
	return 1;

};


int main() {

	// PART A)

	// default instance
	std::shared_future<int> sf1;

	// future shared with other future shared
	std::shared_future<int> sf2(std::async(squared, 3));
	std::shared_future<int> sf3{ sf2 };

	// transfer to future shared from normal future
	std::future<int> f{ std::async(squared, 3) };
	std::shared_future<int> sf4{ f.share() };

	// transfer to future shared from future shared
	std::shared_future<int> sf5{ std::move(sf4) };

	// PART B)

	// checking that member functions of future also works for shared_future
	sf2.valid();
	sf2.wait();
	sf2.get();
	//=> everything works as well


	// PART C)

	// calling twice a shared_future
	sf2.get();

	// PART D)

	// atomic variable to make sure that the loop ends after timeout
	std::atomic<bool> stop{ false };

	// shared future with function that never ends 
	std::shared_future<int> inf(std::async( InfiniteLoop, std::ref(stop)));

	// waiting for a certain time
	// std::future_status infStatus{ inf.wait_for(std::chrono::seconds(5)) };
	// OR (comment out exactly one)
	// wainting until a certain time
	std::future_status infStatus{ inf.wait_until(std::chrono::steady_clock::now()+ std::chrono::seconds(5)) };

	// wainting for n seconds and checking if it becomes ready
	while (infStatus != std::future_status::timeout) {

		if (infStatus == std::future_status::ready) { 
			std::cout << "function1 yielded a result" << std::endl;
			break;
		}
	};
	// showing output 
	if (infStatus == std::future_status::timeout) { 
		stop = true;
		std::cout << "request timed out" << std::endl; 
	}
	else { std::cout << "function1 is " << inf.get() << std::endl; };



};