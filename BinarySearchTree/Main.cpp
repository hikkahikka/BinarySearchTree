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
	generator.GenerateTree(tree, 10);
	printer.HorizontalPrint(tree);
	generator.GenerateTree(tree, 10);
	printer.HorizontalPrint(tree);
	
}


