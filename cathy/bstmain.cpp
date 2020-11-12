#include "bst.h"
#include <iostream>

int main(void){

	BST<int> tree;
	BST<int> tree2;

	tree.insertIterative(55);
	tree.insertIterative(22);
	tree.insertIterative(87);
	tree.insertIterative(26);
	tree.insertIterative(73);
	tree.print();
	std::cout << std::endl;
	tree2.insertRecursive(55);
	tree2.insertRecursive(22);
	tree2.insertRecursive(87);
	tree2.insertRecursive(26);
	tree2.insertRecursive(73);
	tree2.print();
	std::cout << std::endl;

}