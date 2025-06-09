#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "BinarySearchTree.h"
class BSTSerializer
{
public:
	bool DeserializeTree(BST* tree, std::string path);
	bool SerializeTree(BST* tree, std::string path);
private:
	void SerializeTree(Node* root, std::ofstream& fout);
};

