#include "BinarySearchTree.h"

Node* BST::AddNode(Node* node, int value) {
	if (node == nullptr) return new Node(value);
	if (value < node->value) {
		node->left = AddNode(node->left, value);
	}
	else if (value > node->value) {
		node->right = AddNode(node->right, value);
	}
	return node;
}

bool BST::AddNode(int value) {
	if (!ContainsNode(root, value)) {
		root = AddNode(root, value);
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

bool BST::ContainsNode(int value) {
	return ContainsNode(root, value);
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

bool BST::DeleteNode(int value) {
	if (!ContainsNode(root, value))return false;
	root = DeleteNode(root, value);
	return true;
}

void BST::DeleteTree(Node* node) {
	if (root == nullptr) return;  
	DeleteTree(root->left);   
	DeleteTree(root->right); 
	delete root;
}

void BST::DeleteTree() {
	DeleteTree(root);
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

void BST::HorizontalPrint() {
	if (root == nullptr) {
		std::cout << "Tree is empty!";
		return;
	}
	HorizontalPrint(root);
}

void BST::VerticalPrint(Node* root) {
	if (!root) return;
	std::queue<Node*> q;
	q.push(root);
	int level = 0; 
	int maxLevel = 0;
	std::queue<Node*> tempQ;
	tempQ.push(root);
	while (!tempQ.empty()) {
		int size = tempQ.size();
		maxLevel++;
		for (int i = 0; i < size; ++i) {
			Node* current = tempQ.front();
			tempQ.pop();
			if (current->left) tempQ.push(current->left);
			if (current->right) tempQ.push(current->right);
		}
	}
	while (!q.empty()) {
		int size = q.size(); 
		int spaces = std::pow(2, maxLevel - level) - 1;
		for (int i = 0; i < spaces; ++i) {
			std::cout << " ";
		}
		for (int i = 0; i < size; ++i) {
			Node* current = q.front();
			q.pop();
			if (current) {
				std::cout << current->value;
			}
			else {
				std::cout << "  ";
			}
			for (int j = 0; j < 2 * spaces + 1; ++j) {
				std::cout << " ";
			}
			if (current) {
				q.push(current->left);
				q.push(current->right);
			}
			else {
				q.push(nullptr);
				q.push(nullptr);
			}
		}

		std::cout << std::endl;
		level++;
		bool allNull = true;
		std::queue<Node*> temp = q;
		while (!temp.empty()) {
			if (temp.front()) {
				allNull = false;
				break;
			}
			temp.pop();
		}
		if (allNull) break;
	}
}
void BST::VerticalPrint() {
	VerticalPrint(root);
}
BST::BST() {
	root = nullptr;
}
	

