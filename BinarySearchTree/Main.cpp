#include "BinarySearchTree.h"
#include "BSTPrinter.h"
#include "BSTSerializer.h"

int main()
{
	BST tree;
	//tree.DeserializeTree("bob.txt");
	tree.AddNode(10);
	tree.AddNode(20);

	tree.AddNode(6);

	tree.AddNode(3);

	tree.AddNode(8);

	tree.AddNode(15);
	//tree.DeleteNode(15);

	BSTSerializer serializer;
	serializer.SerializeTree(&tree, "bob.txt");
	//serializer.DeserializeTree(&tree, "bob.txt");
	BSTPrinter printer(tree.GetRoot());
	printer.HorizontalPrint();
	std::cout << "aboba\n";
	BST tree2;
	serializer.DeserializeTree(&tree2, "bob.txt");
	BSTPrinter printer2(tree2.GetRoot());
	printer2.HorizontalPrint();
}


