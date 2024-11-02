#pragma once
#include "Node.h"
#include <vector>
#include <fstream>
#include <iostream> 

class BST
{
private:
	Node* root;
	 Node* dodaj(Node* node, int x);
    Node* usun(Node* node, int x);
    Node* znajdzMin(Node* node);
	void wyczysc(Node* node);
	 bool znajdzSciezke(Node* node, int x, std::vector<int>& path);
public:
	BST()
	{
		root = nullptr;
	};
	~BST() {};
	void Dodanie(int x);
	void Usun(int x);
    void wyczysc();
	bool znajdzSciezke(int x, std::vector<int>& path);
	void wyp_all(void);
	void c_inorder(void);
	void inorder(Node* root);
};

