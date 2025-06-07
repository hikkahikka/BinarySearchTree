#pragma once
#include <iostream>
#include <string>

#include <fstream>
struct Node {
	Node* left;
	Node* right;
	int value;
	Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BST {
public:
	BST();
	Node* GetRoot();
	bool AddNode(int value);
	bool ContainsNode(int value);
	bool DeleteNode(int value);
	void DeleteTree();
	void DeserializeTree(std::string path);

private:
	Node* root;
	Node* AddNode(Node* node, int value);
	bool ContainsNode(Node* node, int value);
	Node* FindMin(Node* node);
	Node* DeleteNode(Node* node, int value);
	void DeleteTree(Node* node);
	Node* DeserializeTree(Node* root, std::string path);

};
