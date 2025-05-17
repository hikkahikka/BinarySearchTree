#include "Header.h"

class BST {
private:
	Node* root;
	Node* AddNode(Node* node, int value) {
		if (node == nullptr) return new Node(value);
		if (value < node->value) {
			node->left = AddNode(node->left, value);
		}
		else if (value > node->value) {
			node->right = AddNode(node->right, value);
		}
		return node;
	}
	bool ContainsNode(Node* node, int value) {
		if (node == nullptr) return false;
		if (node->value == value) return true;
		if (value < node->value) {
			return ContainsNode(node->left, value);
		}
		else {
			return ContainsNode(node->right, value);
		}
	}
	Node* FindMin(Node* node) {
		while (node != nullptr && node->left!=nullptr) {
			node = node->left;
		}
		return node;
	}
	Node* DeleteNode(Node* node, int value) { //вот это потом потыкать в отладке, я не понимаю как это работает
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
public:
	BST() {
		root = nullptr;
	}
	
};
