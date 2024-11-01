#pragma once
#include "Node.h"
class BST
{
private:
	Node* root;
public:
	BST()
	{
		root = nullptr;
	};
	~BST() {};
	void Dodanie(int x);
	void wyp_all(void);
	void c_order(void);
	void preorder(Node* root);
	void inorder(Node* root);
	void postorder(Node* root);
};

