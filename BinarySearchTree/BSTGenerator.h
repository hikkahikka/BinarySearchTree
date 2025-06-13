#pragma once
#include "BinarySearchTree.h"
#include <ctime>
class BSTGenerator
{
public:

	void GenerateTree(BST& tree, int n, int start, int finish);
	void GenerateNodes(BST& tree, int n, int start, int finish);
};

