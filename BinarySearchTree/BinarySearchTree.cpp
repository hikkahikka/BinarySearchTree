#include "BinarySearchTree.h"

Node* BST::AddNodeImpl(Node* node, int value) {
	if (node == nullptr) return new Node(value);
	if (value < node->value) {
		node->left = AddNodeImpl(node->left, value);
	}
	else if (value > node->value) {
		node->right = AddNodeImpl(node->right, value);
	}
	return node;
}

bool BST::AddNode(int value) {
	if (!ContainsNode(root, value)) {
		root = AddNodeImpl(root, value);
		return true;
	}
	return false;
}

bool BST::ContainsNode(Node* node, int value) {
	if (node == nullptr) return false;
	if (node->value == value) return true;
	if (value < node->value) {
		return ContainsNode(node->left, value);
	}
	else {
		return ContainsNode(node->right, value);
	}
}
Node* BST::FindMin(Node* node) {
	while (node != nullptr && node->left!=nullptr) {
		node = node->left;
	}
	return node;
}
Node* BST::DeleteNode(Node* node, int value) { 
	if (node == nullptr) return nullptr;
		
	if (value < node->value) {
		node->left = DeleteNode(node->left, value);
	}
	else if (value > node->value) {
		node->right = DeleteNode(node->right, value);
	}
	else {
		if (node->right == nullptr) {
			Node* newNode = node->left;
			delete node;
			return newNode;
		}
		else if (node->left == nullptr) {
			Node* newNode = node->right;
			delete node;
			return newNode;
		}

		Node* newNode = FindMin(node->right);
		node->value = newNode->value;
		node->right = DeleteNode(node->right, newNode->value);
	}
	return node;
}
void BST::DeleteTree(Node* node) {
	if (root == nullptr) return;  
	DeleteTree(root->left);   
	DeleteTree(root->right); 
	delete root;
}

void BST::HorizontalPrint(Node* node, std::string prefix, bool isLeft ) {
	std::string top_right = std::string(1, char(192)) + std::string(2, char(196)) + " ";
	std::string vert = std::string(1, char(179));
	std::string bottom_right = std::string(1, char(218)) + std::string(2, char(196)) + " ";
	if (node->right) {
		HorizontalPrint(node->right, prefix + (isLeft ? vert+"   " : "    "), false);
	}

	std::cout << prefix + (isLeft ? top_right : bottom_right) + std::to_string(node->value) + "\n";

	if (node->left) {
		HorizontalPrint(node->left, prefix + (isLeft ? "    " : vert+"   "), true);
	}
}
BST::BST() {
	root = nullptr;
}
	

