// Level3_Section4_Exercise5.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <vector>
#include <iostream>
#include <chrono>
#include <numeric>
#include <future>
#include <omp.h>
#include <thread>
#include <future>



// PART B)

// recursive way of calulcating the sum (dividing array into two subarrays	
double recursive(std::vector<double>&  vec, std::size_t startIdx, std::size_t endIdx) {
	//std::cout << startIdx << ", " << endIdx << std::endl;

	// computing directly if size is smaller than 1000
	if ((endIdx-startIdx < 1000) || ((endIdx - startIdx) / 2) < startIdx) {
		return std::accumulate(vec.begin() + startIdx, vec.begin() + endIdx, 0.0);
	}
	else {

		// creating future for async call for second part
		std::future<double> resFirstHalf{ std::async(std::launch::async, recursive, std::ref(vec), startIdx, (endIdx - startIdx) / 2) };

		// computing the whole
		return  resFirstHalf.get() + recursive(vec, (endIdx - startIdx) / 2, endIdx);
	}
}



int main() {

	std::chrono::steady_clock::time_point start, end;
	
	// PART A)

	// creating an array that is sin of x between 0 and 1
	std::vector<double> bigArray;
	int lengthArray{ 10'000'000 };
	for (int i{ 0 }; i < lengthArray; ++i) { bigArray.push_back(std::sin(i / (double)lengthArray)); };

	// checking how much time accumulate takes
	start = std::chrono::steady_clock::now();
	double accumulateSum = std::accumulate(bigArray.begin(), bigArray.end(), 0.0) ;
	end = std::chrono::steady_clock::now();
	std::cout << "accumulate result is: " << accumulateSum << " and took : " << std::chrono::duration_cast<std::chrono::microseconds>(end-start).count() << " microseconds" << std::endl;

	// PART B, C)

	
	// checking how much time the recursive async accumulate takes
	start = std::chrono::steady_clock::now();
	double asyncRecursiveSum = recursive(bigArray, 0, bigArray.size());
	end = std::chrono::steady_clock::now();
	std::cout << "recursive async accumulate result is: " << asyncRecursiveSum << " and took : " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds" << std::endl;

	// => for 10milion elements we have:
	//		accumulate: 84583 microseconds
	//		async accumulate: 78478 microseconds
	// => we notice that below 10M elements, accumulate is faster: 
	// => maybe the creation of certain elements in memory in the recursive function makes it slower

	// PART D)

	// GIVEN CODE
	omp_set_num_threads(2);
	// just setting the sumParallel variable to 0
	double sumParallel = 0;
	#pragma omp parallel for reduction (+:sumParallel)


	start = std::chrono::steady_clock::now();
	for (long i = 0; i < bigArray.size(); ++i)
	{
		sumParallel += bigArray[i];
	}
	end = std::chrono::steady_clock::now();
	std::cout << "openPM result is: " << sumParallel << " and took : " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds" << std::endl;
	// => openMP took more than the first two algorithms: 95323 microseconds
	// => I cannot say why because its functionning is no clear to me

	// PART E)

	// lambda function for 10 threads, (we split in 10 subparts) (with promise)
	auto threadAccumulate = [](std::vector<double>& vec, int subpart, std::promise<double> && p) {

		// getting a tenth of the size
		std::size_t tenth{ vec.size() / 10 };

		// doing accumlate of the subpart (for the first 9)
		if (subpart != 9) {
			p.set_value(std::accumulate(vec.begin() + tenth * subpart, vec.begin() + tenth * (subpart + 1), 0.0));
		}
		// doing accumulate of the last subpart (because of the reminder)
		else {
			p.set_value(std::accumulate(vec.begin() + tenth * subpart, vec.end(), 0.0));
		}
		
		return;
	};

	
	start = std::chrono::steady_clock::now();
	double threadsSum{ 0 };

	// creating arrays of threads
	std::thread threads[10];
	
	// creating threads
	for (int i{ 0 }; i < 10; ++i) {
		// promise and future to get the value of the thread
		std::promise<double> p;
		std::future<double> f{ p.get_future() };
		threads[i] = std::thread(threadAccumulate, std::ref(bigArray), 0, std::move(p));
		// adding threds value to overall value
		threadsSum += f.get();
	}
	// joining threads
	for (int i{ 0 }; i < 10; ++i) {
		threads[i].join();
	}

	end = std::chrono::steady_clock::now();
	std::cout << "threads result is: " << threadsSum << " and took : " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds" << std::endl;
	// => this is the fastest yet: 71784 microsends

}