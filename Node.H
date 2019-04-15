/*
	Created by Jacob Marx, 4/11/19
	This contains the struct for all the nodes
*/

#ifndef NODE_H
#define NODE_H

#include <iostream>

struct Node {
	Node(int data = 0) {
		this->data = data;
		left = NULL;
		right = NULL;
		parent = NULL;
	}
	int data;
	Node* left;
	Node* right;
	Node* parent;
};
	
#endif