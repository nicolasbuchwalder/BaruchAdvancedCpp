// Level5_Section4-6_Exercise3.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include "Point.h"
#include <unordered_set>
#include <boost/unordered_set.hpp>
#include <functional>
#include <boost/functional/hash.hpp>
#include <chrono>
#include <iostream>


// PART A)

// GIVEN CODE (last exercise)
struct PointHash : std::unary_function<Point, std::size_t> {
    std::size_t operator()(const Point& pt) const {
        std::size_t seed = 0;
        boost::hash_combine(seed, pt.x());
        boost::hash_combine(seed, pt.y());
        return seed;
    }
};

// PART B)

// custom hash function
struct customPointHash : std::unary_function<Point, std::size_t> {
    std::size_t operator()(const Point& pt) const {
        // custom function that does not use boost/stl hash
        std::size_t hash_value = std::hash<double>()(pt.x()) + 100 * std::hash<double>()(pt.y());
        return hash_value;
    }
};


int main() {


    std::chrono::steady_clock::time_point start, end;

    // PART A)

    boost::unordered_multiset<Point, PointHash> pointSet;

    // creating multiset
    start = std::chrono::steady_clock::now();
    for (int i{ 0 }; i < 10; ++i) { pointSet.emplace(Point(i % 3, i / 3)); };
    end = std::chrono::steady_clock::now();
    std::cout << "time to create multiset: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()  << "mus" << std::endl;

    // erasing multiset
    start = std::chrono::steady_clock::now();
    for (auto it{ pointSet.begin() }; it != pointSet.end(); ++it) {
        it = pointSet.erase(it); 
    };
    end = std::chrono::steady_clock::now();
    std::cout << "time to erase multiset: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "mus" << std::endl;
    
    
    // PART B)

    boost::unordered_multiset<Point, customPointHash> custompointSet;

    // creating multiset with custom hash function
    start = std::chrono::steady_clock::now();
    for (int i{ 0 }; i < 10; ++i) { custompointSet.emplace(Point(i % 3, i / 3)); };
    end = std::chrono::steady_clock::now();
    std::cout << "time to create multiset with custom hash function: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "mus" << std::endl;

    // erasing multisetwith custom hash function
    start = std::chrono::steady_clock::now();
    for (auto it{ custompointSet.begin() }; it != custompointSet.end(); ++it) {
        it = custompointSet.erase(it);
    };
    end = std::chrono::steady_clock::now();
    std::cout << "time to erase multiset with custom hash function: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "mus" << std::endl;

    // => custom hash function in this case is a lot faster for some reason

    // PART C)

    std::unordered_multiset<Point, customPointHash> stdCustompointSet;

    // creating multiset with custom hash function
    start = std::chrono::steady_clock::now();
    for (int i{ 0 }; i < 10; ++i) { stdCustompointSet.emplace(Point(i % 3, i / 3)); };
    end = std::chrono::steady_clock::now();
    std::cout << "time to create std multiset with custom hash function: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "mus" << std::endl;

    // erasing multisetwith custom hash function
    start = std::chrono::steady_clock::now();
    for (auto it{ stdCustompointSet.begin() }; it != stdCustompointSet.end(); ++it) {
        it = stdCustompointSet.erase(it);
    };
    end = std::chrono::steady_clock::now();
    std::cout << "time to erase std multiset with custom hash function: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "mus" << std::endl;

    // => std library is even quicker!
}