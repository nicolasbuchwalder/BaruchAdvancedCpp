#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

template <class T>
class C3
{
private:
    T m_vec;

public:
    explicit constexpr C3() {m_vec = {}; std::cout << "C3 default constructor has been called." << std::endl;} ;
    void operator() (T vec) {m_vec = vec; std::cout << "C3 function call () has been called." << std::endl;};
    explicit C3(const C3& copy){m_vec = copy.m_vec; std::cout << "C3 copy constructor has been called." << std::endl;};
    C3& operator= (const C3& copy) {m_vec = copy.m_vec; std::cout << "C3 assignement has been called." << std::endl; return *this;};
    ~C3(){std::cout << "C3 destructor has been called." << std::endl;};

    void print()
    {
    std::cout << '[';
    for (auto i : m_vec) std::cout << i << ' ';
    std::cout << ']' << std::endl;
    std::cout << "C3 print function has been called." << std::endl;
    };

    void multiply(const double multiplicator)
    {
    std::transform(m_vec.begin(), m_vec.end(), m_vec.begin(), [=](auto& i){return i*multiplicator;});
    std::cout << "C3 multiply function has been called." << std::endl;
    };
};
