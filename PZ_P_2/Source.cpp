#include "BST.h"
int main()
{
	BST A;

	for (int i = 1; i < 5; i++)
	{
		A.Dodanie(i);
	}
	for (int i = -2; i > -5; i--)
	{
		A.Dodanie(i);
	}

	A.c_inorder();

     return 0;
}