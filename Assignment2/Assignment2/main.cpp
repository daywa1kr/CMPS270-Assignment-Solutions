#include "my_btree.h"

int main() {
	BST<int> t1;

	t1.addNode(3);
	t1.addNode(5);
	t1.addNode(1);
	t1.addNode(0);
	t1.addNode(-19);
	t1.addNode(23);
	
	t1.postOrderPrint();
	t1.inOrderPrint();
	t1.preOrderPrint();

	std::cout << "size: " << t1.treeSize() << '\n';

	BST<char> t2;

	t2.addNode('p');
	t2.addNode('d');
	t2.addNode('3');
	t2.addNode('a');
	t2.addNode('i');
	t2.addNode('X');
	t2.addNode('q');
	t2.addNode('-');

	t2.postOrderPrint();
	t2.inOrderPrint();
	t2.preOrderPrint();

	std::cout << "size: " << t2.treeSize() << '\n';
}