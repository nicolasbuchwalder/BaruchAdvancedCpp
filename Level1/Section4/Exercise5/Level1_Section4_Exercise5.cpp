#include <iostream>
#include <functional>


// PART A)
template <typename T>
using FunctionType = std::function<T(const T& t)>;

// almost same class as given in the exercise, just renamed as Shape and execute member function to rotate
template <typename T>
class Shape
{
private:
    FunctionType<T> _func;
    T _fac;
public:
    Shape (const FunctionType<T>& function, const T& factor) : _fac(factor)
    {
        _func = function;
    }

    T rotate(double d) { return _func(d) * _fac; };

    void switchFunction(const FunctionType<T>& function)
   {
        _func = function;
   };
};    

int main()
{
    // PART B)
    auto customfunc1 = [](double d) { std::cout << "custom1\n"; return d;};
    auto customfunc2 = [](double d) { std::cout << "custom2\n"; return d*d;};

    Shape<double> newgenclass(customfunc1, 3.14);
    auto result = newgenclass.rotate(2.0);
    std::cout << result << std::endl;

    newgenclass.switchFunction(customfunc2);
    result = newgenclass.rotate(2.0);
    std::cout << result << std::endl;
    // functions can be assigned at construction and changed with switchFunction element => everything works as planned
}
