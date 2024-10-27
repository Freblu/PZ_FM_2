#pragma once
#include <iostream>
using namespace std;

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

	Node(int x) : : data(x), lewy(nullptr), prawy(nullptr) {}
    ~Node() {}


	int ret_data(void) { return data; }
	void set_data(int x) { data = x; }
	Node* ret_lewy(void) { return lewy; }
	void set_lewy(Node*) { lewy = x; }
	Node* ret_prawy(void) { return prawy; 
	void set_prawy(Node*) { prawy = x; }
};
