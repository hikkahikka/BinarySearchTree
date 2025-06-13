#pragma once
#include <string>
#include <iostream>
#include "BinarySearchTree.h"
#include "BSTPrinter.h"
#include "BSTSerializer.h"
#include "BSTGenerator.h"

class UserInterface
{
public:
	bool Start(BST& tree);
private:
	int InputValue(int start, int finish);
	void AddNode(BST& tree);
	void DeleteNode(BST& tree);
	void ContainsNode(BST& tree);
	void SerializeTree(BST& tree);
	void DeserializeTree(BST& tree);
	void GenerateTree(BST& tree);
	void GenerateNodes(BST& tree);


};

