#pragma once
#include "Node.h"

/**
 * @class BST
 * @brief Klasa reprezentująca drzewo binarne (BST).
 */
class BST
{
private:
	Node* root; //< Wskaźnik na korzeń drzewa BST.
public:
  /**
     * @brief Konstruktor klasy BST.
     * 
     * Inicjalizuje drzewo binarne z korzeniem ustawionym na `nullptr`.
     */
	BST()
	{
		root = nullptr;
	};
	   /**
     * @brief Destruktor klasy BST.
     * 
     * Domyślny destruktor klasy.
     */
	~BST() {};
	    /**
     * @brief Dodaje nowy element do drzewa.
     * @param x Wartość do dodania.
     */
	void Dodanie(int x);

    /**
     * @brief Wyświetla drzewo w wybranym porządku (inorder, preorder, postorder).
     */
	void c_order(void);
	 /**
     * @brief Rekurencyjnie wyświetla drzewo w porządku preorder.
     * @param node Wskaźnik na aktualny węzeł.
     */
	void preorder(Node* node);
	  /**
     * @brief Rekurencyjnie wyświetla drzewo w porządku inorder.
     * @param node Wskaźnik na aktualny węzeł.
     */
	void inorder(Node* node);
	 /**
     * @brief Rekurencyjnie wyświetla drzewo w porządku postorder.
     * @param node Wskaźnik na aktualny węzeł.
     */
	void postorder(Node* node);

    /**
     * @brief Zapisuje drzewo do pliku w wybranym porządku.
     */
	void f_order(void);
	 /**
     * @brief Zapisuje drzewo do pliku w porządku preorder.
     * @param node Wskaźnik na aktualny węzeł.
     * @param file Referencja do obiektu fstream.
     */
	void f_pror(Node* node, fstream& file);
	 /**
     * @brief Zapisuje drzewo do pliku w porządku inorder.
     * @param node Wskaźnik na aktualny węzeł.
     * @param file Referencja do obiektu fstream.
     */
	void f_inor(Node* node, fstream& file);
	 /**
     * @brief Zapisuje drzewo do pliku w porządku postorder.
     * @param node Wskaźnik na aktualny węzeł.
     * @param file Referencja do obiektu fstream.
     */
	void f_poor(Node* node, fstream& file);
	 /**
     * @brief Odczytuje drzewo z pliku.
     * @param fname Nazwa pliku.
     * @param x Wartość kontrolna (opcjonalna).
     */
	void f_read(string fname, int x);
	/**
     * @brief Usuwa węzeł o podanej wartości z drzewa.
     * @param node Wskaźnik na aktualny węzeł.
     * @param x Wartość do usunięcia.
     * @return Wskaźnik na zaktualizowany węzeł.
     */
	Node* usun(Node* node, int x);
	 /**
     * @brief Znajduje najmniejszy element w drzewie.
     * @param node Wskaźnik na aktualny węzeł.
     * @return Wskaźnik na węzeł o najmniejszej wartości.
     */
	Node* znajdzMin(Node* node);
	 /**
     * @brief Usuwa wszystkie węzły z drzewa rekurencyjnie.
     * @param node Wskaźnik na aktualny węzeł.
     */
	void wyczysc(Node* node);
	   /**
     * @brief Szuka ścieżki do podanej wartości w drzewie.
     * @param node Wskaźnik na aktualny węzeł.
     * @param x Wartość do znalezienia.
     * @param path Wektor przechowujący ścieżkę do znalezionego węzła.
     * @return Zwraca `true`, jeśli ścieżka została znaleziona, w przeciwnym razie `false`.
     */
	bool znajdzSciezke(Node* node, int x, std::vector<int>& path);
	  /**
     * @brief Usuwa węzeł o podanej wartości z drzewa.
     * @param x Wartość do usunięcia.
     */
	void Usun(int x);
	 /**
     * @brief Usuwa wszystkie węzły z drzewa.
     */
	void wyczysc();
	 /**
     * @brief Szuka ścieżki do podanej wartości w drzewie.
     * @param x Wartość do znalezienia.
     * @param path Wektor przechowujący ścieżkę do znalezionego węzła.
     * @return Zwraca `true`, jeśli ścieżka została znaleziona, w przeciwnym razie `false`.
     */
	bool znajdzSciezke(int x, std::vector<int>& path);
};

