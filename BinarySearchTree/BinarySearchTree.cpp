#include "BinarySearchTree.h"
Node* BST::GetRoot() {
	return root;
}
BST::BST() {
	root = nullptr;
}

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
	if (node == nullptr) return;
	DeleteTree(node->left);
	DeleteTree(node->right);
	delete node;
}

void BST::DeleteTree() {
	DeleteTree(root);
	root = nullptr;
}

void BST::GetSortedVector(Node* node, std::vector<Node*>& nodes) {
	if (node == nullptr) return;

	GetSortedVector(node->left, nodes);
	nodes.push_back(node);
	GetSortedVector(node->right, nodes);
}


Node* BST::BuildBalancedTree(std::vector<Node*>& nodes, int start, int end) {
	if (start > end) return nullptr;
	int mid = (start + end) / 2;
	Node* node = nodes[mid];
	node->left = BuildBalancedTree(nodes, start, mid - 1);
	node->right = BuildBalancedTree(nodes, mid + 1, end);
	return node;
}

void BST::BuildBalancedTree() {
	std::vector<Node*> nodes;
	GetSortedVector(root, nodes);
	root = BuildBalancedTree(nodes, 0, nodes.size() - 1);
}

//bool BST::IsEmpty() {
//	return root == nullptr;
//}