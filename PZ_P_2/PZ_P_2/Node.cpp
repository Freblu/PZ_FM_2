#include "Node.h"
int Node::ret_data()
{
	return data;
}

void Node::set_data(int x)
{
	data = x;
}

Node* Node::ret_lewy()
{
	return lewy;
}

Node* Node::ret_prawy()
{
	return prawy;
}

void Node::set_lewy(Node* x)
{
	lewy = x;
}
void Node::set_prawy(Node* x)
{
	prawy = x;
}