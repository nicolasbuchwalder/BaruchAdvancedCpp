// Level5_Section9_Exercise3.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <boost/signals2/signal.hpp>
#include <iostream>

// GIVEN CODE

struct BootstrapCheck
{
    // Iterate in slots and return first 'false'
    // value; otherwise, 'true'
    typedef bool result_type;
    template <typename InputIterator>
    bool operator()(InputIterator first, InputIterator last) const
    {
        while (first != last)
        {
            if (!*first)
                return false;
           ++first;
        }
        return true;
    }
};


int main() {

    boost::signals2::signal<bool(), BootstrapCheck> sig;

    // PART B)

    auto s1 = []() {std::cout << "slot1" << std::endl; return true; };
    auto s2 = []() {std::cout << "slot2" << std::endl; return false; };
    auto s3 = []() {std::cout << "slot3" << std::endl; return true; };

    // PART C)

    sig.connect(boost::ref(s1));
    sig.connect(boost::ref(s2));
    sig.connect(boost::ref(s3));

    sig();
    //=> iteration stopped after second slot, as expected


}