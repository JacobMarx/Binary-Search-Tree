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
	while (node->right != NULL)  {
		return min(node->right);
	}
	return node;
}

Node* Tree::findSucc(Node* node) {
	if (node->left != NULL) {
		return min(node->left);
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
	if (node == NULL) { 
		return NULL;
	}
	if (node->data != comp) {
		if (node->data < comp) {
			return search(node->right, comp);
		}
		if (node->data > comp) {
			return search(node->left, comp);
		}
	}
	else if (node->data == comp) {
		return node;
	}
	return NULL;
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
	Node* node = search(root, remove);
	
	Node* succ;
	
	if (node!= NULL && node->left != NULL && node->right != NULL) {
		succ = findSucc(node);
		if (succ == NULL) {
			delete[] node;
			return;
		}
		node->data = succ->data;
		node = succ;
	}
	
	Node* child;
	if (node->left != NULL) {
		child = node->left;
	}
	else {
		child = node->right;
	}
	if (node->parent != NULL) {
		if (node->parent->left == node) {
			node->parent->left = child;
		}
		if (node->parent->right == node) {
			node->parent->right = child;
		}
	}
	else {
		root = child;
	}
	/*
	if (node->left != NULL && node->right == NULL) {
		succ = findSucc(node);
		if (succ == NULL) {
			delete[] node;
			return;
		}
		
		if (succ->left != NULL) {
			succ->parent->right = succ->left;
		}
		
		node->data = succ->data;
		
		node = succ;
	}
	
	if (node->left == NULL && node->right != NULL) {
		node->parent->right = node->right;
	}
	*/
	
	delete[] node;
	
	/*
	if (succ != NULL && node->right != succ) {
		node->data = succ->data;
		succ->parent->right = NULL;
		delete[] succ;
	}
	if (node->right == succ) {
		node->parent->right = succ;
		delete[] node;
	}
	*/
	
	// If succ is NULL do stuff
	
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

/*
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
			node->left->parent = node;
		}
	}
	if (node->right == NULL) {
		if (input > node->data) {
			node->right = new Node(input);
			node->right->parent = node;
		}
	}
}
*/

void Tree::push(Node* node, int input) { // Creates new node
	if (node->left != NULL && node->data > input) {
		push(node->left, input);
		return;
	}
	else if (node->right != NULL && node->data < input) {
		push(node->right, input);
		return;
	}
	if (node->left == NULL && input < node->data) {
			node->left = new Node(input);
			node->left->parent = node;
			return;
	}
	else if (node->right == NULL && input > node->data) {
			node->right = new Node(input);
			node->right->parent = node;
			return;
	}
}

