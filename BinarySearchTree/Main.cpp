#include "BinarySearchTree.h"
#include "BSTPrinter.h"
int main()
{
	BST tree;
	tree.DeserializeTree("bob.txt");
	BSTPrinter printer(tree.GetRoot());
    printer.HorizontalPrint();
}


