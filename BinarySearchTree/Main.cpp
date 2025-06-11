#include "BinarySearchTree.h"
#include "BSTPrinter.h"
#include "BSTSerializer.h"
#include "BSTGenerator.h"

int main()
{
	srand(time(0));
	BST tree;
	BSTPrinter printer;
	BSTGenerator generator;
	generator.GenerateTree(tree, 5, 1, 15);
	printer.HorizontalPrint(tree);
	tree.BuildBalancedTree();
	printer.HorizontalPrint(tree);
	
}


