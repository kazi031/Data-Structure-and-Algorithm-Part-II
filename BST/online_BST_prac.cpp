#include<bits/stdc++.h>
using namespace std;
map <int ,string> p;
int hashFunc(char * key)
{
    int hashVal = 0;
    for(int i=0;i<strlen(key);i++)
    {
        hashVal = hashVal + key[i];
    }
    return hashVal;
}
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
    Node * root;
public:
    BST()
    {
        root = NULL;
    }
    void insert(char * p)
    {
        int v = hashFunc(p);
        root = recursive_insert(root,v,NULL);
    }
    Node * recursive_insert(Node * r,int v,Node * p)
    {
        if(r == NULL)
        {
            Node * temp = new Node(v);
            temp->parent = p;
            return temp;
        }
        else if(r->val > v)
        {
            r->left = recursive_insert(r->left,v,r);

        }
        else if(r->val < v)
        {
            r->right = recursive_insert(r->right,v,r);
        }
        return r;
    }
    void inOrder()
    {
        inOrder(root);
        printf("\n");
    }
    void searchName(char * p)
    {
        int hashVal = hashFunc(p);
        Node * temp = searchName(root, hashVal);
        if(temp == NULL)
        {
            cout << "The Tree is Empty !!" << endl;
        }
        else
        {
            cout << temp->val <<" found in BST" << endl;
        }

    }
    Node * searchName(Node * r,int v)
    {
        if(r == NULL || r->val == v)
        {
            return r;
        }
        else if(r->val > v)
        {
            return searchName(r->left,v);
        }
        else
        {
            return searchName(r->right,v);
        }
    }
    void inOrder(Node * r)
    {
        if(r != NULL)
        {
            inOrder(r->left);
            //printf("%d ",r->val);
            cout << p[r->val]<<" ";
            inOrder(r->right);
        }
    }
    void transplant(Node * u, Node * v)
    {
        if(u->parent == NULL)
        {
            root = v;
        }
        else if(u == u->parent->left)
        {
            u->parent->left = v;
        }
        else
            u->parent->right = v;
        if(v != NULL)
        {
            v->parent = u->parent;
        }
    }
    void deleteByName(char * key)
    {
        int hashVal = hashFunc(key);
        Node * temp = searchName(root,hashVal);
        if(temp == NULL)
        {
            cout << "Name wasn't found in BST "<< endl;
        }
        else
        {
            deleteNode(temp);
        }
    }
    Node * findMin(Node * r)
    {
        while(r->left != NULL)
        {
            r = r->left;
        }
        return r;
    }
    void deleteNode(Node * z)
    {
        if(z->left == NULL)
        {
            transplant(z, z->right);
        }
        else if(z->right == NULL)
        {
            transplant(z, z->left);
        }
        else
        {
           Node * y = findMin(z->right);
           if(y->parent != z)
           {
               transplant(y,y->right);
               y->right = z->right;
               y->right->parent = y;
           }
           transplant(z,y);
           y->left = z->left;
           y->left->parent = y;
        }
    }
};

int main()
{

    cout<< hashFunc("putul")<<endl;
    cout<< hashFunc("kazi")<<endl;
    cout<< hashFunc("shaqran")<<endl;
    p[hashFunc("putul")] = "putul";
    p[hashFunc("kazi")] = "kazi";
    p[hashFunc("shaqran")] = "shaqran";
    cout<<p[hashFunc("shaqran")]<<endl;
    BST b1;
    b1.insert("putul");
    b1.insert("kazi");
    b1.insert("shaqran");
    b1.inOrder();

    b1.searchName("putul");

    b1.deleteByName("shaqran");

    b1.inOrder();
}
