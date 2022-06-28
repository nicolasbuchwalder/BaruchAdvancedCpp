#include <iostream>
#include <functional>

// using same wrapper as ex4.1
template <typename T>
using FunctionType = std::function<T(T t)>;

template <typename T>
void print(const FunctionType<T>& f, T t)
{
    std::cout << f(t) << '\n';
};


// given code
class C
{
    // Function object with extra member functions
private:
    double _data;
public:
    C(double data) : _data(data) {}
    double operator () (double factor) {
        return _data + factor;
    }

    double translate(double factor) {
        return _data + factor;
    }

    double translate2(double factor1, double factor2) {
        return _data + factor1 + factor2;
    }

    static double Square(double x) {
        return x * x;
    }
};

int main()
{
    // PART A)

    FunctionType<double> square = C::Square;
    print(square, 2.0);
    // => this is possible as Square function is static, so shared accros all instances

    // PART B)

    C c{ 3.14 };
    FunctionType<double> translate = std::bind(&C::translate, c, std::placeholders::_1);
    print(translate, 2.0);
    FunctionType<double> translate2pix = std::bind(&C::translate2, c, std::placeholders::_1, 3.14);
    print(translate2pix, 2.0);
    FunctionType<double> translate2piy = std::bind(&C::translate2, c, 3.14, std::placeholders::_1);
    print(translate2piy, 2.0);
    // => here we need to bound to a pointer of the member functions and then give the specific instance

}
