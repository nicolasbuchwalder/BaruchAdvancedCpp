// Level3_Section4_Exercise6.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <thread>
#include <chrono>
#include <iostream>
#include <future>

// list of all functions in the program
int F1(int a) {
	std::this_thread::sleep_for(std::chrono::seconds(1));
	return ++a;
};
int F2(int a) {
	std::this_thread::sleep_for(std::chrono::seconds(1));
	return ++a;
};
int F3(int c) {
	std::this_thread::sleep_for(std::chrono::seconds(1));
	return ++c;
};
int F4(int b, int d) {
	std::this_thread::sleep_for(std::chrono::seconds(1));
	return b + d;
};

// PART C)

// F1 function with promises
void F1_promise(int a, std::promise<int>&& p) {
	std::this_thread::sleep_for(std::chrono::seconds(1));
	p.set_value(++a);
	return;
}
int main() {

	std::chrono::steady_clock::time_point start, end;

	// PART A)
	
	// single threaded 
	start = std::chrono::steady_clock::now();
	int a{ 1 };
	int res1{ F4(F1(a), F3(F2(a))) };
	end = std::chrono::steady_clock::now();
	std::cout << "single threaded lasts: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
	//=> 4042 miliseconds
	
	// PART B)

	// async and future
	start = std::chrono::steady_clock::now();
	// async on the left branch of the graph
	std::future<int> b_async{ std::async(F1, a) };
	int res2{ F4(b_async.get(), F3(F2(a)))};
	end = std::chrono::steady_clock::now();
	std::cout << "async and future lasts: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
	// => 3025 miliseconds: as F1 can run at the same time as F2, we gain one second
	
	// PART C)

	// promises
	std::promise<int> p;
	std::future<int> b_promise{ p.get_future() };

	start = std::chrono::steady_clock::now();

	// thread with the promise for the left branch of the graph 
	std::thread f1{ F1_promise, a, std::move(p) };
	int c_promise{ F3(F2(a)) };
	f1.join();
	int res3{ F4(b_promise.get(), c_promise) };
	end = std::chrono::steady_clock::now();
	std::cout << "promise lasts: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
	// => 3037 miliseconds: we still have the second less but not faster than async

	// PART D)
	
	// packaged tasks
	std::packaged_task<int(int)> t1{F1 };
	std::future<int> b_task{ t1.get_future() };

	// combining both functions of the right branch
	std::packaged_task<int(int)> t2{ [](int a) {return F3(F2(a)); } };
	std::future<int> d_task{ t2.get_future() };

	start = std::chrono::steady_clock::now();

	// running tasks
	std::thread f1_bis{ std::move(t1), a };
	std::thread f23{ std::move(t2), a };
	f1_bis.join();
	f23.join();

	int res4{ F4(b_task.get(), d_task.get()) };
	end = std::chrono::steady_clock::now();
	std::cout << "package_task lasts: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
	// => 3024 miliseconds: also about the same as well





}