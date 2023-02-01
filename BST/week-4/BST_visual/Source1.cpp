#include "Source2.cpp"
#include <cstddef>
#include <stdio.h>
class BST
{
	Node * root;
public:
	BST()
	{
		root = NULL;
	}
	void insert(int v)
	{
		//root = insert(root, v , NULL);
		Node* temp = new Node(v);
		iinsert(temp);
	}
	Node* insert(Node * r,int v , Node * p)
	{
		if (r == NULL)
		{
			Node* temp = new Node(v);
			temp->parent = p;
			return temp;
		}
		else if(r->val > v)
		{
			r->left = insert(r->left, v, r);
		}
		else
		{
			r->right = insert(r->right, v ,r);
		}
		return r;
	}
	void iinsert(Node* z)
	{
		Node* y = NULL;
		Node* x = root;
		while (x != NULL)
		{
			y = x;
			if (x->val < z->val)
			{
				x = x->right;
			}
			else
			{
				x = x->left;
			}
		}
		z->parent = y;
		if (y == NULL)
		{
			root = z;
		}
		else if (y->val > z->val)
		{
			y->left = z;
		}
		else
		{
			y->right = z;
		}
	}
	void search(int v)
	{
		Node* temp = search(root, v);
		if (temp == NULL)
		{
			printf("The value was not found in the BST !!\n");
		}
		else
		{
			printf("%d was found in the BST !!\n", temp->val);
		}
	}
	Node* search(Node* r, int v)
	{
		if ( r == NULL || r->val == v)
		{
			return r;
		}
		else if (r->val > v)
		{
			return search(r->left, v);
		}
		else
		{
			return search(r->right, v);
		}
	}
	Node* FindMin(Node* x)
	{
		while (x->left != NULL)
			x = x->left;
		return x;
	}
	void Transplant(Node* u, Node* v)
	{
		if (u->parent == NULL)
			root = v;
		else if (u == u->parent->left)
			u->parent->left = v;
		else u->parent->right = v;
		if (v != NULL)
			v->parent = u->parent;
	}
	void DeleteByVal(int v)
	{
		Node* temp = search(root,v);
		if (temp == NULL)
		{
			printf("The node was not found in BST");
		}
		else
		{
			DeleteNode(temp);
		}
	}
	void DeleteNode(Node* z)
	{
		if (z->left == NULL)
			Transplant(z, z->right);
		else if (z->right == NULL)
			Transplant(z, z->left);
		else
		{
			Node* y = FindMin(z->right);
			if (y->parent != z)
			{
				Transplant(y, y->right);
				y->right = z->right;
				y->right->parent = y;
			}
			Transplant(z, y);
			y->left = z->left;
			y->left->parent = y;
		}
	}
	void inOrder()
	{
		if (root == NULL)
		{
			printf("The tree is empty!!\n");
		}
		inOrder(root);
		printf("\n");
	}
	void inOrder(Node * r)
	{
		if (r != NULL)
		{
			inOrder(r->left);
			printf("%d ", r->val);
			inOrder(r->right);
		}
	}
};