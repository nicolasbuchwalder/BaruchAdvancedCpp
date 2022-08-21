// Level3_Section1_Exercise3.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course


#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <string>
#include <system_error>






// PART A)

std::mutex mutex1;
// function that will be on multiple threads, using lock_guard wrapper and a counter for all threads

int counterLockGuard{ 0 };

void functionLockGuard(std::string query) {
	// locking function by applying lock guard wrapper to the mutex
	const std::lock_guard<std::mutex> lock(mutex1);
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "query: " << query << std::endl;
	++counterLockGuard;

};

// PART C)

std::mutex mutex2;

// function that be on multiple threads, using unique_lock class instead of lock_guard

void functionUniqueLock(std::string query) {
	// warpping mutex in the unique_lock wrapper
	// adding defer_lock to not lock it (no ownership)
	std::unique_lock<std::mutex> lock(mutex2, std::defer_lock);
	// trying to lock it
	try {
		// continuous trying
		while (true) {
			// if locking is successful, launch function
			if (lock.try_lock()) {
				std::this_thread::sleep_for(std::chrono::seconds(1));
				std::cout << "query: " << query << std::endl;
				// PART E)
				lock.unlock();
				return;
			}
		}
	}
	// if errors in the mutex
	catch (const std::system_error& ec) {
		// exception that there is no associated mutex
		if (ec.code() == std::errc::operation_not_permitted) { std::cout << "no associated mutex" << std::endl; };
		// ecption that the mutex is already locked
		if (ec.code() == std::errc::resource_deadlock_would_occur) { std::cout << "mutex is already locked" << std::endl; };
	};
};


// PART D)

// we now need a timed mutex
std::timed_mutex timed_mutex;

// function that be on multiple threads, still using unique_lock class but with try_lock_for, so only tried for a certain time

void functionUniqueLockFor(std::string query) {
	// warpping mutex in the unique_lock wrapper
	// adding defer_lock to not lock it (no ownership)
	std::unique_lock<std::timed_mutex> lock(timed_mutex, std::defer_lock);
	// trying to lock it
	try {
		// continuous trying
		while (true) {
			// if locking is successful within 2 seconds, launch function
			if (lock.try_lock_for(std::chrono::seconds(2))) {
				std::this_thread::sleep_for(std::chrono::seconds(1));
				std::cout << "query: " << query << std::endl;
				// PART E)
				lock.unlock();
				return;
			}
		}
	}
	// if errors in the mutex
	catch (const std::system_error& ec) {
		// exception that there is no associated mutex
		if (ec.code() == std::errc::operation_not_permitted) { std::cout << "no associated mutex" << std::endl; };
		// ecption that the mutex is already locked
		if (ec.code() == std::errc::resource_deadlock_would_occur) { std::cout << "mutex is already locked" << std::endl; };
	};
};


// PART F)

// function that be on multiple threads, still using unique_lock class but with try_lock_until, so only tries until a certain timestamp

void functionUniqueLockUntil(std::string query) {
	// warpping mutex in the unique_lock wrapper
	// adding defer_lock to not lock it (no ownership)
	std::unique_lock<std::timed_mutex> lock(timed_mutex, std::defer_lock);
	// trying to lock it
	try {
		// continuous trying until certain timestamp
		auto now{ std::chrono::steady_clock::now() };
		while (true) {
			// if locking is successful within 2 seconds, launch function
			if (lock.try_lock_until(now + std::chrono::seconds(2))) {
				std::this_thread::sleep_for(std::chrono::seconds(1));
				std::cout << "query: " << query << std::endl;
				// PART E)
				lock.unlock();
				return;
			}
		}
	}
	// if errors in the mutex
	catch (const std::system_error& ec) {
		// exception that there is no associated mutex
		if (ec.code() == std::errc::operation_not_permitted) { std::cout << "no associated mutex" << std::endl; };
		// ecption that the mutex is already locked
		if (ec.code() == std::errc::resource_deadlock_would_occur) { std::cout << "mutex is already locked" << std::endl; };
	};
};


int main() {

	// PART A)

	std::chrono::time_point< std::chrono::system_clock> start{ std::chrono::system_clock::now() };

	// creating threads
	std::thread t1{ functionLockGuard, "one" };
	std::thread t2{ functionLockGuard, "two" };
	std::thread t3{ functionLockGuard, "three" };
	t1.join();
	t2.join();
	t3.join();
	// => we notice that now they all run one after the other, but in no specific order

	std::chrono::time_point< std::chrono::system_clock> end{ std::chrono::system_clock::now() };
	std::chrono::duration<double> duration{ end - start };
	std::cout << "threads with lock guard " << duration.count() << "s" << std::endl;

	std::cout << "Counter at : " << counterLockGuard << std::endl;
	//=> three counts as expected

	// PART C)

	start = std::chrono::system_clock::now();

	// creating threads
	std::thread t4{ functionUniqueLock, "four" };
	std::thread t5{ functionUniqueLock, "five" };
	std::thread t6{ functionUniqueLock, "six" };
	t4.join();
	t5.join();
	t6.join();
	end = std::chrono::system_clock::now();
	duration = end - start;
	std::cout << "threads with unique lock " << duration.count() << "s" << std::endl;

	// PART D)

	start = std::chrono::system_clock::now();

	// creating threads
	std::thread t7{ functionUniqueLockFor, "seven" };
	std::thread t8{ functionUniqueLockFor, "eight" };
	std::thread t9{ functionUniqueLockFor, "nine" };
	t7.join();
	t8.join();
	t9.join();
	end = std::chrono::system_clock::now();
	duration = end - start;
	std::cout << "threads with unique lock, try_lock_for " << duration.count() << "s" << std::endl;


	// PART F)

	start = std::chrono::system_clock::now();

	// creating threads
	std::thread t10{ functionUniqueLockUntil, "ten" };
	std::thread t11{ functionUniqueLockUntil, "eleven" };
	std::thread t12{ functionUniqueLockUntil, "twelve" };
	t10.join();
	t11.join();
	t12.join();
	end = std::chrono::system_clock::now();
	duration = end - start;
	std::cout << "threads with unique lock, try_lock_until " << duration.count() << "s" << std::endl;

	// PART G)
	// to release an associated mutex without unlockinging, we simply need to call std::unique_lock<std::mutex>::release method as:
	// lock.release();
}