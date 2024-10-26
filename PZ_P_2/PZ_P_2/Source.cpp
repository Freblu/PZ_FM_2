#include "BST.h"
int main()
{
	BST A;
	A.Dodanie(1);

	for (int i = 1; i < 5; i++)
	{
		A.Dodanie(i);
	}
	for (int i = -1; i < 5; i--)
	{
		A.Dodanie(i);
	}

	A.wyp_all();

}