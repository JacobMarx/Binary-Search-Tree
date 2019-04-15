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

Node* Tree::min(Node* node) {
	Node* curr = node;
	
	while (curr->left != NULL) {
		curr = curr->left;
	}
	return curr;
}

Node* findSucc(Node* node) {
	if (node->right != NULL) {
		return min(node->right);
	}
	else {
		if (node->left != NULL) {
			return node->left;
		}
	}
	return NULL;
	/*
	Node* p = node->parent;
	
	while (p != NULL && node == p->right) {
		node = p;
		p = p->parent;
	}
	
	return p;
	*/
}

Node* Tree::search(Node* node, int comp) {
	if (node->data != comp) {
		if (node->right != NULL && node->data < comp) {
			search(node->right);
		}
		if (node->left != NULL ** node->data > comp) {
			search(node->left);
		}
	}
	else if (node->data == comp) {
		return node;
	}
	std::cout << "That number is not in the tree." << std::endl;
	return;
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

void Tree::remove(int remove) {
	// Find node with data we want to remove
	// Find successor of node we want to remove
	// 
	Node* node = search(root, remove)
	Node* succ = findSucc(node);
	
	if (succ != NULL) {
		node->data = succ->data;
	}
	if (succ->parent->left == succ) {
		succ->parent->left = NULL;
	}
	else {
		succ->parent->right = NULL;
	}
	delete[] succ;
	
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

