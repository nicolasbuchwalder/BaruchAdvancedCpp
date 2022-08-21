// Level3_Section1_Exercise2.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course




#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <string>

// PART A)

std::mutex mutex;
// function that will be on multiple threads, now using mutex to lock things
void functionMutex(std::string query) {
	mutex.lock();
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "query: " << query << std::endl;
	mutex.unlock();
};

// PART B)

// function that will be on multiple threads, but now implemented with try_lock in order to look at how long that takes
// for the attempts counts, we cannot use the same function (callables for  threads cannot have arguments aby reference)
// so we create two almost identical functions with just different attempts counts variables
int attemps1{ 0 };
void functionMutexTryLock1(std::string query) {
	// trying to lock the mutex on an infinite look
	while (true) {
		if (mutex.try_lock()) {
			// doing as in last function after being locked
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::cout << "query: " << query << std::endl;
			mutex.unlock();
			// returning to escapte the while true loop
			return;
		}
		else {
			++attemps1;
		};
	}
};

int attemps2{ 0 };
void functionMutexTryLock2(std::string query) {
	// trying to lock the mutex on an infinite look
	while (true) {
		if (mutex.try_lock()) {
			// doing as in last function after being locked
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::cout << "query: " << query << std::endl;
			mutex.unlock();
			// returning to escapte the while true loop
			return;
		}
		else {
			++attemps2;
		};
	}
};

int attemps3{ 0 };
void functionMutexTryLock3(std::string query) {
	// trying to lock the mutex on an infinite look
	while (true) {
		if (mutex.try_lock()) {
			// doing as in last function after being locked
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::cout << "query: " << query << std::endl;
			mutex.unlock();
			// returning to escapte the while true loop
			return;
		}
		else {
			++attemps3;
		};
	}
};


// PART C)

// same function as part a but without unlock
void functionDeadLock(std::string query) {
	mutex.lock();
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "query: " << query << std::endl;
};

int main() {

	// PART A)
	
	std::chrono::time_point< std::chrono::system_clock> start{ std::chrono::system_clock::now() };

	// creating threads
	std::thread t1{ functionMutex, "one"};
	std::thread t2{ functionMutex, "two"};
	std::thread t3{ functionMutex, "three" };
	t1.join();
	t2.join();
	t3.join();
	// => we notice that now they all run one after the other, but in no specific order

	std::chrono::time_point< std::chrono::system_clock> end{ std::chrono::system_clock::now() };
	std::chrono::duration<double> duration{ end - start };
	std::cout << "threads with lock took " << duration.count() << "s" << std::endl;


	// PART B)

	start = std::chrono::system_clock::now();

	// creating threads
	std::thread t4{ functionMutexTryLock1, "one" };
	std::thread t5{ functionMutexTryLock2, "two" };
	std::thread t6{ functionMutexTryLock3, "three" };
	t4.join();
	t5.join();
	t6.join();

	std::cout << "attempts t4: " << attemps1 << std::endl;
	std::cout << "attempts t5: " << attemps2 << std::endl;
	std::cout << "attempts t6: " << attemps3 << std::endl;

	end = std::chrono::system_clock::now();
	duration =  end - start ;
	std::cout << "threads with try_lock took " << duration.count() << "s" << std::endl;
	//=> we notice that threads with try_lock are a lot quicker even if a lot of attempts are made

	// PART C)

	//std::thread t7{ functionDeadLock, "one" };
	//std::thread t8{ functionDeadLock, "two" };
	//=> fails at runtime because t7 cannot be launched because of the deadlock

}