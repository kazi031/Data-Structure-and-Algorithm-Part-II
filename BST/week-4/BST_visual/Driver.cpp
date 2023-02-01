#include<stdio.h>
#include "Source1.cpp"
int main()
{
	BST b1;
	b1.insert(2);
	b1.insert(1);
	b1.insert(5);
	b1.insert(3);
	//b1.inOrder();
	b1.search(3);
	b1.DeleteByVal(2);
	b1.inOrder();
}