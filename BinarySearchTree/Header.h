#pragma once
#include <iostream>

struct Node {
	Node* left;
	Node* right;
	int value;
	Node(int v) {
		value = v;
		left = nullptr;
		right = nullptr;
	}
};
