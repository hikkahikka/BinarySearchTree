#include "BinarySearchTree.h"
#include "BSTPrinter.h"
#include "BSTSerializer.h"

int main()
{
	BST tree;
	tree.AddNode(10);
	tree.AddNode(20);
	tree.AddNode(6);
	tree.AddNode(3);
	tree.AddNode(8);
	tree.AddNode(15);
	BSTSerializer serializer;
	serializer.SerializeTree(&tree, "bob.txt");
	BSTPrinter printer;
	printer.HorizontalPrint(&tree);
	printer.VerticalPrint(&tree);
	
}


