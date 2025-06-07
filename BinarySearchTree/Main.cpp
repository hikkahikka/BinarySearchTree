#include "BinarySearchTree.h"
int main()
{
	
	BST tree;
	
	 tree.AddNode(20);
	 tree.AddNode(10);
	 tree.AddNode(50);
	 tree.AddNode(15);
	 tree.AddNode(40);
	 tree.AddNode(60);
	 tree.AddNode(70);
	 tree.AddNode(5);
     tree.AddNode(3);


	 tree.AddNode(1);



	 tree.HorizontalPrint();
	 std::cout <<std::endl;
	 tree.VerticalPrint();


}


