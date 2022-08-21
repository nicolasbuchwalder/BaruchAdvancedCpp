// Vector.h: This file contains the class Vector which we want to implement in this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#pragma once

#include <iostream>
#include <array>
#include <functional>
#include <algorithm>

template <typename T, int N>
class Vector
{
	// PART A-B-C)
	// constructors, access, operations
	using dataType = std::array<T, N>;
private:
	// choosing std::array for data
	dataType data{ 0 };

public:
	// default, value with array and copy constructors
	Vector() {};
	Vector(dataType input) {
		for (int i = 0; i < N; ++i) {
			data[i] = input[i];
		};
	};
	Vector(const Vector& copy) {
		for (int i = 0; i < N; ++i) {
			data[i] = copy.data[i];
		};
	}

	// accessing elements
	T& operator[](int idx) { return this->data[idx]; };

	// addition
	Vector operator+(const Vector& vec) {
		Vector res(this->data);
		for (int i = 0; i < N; ++i) {
			res[i] += vec.data[i];
		};
		return res;
	};

	// unary minus
	Vector operator-() {
		Vector res(this->data);
		for (int i = 0; i < N; ++i) {
			res[i] -= 1;
		};
		return res;
	};

	// substraction
	Vector operator-(const Vector& vec) {
		Vector res(this->data);
		for (int i = 0; i < N; ++i) {
			res[i] -= vec.data[i];
		};
		return res;
	};

	// scalar multiplication
	Vector operator*(T coeff) {
		Vector res(this->data);
		for (int i = 0; i < N; ++i) {
			res[i] *= coeff;
		};
		return res;
	};

	// printing vector
	friend std::ostream& operator<<(std::ostream& out, const Vector& vec) {
		out << "[ ";
		for (T elem : vec.data) { std::cout << elem << " "; };
		out << "]";
		return out;
	};

	// PART D)
	
	// printing the scalar multiplication with an additionnal template parameter
	template <typename F> 
	friend Vector operator* (const F& a, const Vector& pt) {
		Vector<T, N> res(pt.data);
		for (int i = 0; i < N; ++i) {
			// as F can be different then T, we need to convert it
			res[i] *= a;
		};
		return res;
	};

	// PART E)
	
	// function that modifies the vector
	void modify(const std::function < T(T&)>& f) {
		for (auto& elem : this->data) { elem = f(elem); };
	};

};



