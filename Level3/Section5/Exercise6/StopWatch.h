// StopWatch.h: This file contains the class StopWatch for timing operations
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#pragma once

#include <chrono>
class StopWatch
{
private:
    // timestamps for start and end
    std::chrono::steady_clock::time_point start, end;

    // standard copy constructor
    StopWatch(const StopWatch& copy) {
        this->start = copy.start;
        this->end = copy.end;
    };

    StopWatch& operator=(const StopWatch& copy) {
        StopWatch newWatch(copy);
        return newWatch;
    };

public:
    // default constructor
    StopWatch() {};

    // setting start to now
    void StartStopWatch() { start = std::chrono::steady_clock::now(); };
    // setting end to now
    void StopStopWatch() { end = std::chrono::steady_clock::now(); };

    // we do both at the same time to reset
    void Reset() {
        start = std::chrono::steady_clock::now();
        end = start;
    };

    // simply take the difference between start and end
    double GetTime() const {
        std::chrono::duration<double> time{ end - start };
        return time.count();
    }


};

