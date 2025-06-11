#include "BSTGenerator.h"
void BSTGenerator::GenerateTree(BST& tree, int n, int start, int finish) {
	tree.DeleteTree();
	GenerateNodes(tree, n, start, finish);
}

void BSTGenerator::GenerateTree(BST& tree, int n) {
	GenerateTree(tree, n, 0, 100);
}

void BSTGenerator::GenerateNodes(BST& tree, int n, int start, int finish) {
	int value;
	for (int i = 0; i<n; i++) {
		value = rand() % (finish - start + 1);
		if (!tree.ContainsNode(value)) {
			tree.AddNode(value);

		}
		else {
			i--;
		}
	}
}

void BSTGenerator::GenerateNodes(BST& tree, int n) {
	GenerateNodes(tree, n, 0, 100);
}

