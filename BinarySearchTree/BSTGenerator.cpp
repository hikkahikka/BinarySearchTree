#include "BSTGenerator.h"
void BSTGenerator::GenerateTree(BST& tree, int n, int start, int finish) {
	tree.DeleteTree();
	GenerateNodes(tree, n, start, finish);
}


void BSTGenerator::GenerateNodes(BST& tree, int n, int start, int finish) {
	int value;
	if (n >= (finish - start + 1)) {
		for (int i = start; i <= finish; i++) {
			if (!tree.ContainsNode(i)) {
				tree.AddNode(i);

			}
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			value = rand() % (finish - start + 1);
			if (!tree.ContainsNode(value)) {
				tree.AddNode(value);

			}
			else {
				i--;
			}
		}
	}
}
