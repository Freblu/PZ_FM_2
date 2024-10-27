#include "BST.h"
int main()
{
	BST A;

	for (int i = 1; i < 5; i++)
	{
		A.Dodanie(i);
	}
	for (int i = -1; i > -4; i--)
	{
		A.Dodanie(i);
	}

	A.wyp_all();

}