#include "BinarySearchTree.h"
#include "BSTPrinter.h"
#include "BSTSerializer.h"

int main()
{
	BST tree;
	//tree.DeserializeTree("bob.txt");
	
	BSTSerializer serializer;
	serializer.DeserializeTree(&tree, "bob.txt");
	BSTPrinter printer(tree.GetRoot());
	printer.HorizontalPrint();
}


