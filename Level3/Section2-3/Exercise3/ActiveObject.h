// ActiveObject.h: This file contains the active class for the thread
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#pragma once

#include <thread>
#include <system_error>
#include <iostream>

// thread that will be with the ActiveObject (defined in main file)
std::thread thread;

class ActiveObject
{
private:
	// reference to thread instance
	std::thread& activeThread{ thread };

public:
	// explicit constructing accepting thread with function
	explicit ActiveObject(std::thread& thread)
		: activeThread{ thread } {
		std::cout << "active object constructor called" << std::endl;
	};

	// destroctor that checks if the thread is joinable and joins it
	~ActiveObject() {

		std::cout << "destructor called" << std::endl;

		if (activeThread.joinable()) { 
			activeThread.join();
			std::cout << "active thread joined" << std::endl;
		}
		else {
			 // trying to join even if its not joinable
			try { 
				activeThread.join(); 
				std::cout << "active thread joined" << std::endl;
			}
			// checking why the code is not joinable
			catch (const std::system_error& ec) {
				if (ec.code() == std::errc::invalid_argument) { std::cout << "thread has no thread function" << std::endl; }
				else { std::cout << ec.what() << std::endl; }

			};
			
		}
	}
};

