#pragma once
#include <vector>
#include <iostream>
/*
	a generic Stack class implemented using STL vectors
*/
template<class T>
class Stack {
	std::vector<T> stack;
	
public:
	/*
		effects: return true if the stack size is 0 i.e. the stack is empty and false otherwise
		tests:
			before pushing anything to the stack, after pushing, and after poping everything
	*/
	bool empty() {
		return stack.size() == 0;
	}
	/*
		requires: a T val to be pushed on to the stack
		effects: pushes a new item with the specifies value to the stack
		tests:
			all sorts of chars and ints
	*/
	void push(T val) {
		stack.push_back(val);
	}
	/*
		effects: removes the most recently added item from the top of stack
	*/
	void pop() {
		stack.pop_back();
	}
	/*
		effects: returns the value on the top of the stack
	*/
	T& top() {
		return stack[stack.size() - 1];
	}
	/*
		requires: a stack that will be the second operand of the addition of 2 stacks
		effects: overload the + operator to allow adding 2 stacks, the result of which is a new stack that conatins the stack
				 on the right hand side stacked onto the one on the left hand side

		tests:
			2 stacks of equal sizes, different sizes, an empty stack and a non empty one
	*/
	inline Stack operator +(const Stack s) {
		Stack res;
		std::vector<T> sum;
		for (int i = 0; i < stack.size(); i++) {
			sum.push_back(stack[i]);
		}

		for (int i = 0; i < s.stack.size(); i++) {
			sum.push_back(s.stack[i]);
		}
		res.stack = sum;

		return res;
	}
	/*
		effects: prints the stack
	*/
	void print() {
		for (T t : stack) {
			std::cout << t << " ";
		}
		std::cout << '\n';
	}
	/*
		main to test stack class - in main.cpp -
	*/
	static void main() {
		Stack<int> s;

		std::cout << "stack is empty before pushing: " << s.empty() << '\n';

		s.push(1);
		s.push(5);
		s.push(0);
		s.push(4);
		s.push(3);
		std::cout << "stack is empty after pushing: " << s.empty() << '\n';
		s.print();

		std::cout <<"top: " << s.top() << '\n';

		s.pop();
		s.pop();
		std::cout << "stack is empty bfore popping everything: " << s.empty() << '\n';
		s.pop();
		s.pop();
		s.pop();
		std::cout << "stack is empty after popping everything: " << s.empty() << '\n';

		Stack<int> a, b, d;
		a.push(1);
		a.push(2);
		b.push(3);
		b.push(4);
		Stack<int> c = a + b;
		Stack<int> e = a + d;
		c.print();
		e.print();
	}
};

