// Level1_Section5_Exercise3.cpp: This file contains all the code for this exercise. @Nicolas Buchwalder

#include <iostream>
#include <tuple>
#include <vector>
#include <numeric>
#include <algorithm>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>


// PART A)

// template structur with static function to get statistics about a vector of certain type
template <typename T, typename Vec, typename Tuple, std::size_t N>
struct Statistics
{

	static Tuple calcs(const Vec& v) {
		if (v.empty()) {
			Tuple zeroes{ std::make_tuple(0, 0, 0, 0, 0) };
			return zeroes;
		};
		// mean is simply sum of v divided by size of v
		T mean{ std::accumulate(v.begin(), v.end(), 0) / static_cast<T>(N) };
		// getting the absolute deviations of v
		Vec absDevs(v.size());
		std::transform(v.begin(), v.end(), absDevs.begin(),
			[=](T i) {
				if (i > mean) { return i - mean; }
				else { return mean - i; }
			});
		// mean of deviations will be the sum of absolute deviations by the the size of v
		T meanDev{ std::accumulate(absDevs.begin(), absDevs.end(), 0) / static_cast<T>(N) };
		// range is max minus min
		T range{ static_cast<T>(std::max_element(v.begin(), v.end()) - std::min_element(v.begin(), v.end())) };
		// variance is the deviations squared divided by size of v, as we are squaring, we can use the absolute deviations
		T variance{ std::inner_product(absDevs.begin(), absDevs.end(), absDevs.begin(), 0) / static_cast<T>(N) };
		// standard deviation is the square root of variance
		T stanDev{ std::sqrt(variance) };

		return std::make_tuple(mean, meanDev, range, variance, stanDev);

	};
};


// PART C)
template <typename T, typename Vec, typename Tuple, std::size_t N>
struct Distribution {
	
	static Tuple medianmode(const Vec& v) {
		// is the vector is empty, simply return statistics of 0
		if (v.empty()) {
			Tuple zeroes{ std::make_tuple(0,0) };
			return zeroes;
		};
		Vec sorted_v = v;
		std::sort(sorted_v.begin(), sorted_v.end());

		T median;
		// median is:
		//		- if length is odd: middle value
		//		- if length is even: half of both values in the middle
		if (static_cast<int>(N) % 2 != 0) {
			median = sorted_v[static_cast<int>(N) / 2];
		}
		else {
			median = static_cast<T>((sorted_v[(static_cast<int>(N) - 1) / 2] + sorted_v[static_cast<int>(N) / 2]) / 2.0);
		};
		
		// to get the mode, as the array is sorted, simply count the number of repeating numbers (and store biggest)
		T best{sorted_v[0]};
		int best_count{ 1 };
		T current{ sorted_v[0] };
		int count{ 1 };
		for (int i{ 1 }; i < N; ++i) {
			if (sorted_v[i] == current) { ++count; }
			else {
				// we only update if the count if strictly bigger => if there are equal bests this will take the smallest
				if (count > best_count) {
					best = current;
					best_count = current;
				};
				current = sorted_v[i];
				count = 1;
			};
		};
		T mode{ best };
		return std::make_tuple(median, mode);

	}
};




int main() {
	// PART A, B)
	using tuple_res = std::tuple<double, double, double, double, double>;
	std::vector<double> vec{ 0, 1, 2, 3, 4 };
	tuple_res results{ Statistics<double, std::vector<double>, tuple_res, 5>::calcs(vec) };
	std::cout << "with std::vector: " << std::get<0>(results) << ", " << std::get<1>(results) << ", " << std::get<2>(results) << ", " << std::get<3>(results) << ", " << std::get<4>(results) << std::endl;
	//=> works with std::vector

	boost::numeric::ublas::vector<double> vec2(5);
	for (int i{ 0 }; i < vec2.size(); ++i) {
		vec2[i] = static_cast<double>(i);
	};
	tuple_res results2{ Statistics<double, boost::numeric::ublas::vector<double>, tuple_res, 5>::calcs(vec2) };
	std::cout << "with boost::numeric::ublas::vector: " << std::get<0>(results2) << ", " << std::get<1>(results2) << ", " << std::get<2>(results2) << ", " << std::get<3>(results2) << ", " << std::get<4>(results2) << std::endl;
	//=> works also with boost::numeric::ublas::vector<double>, we got the same results

	// PART C)

	using tuple_mm = std::tuple<int, int>;
	std::vector<int> vec3{ 78,74,68,76,80,84,50,93,55,76,58,74,75 };
	tuple_mm results3{ Distribution<int, std::vector<int>, tuple_mm, 13>::medianmode(vec3) };
	std::cout << "with std::vector: " << std::get<0>(results3) << ", " << std::get<1>(results3) << std::endl;
	//=> works with std::vector

	boost::numeric::ublas::vector<int> vec4(13);
	for (int i{ 0 }; i < vec4.size(); ++i) {
		vec4[i] = vec3[i];
	};
	tuple_mm results4{ Distribution<int, boost::numeric::ublas::vector<int>, tuple_mm, 13>::medianmode(vec4) };
	std::cout << "with boost::numeric::ublas::vector: " << std::get<0>(results4) << ", " << std::get<1>(results4) << std::endl;
	//=> works also with boost::numeric::ublas::vector<int>, we got the same results

}