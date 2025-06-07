#pragma once
#include <iostream>
#include <string>
//#define VERT_STICK char(179)
//#define HORIZ_STICK char(196) 
//#define TOP_TO_RIGHT_STICK char (192)
//#define BOTTOM_TO_RIGHT_STICK char (218)

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
	void HorizontalPrint(Node* node, std::string prefix="", bool isLeft=true);

private:
	Node* root;
	Node* AddNodeImpl(Node* node, int value);
	bool ContainsNode(Node* node, int value);
	Node* FindMin(Node* node);
	Node* DeleteNode(Node* node, int value);
	void DeleteTree(Node* node);
};
