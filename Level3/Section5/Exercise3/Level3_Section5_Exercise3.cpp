// Level3_Section5_Exercise3.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <forward_list>
#include <iostream>
#include <array>

// function to print forward list
template <typename T>
void forward_list_print(std::forward_list<T>& list) {
	if (list.empty()) { std::cout << "list is empty"; }
	else {
		for (T elem : list) { std::cout << elem << ", "; };
	};
	std::cout << std::endl;
}

// PART B)

// function to give the size of forward list
template <typename T>
std::size_t forward_list_size(std::forward_list<T>& list){
	return std::distance(list.begin(), list.end());
}


// PART D)

// function to earse after a given position
template <typename T, typename Iterator>
void erase(std::forward_list<T>& list, Iterator pos) {
	list.erase_after(pos);
}

// function to earse based on range of iterators
template <typename T, typename Iterator>
void erase(std::forward_list<T>& list, Iterator l, Iterator r) {
	list.erase_after(l, r);
}





int main() {

	// PART A)

	// default list
	std::forward_list<int> l1;
	forward_list_print(l1);

	// list with 5 elements
	std::forward_list<int> l2(5, 1);
	forward_list_print(l2);

	// list build from initializer list
	std::forward_list<int> l3{ 1,2,3,4,5,6,7,8 };
	forward_list_print(l3);

	std::cout << std::endl;


	// PART B)

	// checking that function works
	std::cout << "list 1: " << forward_list_size(l1) << std::endl;
	std::cout << "list 2: " << forward_list_size(l2) << std::endl;
	std::cout << "list 3: " << forward_list_size(l3) << std::endl;
	// => works as planned

	// PART C)

	l1 = { 0 };
	// insert value based on value
	l1.insert_after(l1.begin(), 7);
	forward_list_print(l1);

	// insert value based on value and count
	l1.insert_after(l1.begin(), 1, 6);
	forward_list_print(l1);

	// insert value based on two iterators
	std::array<int, 3> iterator{ 3, 4, 5 };
	l1.insert_after(l1.begin(), iterator.begin(), iterator.end());
	forward_list_print(l1);

	// insert value based on list
	l1.insert_after(l1.begin(), { 1, 2 });
	forward_list_print(l1);

	// PART D)
	erase(l1, l1.begin());
	forward_list_print(l1);

	erase(l3, l3.begin(), l3.end());
	forward_list_print(l3);
	//-> works as expected

	// PART E)

	// merge
	l1 = { 1,3,5 };
	l2 = { 2,4,6 };
	l1.merge(l2);
	forward_list_print(l1);
	// => we see cleary that l2 has been merged into l1 and sorted

	// splice
	l3 = { 1,1,1 };
	l1.splice_after(l1.cbegin(), l3);
	forward_list_print(l1);
	forward_list_print(l3);
	// => we have indeed that l3 has been put after begin
}