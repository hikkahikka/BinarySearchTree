#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cmath>
#include "BinarySearchTree.h"

class BSTPrinter {
public:
	BSTPrinter(Node* _root);
	void HorizontalPrint();
	void VerticalPrint();

private:
	Node* root;
	void HorizontalPrint(Node* node, std::string prefix = "", bool isLeft = true);
	void VerticalPrint(Node* root);
};