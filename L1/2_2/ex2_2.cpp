#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <chrono>
#include <algorithm>

// Given code
template < typename T >
void SwapCopyStyle(T& a, T& b)
{
    // Swap a and b in copying way; temporary object needed
    T tmp(a); // Copy constructor
    a = b; // Copy all elements from b to a
    b = tmp; // Copy all elements from tmp to b
}


// Template function for part c)
template <typename T>
void SwapMoveStyle(T& a, T& b)
{
    T tmp(a);
    a = std::move(b);
    b = std::move(tmp);

}
// printing vector function

void printVector(std::vector<double>& v){
        for (auto i : v)
            std::cout << i << ' ' ;
        std::cout << std::endl;
    };

int main()
{
    // PART A)

    std::string sourcestr{"hello"};
    std::string targetstr{"world"};
    std::cout << "source and target string before move: 1: \""<< sourcestr << "\" , 2: \""<< targetstr << "\""<< std::endl;

    targetstr = std::move(sourcestr);

    std::cout << "source and target string after move: 1: \""<< sourcestr << "\" , 2: \""<< targetstr << "\""<< std::endl; 

    // => the source string is now empty and the target is exactly the source string, this was the expected behavior

    // PART B)

    std::vector<double> initvec {1.0, 1.41, 3.14, 2.71, 10.0};

    auto startCopy{std::chrono::steady_clock::now()};
    std::vector<double> copyvec{initvec};
    auto endCopy{std::chrono::steady_clock::now()};
    auto CopyTime = endCopy - startCopy;

    auto startAssign{std::chrono::steady_clock::now()};
    std::vector<double> assignvec{};
    assignvec = initvec;
    auto endAssign{std::chrono::steady_clock::now()};
    auto AssignTime = endAssign - startAssign;

    std::vector<double> movevec1{};
    std::cout << "first and second vectors before move:\n\t1: "; printVector(initvec);  std::cout << "\t2: "; printVector(movevec1);
    movevec1 = std::move(initvec);
    std::cout << "first and second vectors after move:\n\t1: "; printVector(initvec);  std::cout << "\t2: "; printVector(movevec1);

    auto startMove{std::chrono::steady_clock::now()};
    std::vector<double> movevec2{};
    movevec2 = std::move(initvec);
    auto endMove{std::chrono::steady_clock::now()};
    auto MoveTime = endMove - startMove;


    std::cout << "Ellapsed times are: copy: " << CopyTime.count() << ", assign: " << AssignTime.count() << ", move: " << MoveTime.count() << std::endl;
    // => move is way more efficient than copy or assign (about 1/3 of the time of the two others)


    // PART C)
    std::array<int, 100> vec1;
    std::array<int, 100> vec2;
    std::generate(vec1.begin(), vec1.end(), rand);
    std::generate(vec2.begin(), vec2.end(), rand);

    auto startCopySwap{std::chrono::steady_clock::now()};
    SwapCopyStyle(vec1, vec2);
    auto endCopySwap{std::chrono::steady_clock::now()};
    auto CopySwapTime = endCopySwap - startCopySwap;

    // => three copies are made

    auto startMoveSwap{std::chrono::steady_clock::now()};
    SwapMoveStyle(vec1, vec2);
    auto endMoveSwap{std::chrono::steady_clock::now()};
    auto MoveSwapTime = endMoveSwap - startMoveSwap;

    // => no copies are made

    std::cout << "Ellapsed times for swap are: copy: " << CopySwapTime.count() << ", move: " << MoveSwapTime.count() << std::endl;
    // => move is way more efficient than copy (about 1/2 of the time of copy)
}