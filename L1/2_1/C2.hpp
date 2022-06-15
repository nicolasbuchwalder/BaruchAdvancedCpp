#pragma once
#include <iostream>
#include <vector>
#include <algorithm>


class C2
{
private:
    std::vector<double>  m_vec;

public:
    explicit C2() {m_vec = {}; std::cout << "Default constructor has been called." << std::endl;} ;
    explicit C2(std::vector<double>  vec) : m_vec{vec} {std::cout << "Constructor has been called." << std::endl;};
    C2(const C2& copy){m_vec = copy.m_vec; std::cout << "Copy constructor has been called." << std::endl;};
    C2& operator= (const C2& copy) {m_vec = copy.m_vec; std::cout << "Assignement has been called." << std::endl; return *this;};
    ~C2(){std::cout << "C2 destructor has been called." << std::endl;};

    void print()
    {
    std::cout << '[';
    for (auto i : m_vec) std::cout << i << ' ';
    std::cout << ']' << std::endl;
    std::cout << "C2 print function has been called." << std::endl;
    };

    void multiply(const double multiplicator)
    {
    std::transform(m_vec.begin(), m_vec.end(), m_vec.begin(), [=](auto& i){return i*multiplicator;});
    std::cout << "C2 multiply function has been called." << std::endl;
    };
};
