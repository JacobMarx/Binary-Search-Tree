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
	Node* getRoot();
	Node* findSucc(Node*);
	Node* min(Node*);
	Node* search(Node*, int);
	
	void display();
	void remove(int);
	void push(int);
	

private:
	// Private Members
	Node* root;
	
	// Private Functions
	void push(Node*, int);
	void print(Node*, int) const;

	
};

#endif