#include "BSTPrinter.h"

void BSTPrinter::HorizontalPrint(Node* node, std::string prefix, bool isLeft) {
	std::string top_right = std::string(1, char(192)) + std::string(2, char(196)) + " ";
	std::string vert = std::string(1, char(179));
	std::string bottom_right = std::string(1, char(218)) + std::string(2, char(196)) + " ";
	if (node->right) {
		HorizontalPrint(node->right, prefix + (isLeft ? vert + "   " : "    "), false);
	}

	std::cout << prefix + (isLeft ? top_right : bottom_right) + std::to_string(node->value) + "\n";

	if (node->left) {
		HorizontalPrint(node->left, prefix + (isLeft ? "    " : vert + "   "), true);
	}
}

void BSTPrinter::HorizontalPrint(BST& tree) {
	Node* root = tree.GetRoot();
	std::cout << "\n";
	if (root == nullptr) {
		std::cout << "Tree is empty!"<<std::endl;
		return;
	}
	HorizontalPrint(root);
}
void BSTPrinter::VerticalPrint(BST& tree) {
	Node* root = tree.GetRoot();
	if (!root) {
		std::cout << "Tree is empty!" << std::endl;
		return;
	}
	std::cout << "\n";
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
				std::cout << " ";
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
