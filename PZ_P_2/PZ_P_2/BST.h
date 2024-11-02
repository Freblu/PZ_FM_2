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
	void c_order(void);
	void preorder(Node* node);
	void inorder(Node* node);
	void postorder(Node* node);
	void f_order(void);
	void f_pror(Node* node, fstream& file);
	void f_inor(Node* node, fstream& file);
	void f_poor(Node* node, fstream& file);
	void f_read(string fname, int x);
};

