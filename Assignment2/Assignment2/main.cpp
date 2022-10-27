#include "my_btree.h"
#include "my_stack.h"
#include "my_graph.h"

int main() {
	BST<int>::main();
	std::cout << "\n---------------------------------------------\n";
	Stack<int>::main();
	std::cout << "\n----------------------------------------------\n";
	Graph::main();
}