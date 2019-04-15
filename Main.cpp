/*
	Created by Jacob Marx, 4/11/19
	This programs makes a Binary Tree that you can add and remove to
	also it can print out the tree visually
*/

#include <iostream>
#include "Node.h"
#include "Tree.h"


int main() {
	Tree* tree = new Tree();
	tree->push(12);
	tree->push(6);
	tree->push(3);
	tree->push(9);
	tree->push(11);

	tree->display();
	return 0;
}
