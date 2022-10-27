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

		std::cout << s.top() << '\n';

		Stack<int> a, b;
		a.push(1);
		a.push(2);
		b.push(3);
		b.push(4);
		Stack<int> c = a + b;

		c.print();
	}
};

