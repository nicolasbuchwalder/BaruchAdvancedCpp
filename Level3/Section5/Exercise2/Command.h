// Command.h: This file contains the class for commands
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#pragma once

#include <functional>
#include <boost\thread.hpp>


// GIVEN CODE

using FunctionType = std::function<double(double)>;

class Command
{
private:
    long ID; // priority of command
    FunctionType algo;
public:
    Command(const FunctionType& algorithm, long priority)
        : algo(algorithm), ID(priority) {}

    // adding const qualifer to execute directly
    void Execute(double x) const {
        // Introduce delay to simulate a heavy algorithm
        boost::this_thread::sleep(
            boost::posix_time::millisec(5000));
        std::cout << algo(x) << '\n';
    }

    int priority() const
    {
        return ID;
    }
};


