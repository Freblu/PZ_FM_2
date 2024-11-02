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
    void wypiszPreorder(Node* node);
    void wypiszInorder(Node* node);
    void wypiszPostorder(Node* node);
public:
	BST() : root(nullptr) {}
	~BST() {wyczysc();}

	void Dodanie(int x);
    void Usun(int x);
    void wyczysc();
    bool znajdzSciezke(int x, std::vector<int>& path);
    void wyp_all(int orderType); // 1 - Preorder, 2 - Inorder, 3 - Postorder
    void zapiszDoPliku(const std::string& filename);
};

