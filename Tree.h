/*
	Created by Jacob Marx, 4/11/19
	This contains the function prototypes for the tree
*/
#ifndef TREE_H
#define TREE_H

#include<iostream>

class Tree {
	
public:
	// Constructors
	Tree();
	~Tree();
	
	// Member Functions
	bool isempty() const;
	int pop();
	void display();
	Node* getRoot();
	
	
	void push(int);
	

private:
	// Private Members
	Node* root;
	
	// Private Functions
	void push(Node*&, int);
	void print(Node*, int) const;

	
};

#endif