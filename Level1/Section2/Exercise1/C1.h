#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class C1
{
private:
    std::vector<double> m_vec;

    C1(const C1& copy) = delete;
    C1& operator= (const C1& copy) = delete;

public:
    C1() = default;
    C1(std::vector<double> vec) : m_vec{ vec } { std::cout << "C1 constructor has been called." << std::endl; };
    ~C1() { std::cout << "C1 destructor has been called." << std::endl; };

    void print()
    {
        std::cout << '[';
        for (auto i : m_vec) std::cout << i << ' ';
        std::cout << ']' << std::endl;
        std::cout << "C1 print function has been called." << std::endl;
    };

    void multiply(const double multiplicator)
    {
        std::transform(m_vec.begin(), m_vec.end(), m_vec.begin(), [=](auto& i) {return i * multiplicator; });
        std::cout << "C1 multiply function has been called." << std::endl;
    };
};
