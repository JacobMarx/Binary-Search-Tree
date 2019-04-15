/*
	Created by Jacob Marx, 4/11/19
	This contains the functions for the tree
*/

#include "Node.h"
#include "Tree.h"

Tree::Tree() {
	root = NULL;
}

Tree::~Tree() {
	
}

bool Tree::isempty() const {
	if (!root) {
		return true;
	}
	return false;
}

Node* Tree::getRoot() {
	return root;
}

void Tree::print(Node* node, int depth) const {
	if (node == NULL) return;
	
	print(node->right, depth + 1);
	
	int count = depth;
	while (count > 0) {
		std::cout << '\t';
		count--;
	}
	std::cout << node->data << std::endl;
	
	print(node->left, depth + 1);
}

void Tree::display() {
	int depth = 0;
	print(root, depth);
}

void Tree::push(int input) {
	if (!root) {
		root = new Node(input);
	}
	else {
		push(root, input);
	}
}

void Tree::push(Node*& node, int input) {
	if (node->left != NULL) {
		if (input < node->data) {
			push(node->left, input);
		}
	}
	if (node->right != NULL) {
		if (input > node->data) {
			push(node->right, input);
		}
	}
	if (node->left == NULL) {
		if (input < node->data) {
			node->left = new Node(input);
		}
	}
	if (node->right == NULL) {
		if (input > node->data) {
			node->right = new Node(input);
		}
	}
}

