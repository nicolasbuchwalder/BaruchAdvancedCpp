// Level4_Section2_Exercise8.cpp: This file contains the full code for this exercise
// @NicolasBuchwalder for QuantNet/Baruch MFE Advanced C++ course

#include <stack>
#include <iostream>

// max: leaves on the stack the larger value
void max(std::stack<int>& stack) {
	// setting the first value to be the max (for now)
	int max_val{ stack.top() };
	stack.pop();
	// removing all non maximal other values of the stack
	while (!stack.empty()) {
		if (max_val > stack.top()) { stack.pop(); }
		else { max_val = stack.top(); stack.pop(); };
	}
	// putting the max back on the stack
	stack.push(max_val);
};


// min: leaves on the stack the smallest value
void min(std::stack<int>& stack) {
	// setting the first value to be the max (for now)
	int min_val{ stack.top() };
	stack.pop();
	// removing all non minimal other values of the stack
	while (!stack.empty()) {
		if (min_val < stack.top()) { stack.pop(); }
		else { min_val = stack.top(); stack.pop(); };
	}
	// putting the min back on the stack
	stack.push(min_val);
};

// over: duplicates the second stack value on top of the stack
void over(std::stack<int>& stack) {
	// getting top value
	int top{ stack.top() };
	stack.pop();
	// getting second value
	int second{ stack.top() };
	// repushing first and second in the other order
	stack.push(top);
	stack.push(second);
};


// rot: rotate the stack's third data value to the top of the stack
void rot(std::stack<int>& stack) {
	// getting top value
	int top{ stack.top() };
	stack.pop();
	// getting second value
	int second{ stack.top() };
	stack.pop();
	// getting third value
	int third{ stack.top() };
	stack.pop();

	// repushing first and second and third in the other order
	stack.push(second);
	stack.push(top);
	stack.push(third);
};


// swap: interchange the top two values on the stack
void swap(std::stack<int>& stack) {
	// getting top value
	int top{ stack.top() };
	stack.pop();
	// getting second value
	int second{ stack.top() };
	stack.pop();
	// repushing first and second in the other order
	stack.push(top);
	stack.push(second);
};


// drop:  discard the value on the top of the stack
void drop(std::stack<int>& stack) {
	// removing first value
	stack.pop();
};

void print(const std::stack<int>& stack) {
	auto copy{ stack };
	std::cout << "{";
	while (!copy.empty()) {
		std::cout << copy.top() << ", ";
		copy.pop();
	};
	std::cout << "}" << std::endl;
}

std::stack<int> create_stack() {
	std::stack<int> new_stack;
	for (int i{ 4 }; i>= 0; --i) { new_stack.push(i); };
	return new_stack;
}

int main() {

	auto stack = create_stack();
	print(stack);

	max(stack);
	print(stack);

	stack = create_stack();
	min(stack);
	print(stack);

	stack = create_stack();
	over(stack);
	print(stack);

	stack = create_stack();
	rot(stack);
	print(stack);

	stack = create_stack();
	swap(stack);
	print(stack);

	stack = create_stack();
	drop(stack);
	print(stack);
	
	// => everything works as excepted

}