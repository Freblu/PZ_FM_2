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
	cout << "\nwybierz sposob wyswietlenia\n1 - preorder\n2 - inorder\n3 - postorder\n";
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

void BST::f_order(void)
{
	int x = 0;
	cout << "\nwybierz sposob zapisu do pliku\n1 - preorder\n2 - inorder\n3 - postorder\n";
	cin >> x;
	cout << "\n";
	switch(x)
	{
	case(1):
	{
		fstream pre("Preorder.txt", ios::out);
		f_pror(root, pre);
		pre.close();
		break;
	}
	case(2):
	{
		fstream in("Inorder.txt", ios::out);
		f_inor(root, in);
		in.close();
		break;
	}
	case(3):
	{
		fstream post("Postorder.txt", ios::out);
		f_poor(root, post);
		post.close();
		break;
	}
		default:
		{
			cout << "\nnie wybrano zadnej z dostepnych opcji\n";
			break;
		}
	}
}

void BST::f_pror(Node* node, fstream& file)
{
	if (node != NULL)
	{
		file << node->ret_data() << " ";
		f_pror(node->ret_lewy(), file);
		f_pror(node->ret_prawy(), file);
	};
}

void BST::f_inor(Node* node, fstream& file)
{
	if (node != NULL)
	{
		f_inor(node->ret_lewy(), file);
		file << node->ret_data() << " ";
		f_inor(node->ret_prawy(), file);
	};
}
void BST::f_poor(Node* node, fstream& file)
{

	if (node != NULL)
	{
		f_poor(node->ret_lewy(), file);
		f_poor(node->ret_prawy(), file);
		file << node->ret_data() << " ";
	};

}


