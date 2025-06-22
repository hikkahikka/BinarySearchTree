#include "UserInterface.h"
bool UserInterface::Start(BST& tree) {
	std::cout <<"Select an item from the menu:\n"
		"0) Exit\n"
		"1) Add an element to the tree\n"
		"2) Remove an element from the tree\n"
		"3) Delete the entire tree\n"
		"4) Search for an element in the tree\n"
		"5) Draw the tree horizontally\n"
		"6) Draw the tree vertically\n"
		"7) Serialize the tree\n"
		"8) Deserialize the tree\n"
		"9) Generate a tree of n random numbers\n"
		"10) Generate n random elements\n"
		"11) Balance the tree\n";;
	int input = InputValue(0, 11);
	switch (input)
	{
	case 0: {
		return false;
	}
	case 1: {
		AddNode(tree);
		break;
	}
	case 2: {
		DeleteNode(tree);
		break;
	}
	case 3: {
		tree.DeleteTree();
		std::cout << "The tree has been removed successfully!" << std::endl;
		break;
	}
	case 4: {
		ContainsNode(tree);
		break;
	}
	case 5: {
		BSTPrinter printer;
		printer.HorizontalPrint(tree);
		break;
	}
	case 6: {
		BSTPrinter printer;
		printer.VerticalPrint(tree);
		break;
	}
	case 7: {
		SerializeTree(tree);
		break;
	}
	case 8: {
		DeserializeTree(tree);
		break;
	}
	case 9:{
		GenerateTree(tree);
		break;		
	}
	case 10: {
		GenerateNodes(tree);
		break;
	}
	case 11: {
		tree.BuildBalancedTree();
		std::cout << "The tree has been balanced successfully!" << std::endl;

	}
	}
	return true;
}

int UserInterface::InputValue(int start, int finish) {
	int input;
	//std::cout << "Enter the value: " << std::endl;
	while (true) {
		std::cin >> input;
		if (std::cin.good() && start <= input && input <= finish)
			return input;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Please try again: "<<std::endl;
	}
	return input;
}

void UserInterface::AddNode(BST& tree) {
	while (true) {
		std::cout << "Enter the value: " << std::endl;
		int value = InputValue(INT_MIN, INT_MAX);
		if (!tree.AddNode(value)) {
			std::cout << "The tree cannot contain duplicate elements." << std::endl;
		}
		else {
			std::cout << "The item has been added successfully!" << std::endl;
			return;
		}
	}


}

void UserInterface::DeleteNode(BST& tree) {
	
	std::cout << "Enter the value: " << std::endl;
	int value = InputValue(INT_MIN, INT_MAX);
	if (!tree.DeleteNode(value)) {
		std::cout << "There is no such element in the tree." << std::endl;
	}
	else {
		std::cout << "The item has been removed successfully!" << std::endl;

	}
	
}
void UserInterface::ContainsNode(BST& tree) {
	std::cout << "Enter the value: " << std::endl;
	int value = InputValue(INT_MIN, INT_MAX);
	if (tree.ContainsNode(value)) {
		std::cout << "This element is contained in the tree." << std::endl;
	}
	else std::cout << "This element is not contained in the tree." << std::endl;
}
void UserInterface::SerializeTree(BST& tree) {
	std::string path;
	std::cout << "Input file name: " << std::endl;
	std::cin >> path;
	BSTSerializer serializer;
	while (true) {
		if (!serializer.SerializeTree(tree, path)) {
			std::cout << "The file name is incorrect." << std::endl; 
			std::cout << "Input file name: " << std::endl;
			std::cin >> path;
		}
		else return;
	}
}
void UserInterface::DeserializeTree(BST& tree) {
	std::string path;
	std::cout << "Input file name: " << std::endl;
	std::cin >> path;
	BSTSerializer serializer;
	while (true) {
		if (!serializer.DeserializeTree(tree, path)) {
			std::cout << "The file name is incorrect." << std::endl;
			std::cout << "Input file name: " << std::endl;
			std::cin >> path;
		}
		else return;
	}
}


void UserInterface::GenerateTree(BST& tree) {
	BSTGenerator generator;
	std::cout << "Enter the number of items: " << std::endl;
	int n, a, b;
	n = InputValue(INT_MIN, INT_MAX);
	std::cout << "Enter minimum value: " << std::endl;
	a = InputValue(INT_MIN, INT_MAX);
	std::cout << "Enter maximum value: " << std::endl;
	b = InputValue(a, INT_MAX);
	if (n > b - a + 1) {
		std::cout << "Warning! The number of items in this range is less than the number you entered.\nYour tree consists of "
			<< b - a + 1 << " elements from " << a << " to " << b<<std::endl;
	}
	generator.GenerateTree(tree, n, a, b);
	std::cout << "The tree has been generated successfully!" << std::endl;

}

void UserInterface::GenerateNodes(BST& tree) {
	BSTGenerator generator;
	std::cout << "Enter the number of items: " << std::endl;
	int n, a, b;
	n = InputValue(INT_MIN, INT_MAX);
	std::cout << "Enter minimum value: " << std::endl;
	a = InputValue(INT_MIN, INT_MAX);
	std::cout << "Enter maximum value: " << std::endl;
	b = InputValue(a, INT_MAX);
	if (n > b - a + 1) {
		std::cout << "Warning! The number of items in this range is less than the number you entered.\nYour tree consists of "
			<< b - a + 1 << " elements from " << a << " to " << b << std::endl;
	}
	generator.GenerateNodes(tree, n, a, b);
	std::cout << "The nodes has been generated successfully!" << std::endl;

}