/** @file BST.cpp
 *  @brief Implementacja metod klasy BST.
 */
#pragma once
#include "BST.h"

/**
 * @brief Dodaje nowy element do drzewa.
 * @param x Wartość do dodania.
 * 
 * Metoda dodaje nowy element do drzewa zgodnie z zasadami BST.
 */

void BST::Dodanie(int x) {
	if (root == nullptr)
	{
		root = new Node(x);///< Tworzy nowy węzeł jako korzeń drzewa, jeśli drzewo jest puste.
	}
	else
	{
		Node* Loc = root; ///< Zmienna pomocnicza do poruszania się po drzewie.
		while (true)
		{
			if (x >= Loc->ret_data())
			{
				if (Loc->ret_prawy() == nullptr)
				{
					Loc->set_prawy(new Node(x)); ///< Dodaje nowy węzeł jako prawego potomka.
					break;
				}
				else
				{
					if (Loc->ret_prawy()->ret_data() < x)
					{
						Loc = Loc->ret_prawy(); ///< Przechodzi do prawego potomka.
					}
					else
					{
						Node* temp = Loc->ret_prawy();
						Loc->set_prawy(new Node(x)); ///< Wstawia nowy węzeł i przesuwa dotychczasowego potomka w prawo.
						Loc->ret_prawy()->set_prawy(temp);
						break;
					}
				}
			}
			else
			{
				if (Loc->ret_lewy() == nullptr)
				{
					Loc->set_lewy(new Node(x)); ///< Dodaje nowy węzeł jako lewego potomka.
					break;
				}
				else
				{
					if (Loc->ret_lewy()->ret_data() >= x)
					{
						Loc = Loc->ret_lewy(); ///< Przechodzi do lewego potomka.
					}
					else
					{
						Node* temp = Loc->ret_lewy();
						Loc->set_lewy(new Node(x));  ///< Wstawia nowy węzeł i przesuwa dotychczasowego potomka w lewo.
						Loc->ret_lewy()->set_lewy(temp);
						break;
					}
				}
			}
		}

	}
}
/**
 * @brief Wyświetla drzewo w wybranym porządku.
 * 
 * Użytkownik może wybrać metodę wyświetlania: preorder, inorder lub postorder.
 */

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

/**
 * @brief Wyświetla drzewo w porządku preorder.
 * @param node Wskaźnik na aktualny węzeł.
 */
void BST::preorder(Node* node)
{
	if (node != NULL) {
		cout << node->ret_data() << " ";///< Wyświetla wartość bieżącego węzła.
		preorder(node->ret_lewy());///< Przechodzi do lewego potomka.
		preorder(node->ret_prawy());///< Przechodzi do prawego potomka.
	}
}
/**
 * @brief Wyświetla drzewo w porządku inorder.
 * @param node Wskaźnik na aktualny węzeł.
 */
void BST::inorder(Node* node)
{
	if (node != NULL) {
		inorder(node->ret_lewy());///< Przechodzi do lewego potomka.
		cout << node->ret_data() << " ";///< Wyświetla wartość bieżącego węzła.
		inorder(node->ret_prawy());///< Przechodzi do prawego potomka.
	}
}
/**
 * @brief Wyświetla drzewo w porządku postorder.
 * @param node Wskaźnik na aktualny węzeł.
 */
