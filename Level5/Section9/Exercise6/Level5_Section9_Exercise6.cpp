// Level5_Section9_Exercise6.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <iostream>
#include <boost/signals2/signal.hpp>

// PART A)

void init(double& x) {
	std::cout << "data initialised" << std::endl;
};

void check(double& x) {
	if (x < 2 || x > 4) { x = 3; };
	std::cout << "data checked" << std::endl;
};

void modify(double& x) {
	x *= x;
	std::cout << "data modified" << std::endl;
};

void print(double& x) {
	std::cout << "data printed: " << x << std::endl;
}


int main() {

	// PART A)

	// four signals for the four layers of GOF pattern
	boost::signals2::signal<void(double& d)> ExteriorSig;
	boost::signals2::signal<void(double& d)> HardwareSig;
	boost::signals2::signal<void(double& d)> DataSig;
	boost::signals2::signal<void(double& d)> CommunicationSig;

	ExteriorSig.connect(boost::ref(init));
	HardwareSig.connect(boost::ref(check));
	DataSig.connect(boost::ref(modify));
	CommunicationSig.connect(boost::ref(print));

	// PART B)
	
	// connecting signals in opposite order so that the sequence is init->check->modify->print
	
	CommunicationSig.connect(0, boost::ref(DataSig));
	DataSig.connect(1, boost::ref(HardwareSig));
	HardwareSig.connect(2, boost::ref(ExteriorSig));
	
	double value = -3.7; // in range [2.0, 5.0]
	CommunicationSig(value);
	//=> order is correct

}