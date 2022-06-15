#include <iostream>
#include <bitset>

// PART B)
void print(){};
// => this is the tail function

// PART A)
template<typename T, typename... Ts>
void print(T arg1, Ts... args)
{
    std::cout << arg1 << ' ';
    print(args...);
}

int main()
{
    // Variadic function templates
    int j = 1; double d = 2.0;
    print(j); print(d); print(j, d); print(d, j);
    std::cout << "\n3 params \n";
    print(d, j, std::bitset<8>(233));
}