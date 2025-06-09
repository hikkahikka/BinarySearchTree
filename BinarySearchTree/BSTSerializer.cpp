#include "BSTSerializer.h"
bool BSTSerializer::DeserializeTree(BST* tree, std::string path) {
	std::string value;
	std::ifstream fin(path);
	if (fin.is_open())
	{
		while (fin >> value) {
			tree->AddNode(std::stoi(value));
		}
		fin.close();
		return true;
	}
	std::cout << "File is not open!";
	return false;
	
}
bool BSTSerializer::SerializeTree(BST* tree, std::string path) {
	std::ofstream fout(path);
	if (fout.is_open()) {
		SerializeTree(tree->GetRoot(), fout);
		fout.close();
		return true;
	}
	std::cout << "File is not open!";
	return false;
}

void BSTSerializer::SerializeTree(Node* root, std::ofstream& fout) {
	if (root == nullptr) return;	
	fout << root->value << " "; 
	SerializeTree(root->left, fout); 
	SerializeTree(root->right, fout); 
}