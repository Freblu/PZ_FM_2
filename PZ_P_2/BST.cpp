#pragma once
#include "BST.h"




void BST::Dodanie(int x) {
	if (root == nullptr)
	{
		root = new Node(x);
	}
	else
	{
		Node* Loc = root;
		if (x >= root->ret_data())
		{
			while (Loc->ret_prawy() != nullptr && Loc->ret_data() <= x)
			{
				Loc = Loc->ret_prawy();
			}
			if (Loc->ret_prawy() == nullptr)
			{
				Loc->set_prawy(new Node(x));
			}
			else
			{
				Node* temp = Loc->ret_prawy();
				Loc->set_prawy(new Node(x));
				Loc->ret_prawy()->set_prawy(temp);
			}
		}
		else
		{
			while (Loc->ret_lewy() != nullptr && Loc->ret_data() >= x)
			{
				Loc = Loc->ret_lewy();
			}
			if (Loc->ret_lewy() == nullptr)
			{
				Loc->set_lewy(new Node(x));
			}
			else
			{
				Node* temp = Loc->ret_lewy();
				Loc->set_lewy(new Node(x));
				Loc->ret_lewy()->set_lewy(temp);
			}
		}
	}
}

// Usuń element z drzewa
void BST::Usun(int x) {
    root = usun(root, x);
}

Node* BST::usun(Node* node, int x) {
    if (!node) return nullptr;
    if (x < node->ret_data()) node->set_lewy(usun(node->ret_lewy(), x));
    else if (x > node->ret_data()) node->set_prawy(usun(node->ret_prawy(), x));
    else {
        if (!node->ret_lewy()) {
            Node* rightChild = node->ret_prawy();
            delete node;
            return rightChild;
        }
        if (!node->ret_prawy()) {
            Node* leftChild = node->ret_lewy();
            delete node;
            return leftChild;
        }
        Node* minNode = znajdzMin(node->ret_prawy());
        node->set_data(minNode->ret_data());
        node->set_prawy(usun(node->ret_prawy(), minNode->ret_data()));
    }
    return node;
}

Node* BST::znajdzMin(Node* node) {
    while (node && node->ret_lewy()) node = node->ret_lewy();
    return node;
}

void BST::wyp_all()
{
	if (root == nullptr)
	{
		cout << "puste drzewo" << endl;
	}
	else
	{
		cout << "lewa strona :" << endl;
		Node* Loc = root;
		cout << Loc->ret_data() << endl;
		while (Loc->ret_lewy() != nullptr)
		{
			Loc = Loc->ret_lewy();
			cout << Loc->ret_data() << endl;
		}
		cout << "prawa strona :" << endl;
		Loc = root;
		cout << Loc->ret_data() << endl;
		while (Loc->ret_prawy() != nullptr)
		{
			Loc = Loc->ret_prawy();
			cout << Loc->ret_data() << endl;
		}
	}
}

