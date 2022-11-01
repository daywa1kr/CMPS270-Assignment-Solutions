#include "my_btree.h"
#include "my_stack.h"
#include "my_graph.h"

int main() {
	BT<int>::main();
	std::cout << "\n---------------------------------------------\n";
	Stack<int>::main();
	std::cout << "\n----------------------------------------------\n";
	Graph::main();
}