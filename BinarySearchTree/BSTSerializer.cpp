#include "BSTSerializer.h"
void BSTSerializer::DeserializeTree(BST* tree, std::string path) {
	std::string value;
	std::ifstream fin(path);
	if (fin.is_open())
	{
		while (fin >> value) {
			tree->AddNode(std::stoi(value));
		}
	}
	fin.close();
}
