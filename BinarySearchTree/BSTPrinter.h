#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cmath>
#include "BinarySearchTree.h"

class BSTPrinter {
public:
	void HorizontalPrint(BST* tree);
	void VerticalPrint(BST* tree);
private:
	void HorizontalPrint(Node* node, std::string prefix = "", bool isLeft = true);
	
};