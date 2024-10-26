#include "Node.h"
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
	}
	~Node() {}
};