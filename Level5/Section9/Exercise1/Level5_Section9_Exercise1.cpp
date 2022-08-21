// Level5_Section9_Exercise1.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <boost/signals2.hpp>
#include <iostream>
#include <boost/functional.hpp>

// PART A)

// free function
void freefunc() {
	std::cout << "free function" << std::endl;
};

// lambda function
auto lambda = []() {std::cout << "lambda function" << std::endl; };

// function obkect
struct Object {
	void operator()() {
		std::cout << "function object" << std::endl;
	};
};

// GIVEN CODE

struct MyStruct
{
	double val;
	MyStruct(double v) { val = v; }
	void modify(double newValue)
   {
	   val = newValue;
	   std::cout << "A third slot " << val << std::endl;
   }
};


int main() {

	// PART A)

	boost::signals2::signal<void()> signal;

	// creating slots for all functions
	signal.connect(boost::ref(freefunc));
	signal.connect(boost::ref(lambda));
	Object obj;
	signal.connect(boost::ref(obj));

	signal();
	// => all three functions are called
	std::cout << "-------" << std::endl;

	// PART B)

	MyStruct mystruct(1);

	// as the callable is not direclty the MyStruct object, a binding to the modify function is necessary
	auto modifier = boost::bind(&MyStruct::modify, &mystruct, 2);
	signal.connect(boost::ref(modifier));

	signal();
	//=> this binding calls indeed modify, (other slots in signal are called again)
	std::cout << "-------" << std::endl;

	// PART C)

	signal.disconnect(boost::ref(freefunc));
	signal.disconnect(boost::ref(lambda));
	signal.disconnect(boost::ref(obj));
	signal.disconnect(boost::ref(modifier));

	signal();
	//=> everything has been removed indeed
	std::cout << "-------" << std::endl;

	// PART D)

	// GIVEN CODE

	// Define potential emitters
	boost::signals2::signal<void()> signalA;
	boost::signals2::signal<void()> signalB;
	boost::signals2::signal<void()> signalC;
	boost::signals2::signal<void()> signalD;

	// Define slots
	auto slotB = []() {std::cout << "Slot B called by B\n " << std::endl; };
	auto slotC = []() {std::cout << "Slot C called by C\n " << std::endl; };
	auto slotD1 = []() {std::cout << "Slot D1 called by D\n " << std::endl; };
	auto slotD2 = []() {std::cout << "Slot D2 called by D\n " << std::endl; };

	signalA.connect(boost::ref(signalB));
	signalB.connect(boost::ref(signalC));
	signalC.connect(boost::ref(signalD));
	signalB.connect(boost::ref(slotB));
	signalC.connect(boost::ref(slotC));
	signalD.connect(boost::ref(slotD1));
	signalD.connect(boost::ref(slotD2));

	signalA();
	//=> it runs the slots from the furthest signal first (D) all the way up to the first signal (A)

	std::cout << "-------" << std::endl;


	signalB.disconnect(boost::ref(signalC));
	signalA();
	//=> works without disconnecting the terminal slot

}