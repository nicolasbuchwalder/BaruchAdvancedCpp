// Level3_Section4_Exercise4.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include <future>
#include <queue>
#include <array>


// GIVEN CODE
// Thread function
double compute(double x, double y)
{
    // Wait a while
    std::default_random_engine dre(42);
    std::uniform_int_distribution<int> delay(0, 100);
    std::this_thread::sleep_for(std::chrono::milliseconds(delay(dre)));

    return std::cos(x) * std::exp(y);
}

int main() {

    // PART A)

    // GIVEN CODE

    double x = 0.0; double y = 2.71;
    // A. 'Direct' tasks
    std::future<double> fut = std::async(compute, x, y);

    // Get the shared data
    double result = fut.get();
    std::cout << "Result: " << result << '\n';

    // PART B)

    // packaged task for the function
    std::packaged_task<double(double, double)> task{ compute };

    // getting future
    std::future<double> f{ task.get_future() };

    // creating thread by moving task as callable
    std::thread t{ std::move(task), x, y };

    // joining thread
    t.join();

    // PART C)

    // creating queue of packaged tasks
    std::queue<std::packaged_task<double(double, double)>> queuedTasks;

    // creating arrays of x and y for the queued task
    std::array<double, 5> x_list{ -2, -1, 0, 1, 2 };
    std::array<double, 5> y_list{ -2, -1, 0, 1, 2 };
    int numTasks{ 25 };

    // building queue from packaged tasks
    for (int i{ 0 }; i < numTasks; ++i) {

        // creating packaged task that will be moved
        std::packaged_task<double(double, double)> taskMove{ compute };

        // moving packaged task to queue
        queuedTasks.push(std::move(taskMove));
    };

    // dequeuing 
    for (int i{ 0 }; i < numTasks; ++i) {

        // getting future from the first task in the queue
        std::future<double> nextTask = queuedTasks.front().get_future();

        // computing task (doint all combinations)
        queuedTasks.front()(x_list[i % 5], y_list[i / 5]);

        // showing result
        std::cout << "compute for " << x_list[i % 5] << " and " << y_list[i / 5] << " equals " << nextTask.get() << std::endl;

        // removing computed task from list
        queuedTasks.pop();
    };
}