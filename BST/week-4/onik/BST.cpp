#include <stdio.h>
struct Node
{
    int val;
    Node * left;
    Node * right;
    Node * parent;

    Node(int v)
    {
        val = v;
        left = right = NULL;
        parent = NULL;
    }
};

class BST
{

public:
    Node * root;
    BST()
    {
        root = NULL;
    }

    void inorder()
    {
        if (root == NULL)
            printf("Tree is empty\n");
        else
            inorder(root);
        printf("\n");
    }



    Node * findMin(Node * x)
    {
        while(x->left != NULL)
            x = x->left;
        return x;
    }

    void inorder(Node * r)
    {
        if (r != NULL)
        {
            inorder(r->left);
            printf("%d ", r->val);
            inorder(r->right);
        }
    }

    void iinsert(Node * z)
    {
        Node * y = NULL;
        Node * x = root;
        while (x != NULL)
        {
            y = x;
            if (z->val < x->val)
                x = x->left;
            else x = x->right;
        }
        z->parent = y;
        if (y == NULL)
            root = z;
        else if (z->val < y->val)
            y->left = z;
        else
            y->right = z;
    }

    void insert(int val)
    {
        //root = insert(root, val, NULL);
        Node * temp = new Node(val);
        iinsert(temp);
    }

    void search(int val)
    {
        Node * temp = search(root, val);
        if (temp == NULL)
            printf("%d not found!\n", val);
        else
            printf("%d found in the BST!\n", val);
    }

    Node * search(Node * x, int k)
    {
        if (x == NULL || k == x->val)
            return x;

        if (k < x->val)
            return search(x->left, k);
        else
            return search(x->right, k);
    }

    Node * insert(Node * r, int val, Node * p)
    {
        if (r == NULL)
        {
            Node * newnode = new Node(val);
            newnode->parent = p;
            return newnode;
        }
        else if (val < r->val)
        {
            r->left = insert(r->left, val, r);
        }
        else
            r->right = insert(r->right, val, r);
        return r;
    }

    void transplant(Node * u, Node * v)
    {
        if(u->parent == NULL)
            root = v;
        else if (u == u->parent->left)
            u->parent->left = v;
        else u->parent->right = v;
        if (v!= NULL)
            v->parent = u->parent;
    }

    void deleteByVal(int val)
    {
        Node * temp = search(root, val);
        if (temp == NULL)
            printf("Value not found");
        else
            deleteNode(temp);
    }

    void deleteNode(Node * z)
    {
        if (z->left == NULL)
            transplant(z, z->right);
        else if (z -> right == NULL)
            transplant(z, z->left);
        else
        {
            Node * y = findMin(z->right);
            if (y->parent != z)
            {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
        }
    }
};

int main()
{
//    BST b1;
//    //b1.inorder();
//    b1.insert(2);
//    b1.insert(8);
//    b1.insert(3);
//    b1.insert(10);
//    b1.insert(1);
//    b1.insert(6);
//    //b1.insert(3);
//    b1.inorder();
//
//    b1.search(10);
//    b1.search(1);
//    b1.deleteByVal(1);
//    b1.inorder();
    /*Node * a = b1.findMin(b1.root);
    printf("Min value is %d", a->val);*/
    BST b1;
	b1.insert(3);
	b1.insert(1);
	b1.insert(5);
	b1.insert(2);
	b1.inorder();
	b1.search(3);
	b1.deleteByVal(3);
	b1.inorder();
}
