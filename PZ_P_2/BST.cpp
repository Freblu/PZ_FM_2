#pragma once
#include "BST.h"

// Dodanie elemenu do drzewa
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

// Usuwanie elementu z drzewa
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

// Usuń całe drzewo
void BST::wyczysc() {
    wyczysc(root);
    root = nullptr;
}

void BST::wyczysc(Node* node) {
    if (!node) return;
    wyczysc(node->ret_lewy());
    wyczysc(node->ret_prawy());
    delete node;
}

Node* BST::znajdzMin(Node* node) {
    while (node && node->ret_lewy()) node = node->ret_lewy();
    return node;
}

//wyświetlenie drzewa
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

// Szukaj ścieżki do elementu
bool BST::znajdzSciezke(int x, std::vector<int>& path) {
    return znajdzSciezke(root, x, path);
}

bool BST::znajdzSciezke(Node* node, int x, std::vector<int>& path) {
    if (!node) return false;
    path.push_back(node->ret_data());
    if (node->ret_data() == x) return true;
    if (x < node->ret_data() && znajdzSciezke(node->ret_lewy(), x, path)) return true;
    if (x > node->ret_data() && znajdzSciezke(node->ret_prawy(), x, path)) return true;
    path.pop_back();
    return false;
}

