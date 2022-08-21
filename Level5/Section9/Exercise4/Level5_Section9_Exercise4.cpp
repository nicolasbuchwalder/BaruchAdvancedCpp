// Level5_Section9_Exercise4.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <boost/signals2/signal.hpp>
#include <iostream>

// PART B)

// function template to add every slot together
template <typename T>
struct SumCombiner {
    // singal2 needs result_type alias
    using result_type = T;
    template <typename InputIterator>
    result_type operator()(InputIterator first, InputIterator last) const {
        result_type res{0};
        while (first != last) {
            res += *first; 
            ++first;
        }
        return res;
    }
};

int main() {

    // PART A)

    auto s1 = [](int x, int y) {return x + y + 1; };

    auto s2 = [](int x, int y) {return x + y + 2; };

    auto s3 = [](int x, int y) {return x + y + 3; };


    boost::signals2::signal<int(int x, int y), SumCombiner<int>> sig;
    sig.connect(boost::ref(s1));
    sig.connect(boost::ref(s2));
    sig.connect(boost::ref(s3));

    std::cout << sig(1, 1);
    //=> we have indeed 3*(1+1) + 6 = 12, the combiner works


}