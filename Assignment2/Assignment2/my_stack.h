#pragma once
#include <vector>
#include <iostream>

template<class T>
class Stack {
	std::vector<T> stack;
	
public:
	bool empty() {
		return stack.size() == 0;
	}

	void push(T val) {
		stack.push_back(val);
	}

	void pop() {
		stack.pop_back();
	}

	T& top() {
		return stack[stack.size() - 1];
	}

	void print() {
		for (T t : stack) {
			std::cout << t << " ";
		}
		std::cout << '\n';
	}

	static void main() {
		Stack<int> s;
		s.push(1);
		s.push(5);
		s.push(0);
		s.push(4);
		s.push(3);

		s.print();

		s.pop();

		std::cout << s.top();


	}
};