void BST::postorder(Node* node)
{
	if (node != NULL) {
		postorder(node->ret_lewy());///< Przechodzi do lewego potomka.
		postorder(node->ret_prawy());///< Przechodzi do prawego potomka.
		cout << node->ret_data() << " ";///< Wyświetla wartość bieżącego węzła.
}
}
/**
 * @brief Zapisuje drzewo do pliku w wybranym porządku.
 * 
 * Użytkownik może wybrać sposób zapisu: preorder, inorder lub postorder.
 */
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
		f_pror(root, pre);///< Zapisuje drzewo w porządku preorder.
		pre.close();

		cout << "Drzewo zapisane do pliku 'Preorder.txt'." << endl;
		break;
	}
	case(2):
	{
		fstream in("Inorder.txt", ios::out);
		f_inor(root, in); ///< Zapisuje drzewo w porządku inorder.
		in.close();

		cout << "Drzewo zapisane do pliku 'Inorder.txt'." << endl;
		break;
	}
	case(3):
	{
		fstream post("Postorder.txt", ios::out);
		f_poor(root, post);///< Zapisuje drzewo w porządku postorder.
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

/**
 * @brief Zapisuje drzewo do pliku w porządku preorder.
 * @param node Wskaźnik na aktualny węzeł.
 * @param file Referencja do obiektu fstream, do którego następuje zapis.
 */
void BST::f_pror(Node* node, fstream& file)
{
	if (node != NULL)
	{
		file << node->ret_data() << " ";
		f_pror(node->ret_lewy(), file);
		f_pror(node->ret_prawy(), file);
	};
}
/**
 * @brief Zapisuje drzewo do pliku w porządku inorder.
 * @param node Wskaźnik na aktualny węzeł.
 * @param file Referencja do obiektu fstream, do którego następuje zapis.
 */
void BST::f_inor(Node* node, fstream& file)
{
	if (node != NULL)
	{
		f_inor(node->ret_lewy(), file);
		file << node->ret_data() << " ";
		f_inor(node->ret_prawy(), file);
	};
}
/**
 * @brief Zapisuje drzewo do pliku w porządku postorder.
 * @param node Wskaźnik na aktualny węzeł.
 * @param file Referencja do obiektu fstream, do którego następuje zapis.
 */
void BST::f_poor(Node* node, fstream& file)
{

	if (node != NULL)
	{
		f_poor(node->ret_lewy(), file);
		f_poor(node->ret_prawy(), file);
		file << node->ret_data() << " ";
	};

}
/**
 * @brief Odczytuje dane z pliku i buduje drzewo BST.
 * @param fname Nazwa pliku do odczytu.
 * @param x Typ danych: 1 dla dziesiętnych, inny dla binarnych.
 * 
 * Metoda odczytuje dane z pliku i konwertuje je na wartości liczbowe, które są dodawane do drzewa. 
 * Sprawdza poprawność danych i obsługuje zarówno liczby dziesiętne, jak i binarne.
 */
void BST::f_read(string fname, int x)
{
	fstream file2(fname, ios::in);///< Otwiera plik do odczytu
	string line;
	char c;
	string d;
	if (x == 1)///< Odczyt danych dziesiętnych.
	{
		while (file2.get(c)) {
			if (c != '1' && c != '2' && c != '3' && c != '4' && c != '5' && c != '6' && c != '7' && c != '8' && c != '9' && c != '0' && c != ' ')
			{
				cout << "blad, zle dane w pliku wejsciowym";
				break;
			}
			else ///< Odczyt danych binarnych.
			{
				d = d + c;
				if (c == ' ')
				{
					int number = stoi(d);///< Konwertuje ciąg na liczbę całkowitą.
					Dodanie(number);///< Dodaje liczbę do drzewa.
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
	file2.close();///< Zamyka plik po zakończeniu odczytu.
}
/**
 * @brief Usuwa element o podanej wartości z drzewa.
 * @param x Wartość do usunięcia.
 * 
 * Metoda wywołuje funkcję rekurencyjną, która usuwa węzeł i aktualizuje strukturę drzewa.
 */

void BST::Usun(int x) {
	root = usun(root, x);///< Wywołuje rekurencyjną funkcję usuwania.
}
/**
 * @brief Rekurencyjna metoda usuwająca węzeł z drzewa.
 * @param node Wskaźnik na aktualny węzeł.
 * @param x Wartość do usunięcia.
 * @return Zwraca wskaźnik na zaktualizowany węzeł.
 * 
 * Usuwa węzeł, zachowując właściwości drzewa BST. Obsługuje przypadki, gdy węzeł ma jednego lub dwóch potomków.
 */
Node* BST::usun(Node* node, int x) {
	if (!node) return nullptr;///< Zwraca nullptr, jeśli węzeł nie istnieje.
	if (x < node->ret_data()) node->set_lewy(usun(node->ret_lewy(), x));///< Przechodzi do lewego poddrzewa.
	else if (x > node->ret_data()) node->set_prawy(usun(node->ret_prawy(), x));///< Przechodzi do prawego poddrzewa.
	else {
		if (!node->ret_lewy()) {///< Węzeł bez lewego potomka.
			Node* rightChild = node->ret_prawy();
			delete node;///< Usuwa węzeł.
			return rightChild;///< Zwraca prawego potomka.
		}
		if (!node->ret_prawy()) {///< Węzeł bez prawego potomka.
			Node* leftChild = node->ret_lewy();
			delete node;///< Usuwa węzeł.
			return leftChild;///< Zwraca lewego potomka
		}
		Node* minNode = znajdzMin(node->ret_prawy());Znajduje najmniejszy węzeł w prawym poddrzewie.
		node->set_data(minNode->ret_data());///< Kopiuje dane najmniejszego węzła.
		node->set_prawy(usun(node->ret_prawy(), minNode->ret_data()));///< Usuwa najmniejszy węzeł z prawego poddrzewa.
    }
	}
	return node;

/**
 * @brief Znajduje najmniejszy element w poddrzewie.
 * @param node Wskaźnik na aktualny węzeł.
 * @return Wskaźnik na węzeł o najmniejszej wartości.
 */
Node* BST::znajdzMin(Node* node) {
	while (node && node->ret_lewy()) node = node->ret_lewy();
	return node;
}

/**
 * @brief Usuwa wszystkie węzły z drzewa.
 */
void BST::wyczysc() {
	wyczysc(root);
	root = nullptr;
}
/**
 * @brief Rekurencyjnie usuwa wszystkie węzły z drzewa.
 * @param node Wskaźnik na aktualny węzeł.
 */
void BST::wyczysc(Node* node) {
	if (!node) return;
	wyczysc(node->ret_lewy());
	wyczysc(node->ret_prawy());
	delete node;
}
/**
 * @brief Szuka ścieżki do podanej wartości w drzewie.
 * @param x Wartość do znalezienia.
 * @param path Wektor przechowujący ścieżkę do znalezionego węzła.
 * @return Zwraca `true`, jeśli ścieżka została znaleziona, w przeciwnym razie `false`.
 */
bool BST::znajdzSciezke(int x, std::vector<int>& path) {
	return znajdzSciezke(root, x, path);
}
/**
 * @brief Rekurencyjnie szuka ścieżki do podanej wartości w drzewie.
 * @param node Wskaźnik na aktualny węzeł.
 * @param x Wartość do znalezienia.
 * @param path Wektor przechowujący ścieżkę do znalezionego węzła.
 * @return Zwraca `true`, jeśli ścieżka została znaleziona, w przeciwnym razie `false`.
 */
bool BST::znajdzSciezke(Node* node, int x, std::vector<int>& path) {
	if (!node) return false;
	path.push_back(node->ret_data());
	if (node->ret_data() == x) return true;
	if (x < node->ret_data() && znajdzSciezke(node->ret_lewy(), x, path)) return true;
	if (x > node->ret_data() && znajdzSciezke(node->ret_prawy(), x, path)) return true;
	path.pop_back();
	return false;
}
