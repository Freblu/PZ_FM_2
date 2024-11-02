#pragma once
#include "Node.h"
/**
 * @brief Zwraca wartość przechowywaną w węźle.
 * @return Wartość `data`.
 */
int Node::ret_data(void)
{
	return data;
};
/**
 * @brief Ustawia nową wartość przechowywaną w węźle.
 * @param x Nowa wartość do ustawienia.
 */
void Node::set_data(int x)
{
	data = x;
};
/**
 * @brief Ustawia wskaźnik na lewego potomka węzła.
 * @param x Wskaźnik na nowy lewy węzeł.
 */
void Node::set_lewy(Node* x) {
	lewy = x;
};
/**
 * @brief Zwraca wskaźnik na lewego potomka węzła.
 * @return Wskaźnik `lewy`.
 */
Node* Node::ret_lewy(void)
{
	return lewy;
};

/**
 * @brief Zwraca wskaźnik na prawego potomka węzła.
 * @return Wskaźnik `prawy`.
 */
Node* Node::ret_prawy(void)
{
	return prawy;
};
/** @file BST.h
 *  @brief Plik nagłówkowy definiujący klasę BST, reprezentującą drzewo binarne.
 */
/**
 * @brief Ustawia wskaźnik na prawego potomka węzła.
 * @param x Wskaźnik na nowy prawy węzeł.
 */
void Node::set_prawy(Node* x)
{
	prawy = x;
};
/** @file BST.h
 *  @brief Plik nagłówkowy definiujący klasę BST, reprezentującą drzewo binarne.
 */