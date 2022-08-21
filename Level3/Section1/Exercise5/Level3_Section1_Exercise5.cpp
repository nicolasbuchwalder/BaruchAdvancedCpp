// Level3_Section1_Exercise5.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <atomic>
#include <thread>
#include <mutex>
#include <chrono>
#include <iostream>

int main() {

	// PART A)

	std::atomic<long long> atomicLongLong;
	std::atomic<bool> atomicBool;
	std::atomic<int> atomicInt;

	// PART B)

	std::cout << "atomic long long is lock free: " << std::boolalpha << std::atomic_is_lock_free(&atomicLongLong) << std::endl;
	std::cout << "atomic bool is lock free: " << std::boolalpha << std::atomic_is_lock_free(&atomicBool) << std::endl;
	std::cout << "atomic int is lock free: " << std::boolalpha << std::atomic_is_lock_free(&atomicInt) << std::endl;
	//=> all lock free

	// PART C)
	// atomically replacing one atomic by another
	atomicLongLong.store(atomicBool);

	// PART D)
	atomicInt = 3;
	std::cout << "atomic int is: " << atomicInt.load() << std::endl;
}