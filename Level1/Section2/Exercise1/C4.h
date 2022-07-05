#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

template <class T>
class C4
{
private:
    T m_vec;

public:
    explicit constexpr C4() { m_vec = {}; std::cout << "C4 default constructor has been called." << std::endl; };
    void operator() (T vec) { m_vec = vec; std::cout << "C4 function call () has been called." << std::endl; };
    explicit C4(const C4& copy) noexcept { m_vec = copy.m_vec; std::cout << "C4 copy constructor has been called." << std::endl; };
    C4& operator= (const C4& copy) noexcept { m_vec = copy.m_vec; std::cout << "C4 assignement has been called." << std::endl; return *this; };
    ~C4() { std::cout << "C4 destructor has been called." << std::endl; };

    void print()
    {
        std::cout << '[';
        for (auto i : m_vec) std::cout << i << ' ';
        std::cout << ']' << std::endl;
        std::cout << "C4 print function has been called." << std::endl;
    };

    void multiply(const double multiplicator)
    {
        std::transform(m_vec.begin(), m_vec.end(), m_vec.begin(), [=](auto& i) {return i * multiplicator; });
        std::cout << "C4 multiply function has been called." << std::endl;
    };
};
