// Level1_Section5_Exercise2.cpp: This file contains all the code for this exercise. @Nicolas Buchwalder


#include <iostream>
#include <tuple>
#include <complex>


// PART A, C)

// recurive way to calculate max, sum, average => using iteration didn't work 
template <typename T, typename Tuple, std::size_t N>
struct Calculator
{
    static T max(const Tuple& tuple)
    {
        if (std::get<N - 1>(tuple) > Calculator<T, Tuple, N - 1>::max(tuple))
        {
            T max_value = std::get<N - 1>(tuple);
            return max_value;
        }
        else {
            T max_value = Calculator<T, Tuple, N - 1>::max(tuple);
            return max_value;
        }
    };

    static T sum(const Tuple& tuple)
    {
        T total = std::get<N - 1>(tuple) + Calculator<T, Tuple, N - 1>::sum(tuple);
        return total;
    };

    static T avg(const Tuple& tuple)
    {
        T total = sum(tuple);
        T avg = total / (static_cast<T>(N));
        return avg;
    };
};

// single valued tuples, where recursion ends
template <typename T, typename Tuple>
struct Calculator<T, Tuple, 1>
{
    static T max(const Tuple& tuple)
    {
        T max_value = std::get<0>(tuple);
        return max_value;
    };

    static T sum(const Tuple& tuple)
    {
        T total = std::get<0>(tuple);
        return total;
    };
}; 



int main() {

	// PART B)
	using twoDoubleTuple = std::tuple<double, double>;
	using threeDoubleTuple = std::tuple<double, double, double>;

	twoDoubleTuple tuple1 = std::make_tuple(10.0, 20.0);
	threeDoubleTuple tuple2 = std::make_tuple(1.0, 2.0, 3.0);

	std::cout << Calculator<double, twoDoubleTuple, 2>::max(tuple1) << std::endl;
	std::cout << Calculator<double, twoDoubleTuple, 2>::sum(tuple1) << std::endl;
	std::cout << Calculator<double, threeDoubleTuple, 3>::avg(tuple2) << std::endl;
	// => works

    using threeComplexTuple = std::tuple<std::complex<int>, std::complex<int>, std::complex<int>>;

    threeComplexTuple tuple3 = std::make_tuple(std::complex<int>{0, 0}, std::complex<int>{1, 0}, std::complex<int>{0, 1});

    std::cout << Calculator<std::complex<int>, threeComplexTuple, 3>::sum(tuple3) << std::endl;
    std::cout << Calculator<std::complex<int>, threeComplexTuple, 3>::avg(tuple3) << std::endl;
    // => works as well, makes sense that max cannot be determind as complex numbers are 2D and the way calculator is implemented works only for 1D

}