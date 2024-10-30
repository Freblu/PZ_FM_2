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
public:
	BST()
	{
		root = nullptr;
	};
	~BST() {};
	void Dodanie(int x);
	void Usun(int x);
    void wyczysc();
	void wyp_all(void);
};

