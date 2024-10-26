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

