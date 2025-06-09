#pragma once
#include <string>
#include <fstream>
#include "BinarySearchTree.h"
class BSTSerializer
{
public:
	void DeserializeTree(BST* tree, std::string path);
}

