#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cmath>
struct Node {
	Node* left;
	Node* right;
	int value;
	Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BST {
public:
	BST();
	bool AddNode(int value);
	void HorizontalPrint();
	bool ContainsNode(int value);
	bool DeleteNode(int value);
	void DeleteTree();
	void VerticalPrint();
private:
	Node* root;
	Node* AddNode(Node* node, int value);
	bool ContainsNode(Node* node, int value);
	Node* FindMin(Node* node);
	Node* DeleteNode(Node* node, int value);
	void DeleteTree(Node* node);
	void HorizontalPrint(Node* node, std::string prefix = "", bool isLeft = true);
	void VerticalPrint(Node* root);

};
