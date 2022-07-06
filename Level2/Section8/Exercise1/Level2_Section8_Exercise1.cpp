// Level2_Section8_Exercise1.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <iostream>
#include <bitset>
#include <boost/dynamic_bitset.hpp>
#include <string>


// template function to print the dynamic bitset
template <typename T>
void print(const boost::dynamic_bitset<T>& bitSet)
{
    for (int i = 0; i < bitSet.size(); ++i) { std::cout << bitSet[i]; };
    std::cout << std::endl;
};


int main()
{
    // PART A)
    // 
    // creating bitset from unsigned long and unsigned long long
    boost::dynamic_bitset<unsigned long> unsingLong(3);
    std::cout << "unsigned long: ";
    print(unsingLong);

    boost::dynamic_bitset<unsigned long long> unsingLongLong(3);
    unsingLongLong[0] = 1; unsingLongLong[1] = 0; unsingLongLong[2] = 1;
    std::cout << "unsigned long long: ";
    print(unsingLongLong);

    // PART B) 
    
    std::string binaryString = "01010";
    unsigned int start_idx{1};
    unsigned int num_bits{2};

    // creating bitset from full string
    std::bitset<5> fullStrBitset{ binaryString };
    std::cout << "full string is: " << fullStrBitset << std::endl;

    // creating bitset from parts of strings
    std::bitset<2> partialStrBitset{ binaryString, start_idx, num_bits};
    std::cout << "parital string is: " << partialStrBitset << std::endl;

    // PART C)
    // exception handling for out of range values
    try {

        std::string testString1 = "010101010";
        // 42 is out of range
        std::bitset<5> testBitset1{ testString1 , 42 };
    }
    catch (const std::out_of_range& err)
    {
        std::cout << "Error: starting value of out range" << std::endl;
    }
    // exception handling for invalid arguments values
    try {
        
        std::string testString2 = "fwhafs";
        std::bitset<6> testBitset2{ testString2 };
    }
    catch (const std::invalid_argument& err) //catching invalid bitset
    {
        std::cout << "Error: invalid string to build bitset from" << std::endl;
    }

    // PART D)
    // 
    // setting bitsets in differents ways
    std::bitset<3> bitset;
    std::cout << "bitset at initialisation: " << bitset << std::endl;

    // setting all bits (to 1 by default)
    std::cout << "bitset.set(): " << bitset.set() << std::endl;
    // resetting all bits
    std::cout << "bitset.reset(): " << bitset.reset() << std::endl;
    // flip
    std::cout << "bitset.flip(): " << bitset.flip() << std::endl;
    // none all, any
    std::cout << "bitset.none(): " << bitset.none() << std::endl;
    std::cout << "bitset.all(): " << bitset.all() << std::endl;
    std::cout << "bitset.any(): " << bitset.any() << std::endl;
    // accessing elements
    std::cout << "bitset.test(0): " << bitset.test(0) << std::endl;
    std::cout << "bitset[0]: " << bitset[0] << std::endl;
    // count number of set bits
    std::cout << "bitset.count(): " << bitset.count() << std::endl; 


    // PART E)
    // converting bitset to std::string, unsigned long, unsigned long long 

    std::bitset<3> stringBitset(bitset);
    std::bitset<3> unsingLongBitset(bitset);
    std::bitset<3> unsingLongLongBitset(bitset);

    std::cout << "string format: " << stringBitset.to_string() << std::endl;
    std::cout << "unsigned long format: " << unsingLongBitset.to_ulong() << std::endl;
    std::cout << "unsigned long oong format: " << unsingLongLongBitset.to_ullong() << std::endl;
    //=> both unsigned long and unsigned long long yields the same result

    // Part F)
    // testing is two bitsets are equal or unequal
    std::bitset<5> b1;
    b1.set();
    std::bitset<5> b2;
    b2.set();
     
    std::cout << b1 << " and " << b2 << " are equal: " << (b1 == b2) << std::endl;
    b2.reset();
    std::cout << b1 << " and " << b2 << " are equal: " << (b1 == b2) << std::endl;
    //=> works as expected

}