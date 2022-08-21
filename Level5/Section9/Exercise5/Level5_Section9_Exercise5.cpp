// Level5_Section9_Exercise5.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <boost/signals2/signal.hpp>
#include <iostream>

// PART A)

// Using boost Function library
using FunctionType = boost::function<void(double)>;
using SignalType = boost::signals2::signal<void(double)>;

class Subject
{
    private:
        // signal where slots will be connected
        SignalType attentionList;
    public:
        // initializing empty signal
        Subject() { attentionList = SignalType(); }
        // adding slot to signal
        void AddObserver(const FunctionType& ft)
        {
            attentionList.connect(ft);
        }
        // running signal
        void ChangeEvent(double x)
        {
            attentionList(x);
        }
};

// PART B)

// GIVEN CODE

void CPrint(double x)
{
    std::cout << "C function: " << x << std::endl;
}

struct Print{
    void operator() (double x)
    {
        std::cout << "I am a printer " << x << std::endl;
    }
};


int main() {

    // PART C)

    // GIVEN CODE

    // Create the notifier
    Subject mySubject;

    // Create the attention list
    Print myPrint;

    mySubject.AddObserver(myPrint);
    mySubject.AddObserver(&CPrint);

    // Trigger the event
    std::cout << "Give the value: "; double val; std::cin >> val;
    mySubject.ChangeEvent(val);


}