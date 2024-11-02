/** @file Node.h
 *  @brief Plik nagłówkowy definiujący klasę Node, reprezentującą węzeł drzewa BST.
 */
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
/**
 * @class Node
 * @brief Klasa reprezentująca pojedynczy węzeł drzewa BST.
 */
class Node
{
private:
	/// zapis danych
	int data;
	///wskaznik lewy
	Node* lewy;
	/// wskaznik prawy
	Node* prawy;

public:
 /**
     * @brief Konstruktor klasy Node.
     * @param x Wartość do przechowywania w węźle.
     * 
     * Inicjalizuje nowy węzeł, ustawiając wartość `data` i wskaźniki `lewy` oraz `prawy` na nullptr.
     */
	Node(int x)
	{
		data = x;
		lewy = nullptr;
		prawy = nullptr;
	};
	 /**
     * @brief Destruktor klasy Node.
     * 
     * W tej implementacji destruktor jest domyślnie pusty, ponieważ nie zajmuje się on usuwaniem potomków.
     */
    ~Node() {}
 /**
     * @brief Zwraca wartość przechowywaną w węźle.
     * @return Wartość `data`.
     */
	
	int ret_data(void);
	  /**
     * @brief Ustawia nową wartość przechowywaną w węźle.
     * @param x Nowa wartość do ustawienia.
     */
	void set_data(int x);
	 /**
     * @brief Zwraca wskaźnik na lewego potomka węzła.
     * @return Wskaźnik `lewy`.
     */
	Node* ret_lewy(void);
	 /**
     * @brief Ustawia wskaźnik na lewego potomka węzła.
     * @param x Wskaźnik na nowy lewy węzeł.
     */
	void set_lewy(Node* x);
	  /**
     * @brief Zwraca wskaźnik na prawego potomka węzła.
     * @return Wskaźnik `prawy`.
     */
	Node* ret_prawy(void);
	 /**
     * @brief Ustawia wskaźnik na prawego potomka węzła.
     * @param x Wskaźnik na nowy prawy węzeł.
     */
	void set_prawy(Node* x);
	/** @file Node.cpp
 *  @brief Implementacja metod klasy Node.
 */
};
