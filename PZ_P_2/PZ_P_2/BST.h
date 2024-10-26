#pragma once
#include "Node.cpp"
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
	void wys_pr(void);
};

