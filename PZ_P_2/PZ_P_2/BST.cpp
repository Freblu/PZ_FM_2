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
			while (true)
			{
				if (x >= Loc->ret_data())
				{
					if (Loc->ret_prawy() == nullptr)
					{
						Loc->set_prawy(new Node(x));
						break;
					}
					else
					{
						if (Loc->ret_prawy()->ret_data() < x)
						{
							Loc = Loc->ret_prawy();
						}
						else
						{
							Node* temp = Loc->ret_prawy();
							Loc->set_prawy(new Node(x));
							Loc->ret_prawy()->set_prawy(temp);
							break;
						}
					}
				}
				else
				{
					if (Loc->ret_lewy() == nullptr)
					{
						Loc->set_lewy(new Node(x));
						break;
					}
					else
					{
						if (Loc->ret_lewy()->ret_data() >= x)
						{
							Loc = Loc->ret_lewy();
						}
						else
						{
							Node* temp = Loc->ret_lewy();
							Loc->set_lewy(new Node(x));
							Loc->ret_lewy()->set_lewy(temp);
							break;
						}
					}
				}
			}

	}
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

void BST::preorder(Node* node)
{
	if (node != NULL) {
		cout << node->ret_data() << " ";
		preorder(node->ret_lewy());
		preorder(node->ret_prawy());
	}
}

void BST::inorder(Node* node)
{
	if (node != NULL) {
		inorder(node->ret_lewy());
		cout << node->ret_data() << " ";
		inorder(node->ret_prawy());
	}
}

void BST::postorder(Node* node)
{
	if (node != NULL) {
		postorder(node->ret_lewy());
		postorder(node->ret_prawy());
		cout << node->ret_data() << " ";
	}
}


void BST::c_order() 
{
	int x = 0;
	cout << "wybierz sposob wyswietlenia\n1 - preorder\n2 - inorder\n3 - postorder\n";
	cin >> x;
	cout << "\n";
	switch (x)
	{
	case(1):
		preorder(root);
		break;
	case(2):
		inorder(root);
		break;
	case(3):
		postorder(root);
		break;
	default:
	{
		cout << "\nnie wybrano zadnej z dostepnych opcji\n";
		break;
	}
	}

}
