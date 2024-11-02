#pragma once
#include "Node.h"
int Node::ret_data(void)
{
	return data;
};
void Node::set_data(int x)
{
	data = x;
};
void Node::set_lewy(Node* x) {
	lewy = x;
};
Node* Node::ret_lewy(void)
{
	return lewy;
};
Node* Node::ret_prawy(void)
{
	return prawy;
};
void Node::set_prawy(Node* x)
{
	prawy = x;
};