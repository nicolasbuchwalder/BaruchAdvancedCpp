#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

template <class T>
class C
{
private:
    T m_vec;

public:
    explicit constexpr C() { m_vec = {}; std::cout << "Default constructor has been called." << std::endl; };
    void operator() (T vec) { m_vec = vec; std::cout << "Function call () has been called." << std::endl; };
    explicit C(const C& copy) noexcept { m_vec = copy.m_vec; std::cout << "Copy constructor has been called." << std::endl; };
    explicit C(const C&& copy) noexcept { m_vec = std::move(copy.m_vec); std::cout << "Move constructor has been called." << std::endl; };
    C& operator= (const C& copy) noexcept { m_vec = copy.m_vec; std::cout << "Assignement has been called." << std::endl; return *this; };
    C& operator= (const C&& copy) noexcept { m_vec = std::move(copy.m_vec); std::cout << "Move assignement has been called." << std::endl; return *this; };
    ~C() { std::cout << "Destructor has been called." << std::endl; };

    void print()
    {
        std::cout << '[';
        for (auto i : m_vec) std::cout << i << ' ';
        std::cout << ']' << std::endl;
    };

    void multiply(const double multiplicator)
    {
        std::transform(m_vec.begin(), m_vec.end(), m_vec.begin(), [=](auto& i) {return i * multiplicator; });
        std::cout << "Multiply function has been called." << std::endl;
    };
};
