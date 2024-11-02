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
	Node* usun(Node* node, int x);
	Node* znajdzMin(Node* node);
	void wyczysc(Node* node);
	bool znajdzSciezke(Node* node, int x, std::vector<int>& path);
	void Usun(int x);
	void wyczysc();
	bool znajdzSciezke(int x, std::vector<int>& path);
};

