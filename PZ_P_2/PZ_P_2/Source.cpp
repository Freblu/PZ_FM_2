#include "BST.h"
int main()
{
	BST A;

	A.Dodanie(100);
	A.Dodanie(20);
	A.Dodanie(200);
	A.Dodanie(10);
	A.Dodanie(30);
	A.Dodanie(150);
	A.Dodanie(300);
	A.c_order();
	A.f_order();
}