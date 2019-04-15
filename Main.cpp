/*
	Created by Jacob Marx, 4/11/19
	This programs makes a Binary Tree that you can add and remove to
	also it can print out the tree visually
*/

#include <iostream>
#include <cstring>
#include <fstream>
#include "Node.h"
#include "Tree.h"

bool getInput(Tree*, char*);
void getInput(Tree*);

int main() {
		Tree* tree = new Tree();
	
	std::cout << "Would you like to input a file or through the console?" << std::endl;
	char* input;
	std::cin >> input;
	if (strcmp(input, "file") == 0) {
		char* fileName = new char[80];
		std::cout << "What is the name of the file?" << std::endl;
		std::cin >> fileName;
		getInput(tree, fileName);
		delete[] fileName;
	}
	else if (strcmp(input, "console") == 0) {
		getInput(tree);
	}
	
	/*
	tree->push(12);
	tree->push(6);
	tree->push(3);
	tree->push(9);
	tree->push(16);
	tree->push(1);
	tree->push(45);
	tree->push(23);
	tree->push(34);
	tree->push(19);
	tree->push(4);
	tree->push(21);
	tree->push(25);
	tree->push(15);
	*/
	
	tree->display();
	return 0;
}

bool getInput(Tree* tree, char* fileName) {
	std::ifstream file;
	std::cout << "goon" << std::endl;
	file.open(fileName);
	if (file.is_open()) {
		char* in;
		int input = 0;
		int index = 0;
		std::cout << file.get() << std::endl;
		file.unget();
		file >> in;
		while (true) { // Gage did this
			char current = in[index++];
			if (current == '\0') {
				break;
			} else if (current == ',') {
				tree->push(input);
				input = 0;
				continue;
			}
			int digit = current - '0';
			input = input * 10 + digit;
		}
		std::cout << in << std::endl;
		if (input <= 1000 && input >= 1) {
			tree->push((int)*in);
		}
		return true;
	}
	return false;
}

void getInput(Tree* tree) {
	while (true) {
		int input = 0;
		std::cout << "ghflkfjlj\n";
		std::cin >> input;
		if (input <= 1000 && input >= 1) {
			std::cout << input << std::endl;
			tree->push(input);
			std::cout << "goon\n";
		}
		//std::cin.unget();
		//std::cout << "Whitespace: " << int(std::cin.get()) << std::endl;
		//std::cin.unget();
		if (std::cin.get() == '\n') {
			std::cout << "hi\n";
			break;
		}
	}
	std::cout << "Left function" << std::endl;
}
