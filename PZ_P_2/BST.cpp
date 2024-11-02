#pragma once
#include "BST.h"



// Dodanie elementu do drzewa

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


void BST::c_order()
{
	int x = 0;
	cout << "\nPodaj metodę wyświetlania (1-Preorder, 2-Inorder, 3-Postorder): ";
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

		cout << "Drzewo zapisane do pliku 'Preorder.txt'." << endl;
		break;
	}
	case(2):
	{
		fstream in("Inorder.txt", ios::out);
		f_inor(root, in);
		in.close();

		cout << "Drzewo zapisane do pliku 'Inorder.txt'." << endl;
		break;
	}
	case(3):
	{
		fstream post("Postorder.txt", ios::out);
		f_poor(root, post);
		post.close();

		cout << "Drzewo zapisane do pliku 'Postorder.txt'." << endl;
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

void BST::f_read(string fname, int x)
{
	fstream file2(fname, ios::in);
	string line;
	char c;
	string d;
	if (x == 1)
	{
		while (file2.get(c)) {
			if (c != '1' && c != '2' && c != '3' && c != '4' && c != '5' && c != '6' && c != '7' && c != '8' && c != '9' && c != '0' && c != ' ')
			{
				cout << "blad, zle dane w pliku wejsciowym";
				break;
			}
			else
			{
				d = d + c;
				if (c == ' ')
				{
					int number = stoi(d);
					Dodanie(number);
					d = "";
				}
			}
		}
	}
	else
	{
		while (file2.get(c)) {
			if (c != '1' && c != '0' && c != ' ')
			{
				cout << "blad, zle dane w pliku wejsciowym";
				break;
			}
			else
			{
				d = d + c;
				if (c == ' ')
				{
					int number = stoi(d, 0, 2);
					Dodanie(number);
					d = "";
				}
			}
		}
	}
	file2.close();
}

// Usuniecie elementu z drzewa
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

// Usuniecie ca�ego drzewa
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

// Szukanie �cie�ki do elementu
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
