#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class C
{
private:
    std::vector<double> m_vec;

public:
    C() {std::cout << "C default constructor has been called." << std::endl;} ;
    C(std::vector<double> vec) : m_vec{vec}{std::cout << "C constructor has been called." << std::endl;} ;
    C(const C& copy){m_vec = copy.m_vec; std::cout << "C copy constructor has been called." << std::endl;};
    C& operator= (const C& copy) {m_vec = copy.m_vec; std::cout << "C assignement has been called." << std::endl; return *this;};
    ~C(){std::cout << "C destructor has been called." << std::endl;};

    void print()
    {
    std::cout << '[';
    for (auto i : m_vec) std::cout << i << ' ';
    std::cout << ']' << std::endl;
    std::cout << "C print function has been called." << std::endl;
    };

    void multiply(const double multiplicator)
    {
    std::transform(m_vec.begin(), m_vec.end(), m_vec.begin(), [=](auto& i){return i*multiplicator;});
    std::cout << "C multiply function has been called." << std::endl;
    };
};
