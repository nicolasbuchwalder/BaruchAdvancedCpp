// TMPClass.h: This is a class that allows pre and post processing on a vector, 
// for any input and output functions. @Nicolas Buchwalder

#pragma once

#include <vector>
#include <functional>
#include <algorithm>


using InputFunction = std::function<double()>;
using OutputFunction = std::function<void(const std::vector<double>&)>;

class TMPClass final
{
// PART A)

private:
	std::vector<double> vec;
	InputFunction in_function;
	OutputFunction out_function;

public:
// PART B)
	// consttructor with the size of vector, the value of each element and the functions
	TMPClass(std::size_t n, double startValue, InputFunction iFunction, OutputFunction oFunction) {
		in_function = iFunction;
		out_function = oFunction;
		for (int i{ 0 }; i < n; ++i) { vec.push_back(startValue); };
	};
	// applying both in and out functions
	void out() {
		std::transform(vec.begin(), vec.end(), vec.begin(), [this](double i) {return i * in_function(); });
		return out_function(vec);
	}
};

