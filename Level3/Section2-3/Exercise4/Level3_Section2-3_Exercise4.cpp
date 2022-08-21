// Level3_Section2-3_Exercise4.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <string>
#include <mutex>
#include <atomic>
#include <thread>
#include <iostream>


// PART A)
// GIVEN CODE

// Types and data needed
std::string data;// Shared data between master and worker
std::mutex m; // Ensures no race condition

// Synchronization between master and worker
std::condition_variable cv;

// Initial state of worker and master
std::atomic<bool> workerReady = false;
std::atomic<bool> masterReady = false;


// PART B)

// function for the worker
void workerThread() {

	std::unique_lock<std::mutex> workerLock(m);
	
	// waiting for master (second arugment needs to be a function)
	cv.wait(workerLock, []() {return workerReady.load(); });
	
	// now master has flagged worker as ready, so processing is on
	data += "worker has worked";

	// now that worker is finished, master is done and we can unlock
	masterReady = true;
	workerLock.unlock();
	cv.notify_one();

}

// PART D)

// setting atomic flags
std::atomic_flag workerReadyFlag{ ATOMIC_FLAG_INIT };
std::atomic_flag masterReadyFlag{ ATOMIC_FLAG_INIT };

// same function as before but with atomic flags
void workerThreadFlag() {

	std::unique_lock<std::mutex> workerLock(m);

	// waiting for master (second arugment needs to be a function)
	cv.wait(workerLock, []() {return workerReadyFlag.test_and_set(); });

	// now master has flagged worker as ready, so processing is on
	data += "worker has worked";

	// now that worker is finished, master is done and we can unlock
	masterReadyFlag.test_and_set();
	workerLock.unlock();
	cv.notify_one();

}


int main()
{
	// PART C)
	
	// creating worker thread
	std::thread worker1(workerThread);

	// looping while the master thread has not finished
	{
		std::unique_lock<std::mutex> masterLock(m);

		// master flags worker as ready
		workerReady = true;

		// waiting master to be finished
		cv.wait(masterLock, []() { return masterReady.load(); });

	}
	worker1.join();

	std::cout << data << std::endl;
	
	// PART D)


	// creating worker thread
	std::thread worker2(workerThreadFlag);

	// looping while the master thread has not finished
	{
		std::unique_lock<std::mutex> masterLock(m);

		// master flags worker as ready
		workerReadyFlag.test_and_set();

		// waiting master to be finished
		cv.wait(masterLock, []() { return masterReadyFlag.test_and_set(); });

	}
	worker2.join();

	std::cout << data << std::endl;
}