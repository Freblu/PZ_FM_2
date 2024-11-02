#pragma once
#include <iostream>
#include <fstream>
#include <string>
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

	Node(int x)
	{
		data = x;
		lewy = nullptr;
		prawy = nullptr;
	};
    ~Node() {}

	
	int ret_data(void);
	void set_data(int x);
	Node* ret_lewy(void);
	void set_lewy(Node* x);
	Node* ret_prawy(void);
	void set_prawy(Node* x);
};
