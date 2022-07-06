// Level1_Section1_Exercise1.cpp: This file contains all the code for this exercise.

#include <iostream>
#include <algorithm>
#include <vector>

// method to print vector
void printVector(std::vector<double>& v) {
    for (auto i : v)
        std::cout << i << ' ';
    std::cout << std::endl;
};


int main() {

    // PART A) and B) (see printVector function above)

    double multiplicator{ 3.14 };
    std::vector<double> vec{ 0.0, 1.0, 2.0, 3.0, 4.0 };

    // lambda capture by reference
    std::transform(vec.begin(), vec.end(), vec.begin(), [=](double& i) {return multiplicator * i; });
    std::cout << "Capture by value: ";
    printVector(vec);

    // lambda capture by reference
    vec = { 0.0, 1.0, 2.0, 3.0, 4.0 };
    std::transform(vec.begin(), vec.end(), vec.begin(), [&](double& i) {return multiplicator * i; });
    std::cout << "Capture by reference: ";
    printVector(vec);

    //=> nothing changes: we have the same results

    // PART C) 
    vec = { 3.0, 1.0, 2.0, 4.0, 0.0 };
    //getting a pair from the min and max of the vector (as std::min/max_element gives the index, we get the value by *)
    auto minmax = [](std::vector<double> vec) {return std::make_pair(*std::min_element(vec.begin(), vec.end()), *std::max_element(vec.begin(), vec.end())); };
    auto res_minmax = minmax(vec);

    std::cout << "min is : " << res_minmax.first << ", max is : " << res_minmax.second << std::endl;

    // PART D)

    vec = { 3.0, 1.0, 2.0, 4.0, 0.0 };

    auto minmax_std = std::minmax_element(vec.begin(), vec.end());
    std::cout << "min is : " << res_minmax.first << ", max is : " << res_minmax.second << std::endl;

    // => we get the same results, minmax_element is a lot clearer but the lambda can be calculated only by calling the vector (instead of begin and end)


}
