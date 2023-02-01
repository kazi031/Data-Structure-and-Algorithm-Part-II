#include<stdio.h>
using namespace std;
struct Node
{
    int val;
    Node * left;
    Node * right;
    Node * parent;
    Node(int v)
    {
        left = right = NULL;
        val = v;
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
    // rapper or delicate function
    void inorder()
    {
        if(root == NULL)
        {
            printf("Tree is empty!");
            return ;
        }
        inorder(root);
    }
    void inorder(Node * r)
    {
        if(r != NULL)
        {
            inorder(r->left);
            printf("%d ",r->val);
            inorder(r->right);
        }
    }

    void preorder()
    {
        if(root == NULL)
        {
            printf("Tree is empty!");
            return ;
        }
        preorder(root);
    }



    void preorder(Node * r)
    {
        if(r != NULL)
        {
            printf("%d ",r->val);
            inorder(r->left);
            inorder(r->right);
        }
    }

    void postorder()
    {
        if(root == NULL)
        {
            printf("Tree is empty!");
            return ;
        }
        postorder(root);
    }




    void postorder(Node * r)
    {
        if(r != NULL)
        {
            inorder(r->left);
            inorder(r->right);
            printf("%d ",r->val);
        }
    }

    /*void insert(int v)
    {
        Node * temp = new Node(v);
        root = insert(root , temp);
    }

    Node * insert(Node * root_,Node * temp)
    {
        //Node * temp = new Node(v);
        if(root_ == NULL)
        {
            root_ = temp;
            return root_;
        }
        else if(root_->val < temp->val)
        {
            root_->right = insert(root_->right , temp);
        }
        else if(root_->val < temp->val)
        {
            root_->left = insert(root_->left , temp);
        }

    }*/
    void insert(int val)
    {
        root = insert(root,val,NULL);
    }
    Node * insert(Node * r,int val,Node * p)
    {
        if(r == NULL)
        {
            Node * newnode = new Node(val);
            newnode->parent = p;
            return newnode;
        }
        if(r->val > val)
        {
            r->left = insert(r->left , val,r);
        }
        else if(r->val < val)
        {
            r->right = insert(r->right , val,r);
        }
        return r;
    }
    void iter_insert(int val)
    {
        Node * temp = NULL;
        Node * temp2 = root;
        while(temp2!= NULL)
        {
            temp = temp2;
            if(temp2->val > val)
            {
                temp2 = temp2->left;
            }
            else if(temp2->val < val)
            {
                temp2 = temp2->right;
            }
        }
         Node * temp3 = new Node(val);
        //temp2->parent = temp;

        if(temp == NULL)
        {
            root = temp3;
        }
        else if(temp->val < val)
        {
            temp->right = temp3;
        }
        else if(temp->val > val)
        {
            temp->left = temp3;
        }
    }
    int binary_search(int val)
    {
        Node * temp = binary_search(root,val);
        if(temp == NULL)
        {
            printf("\nNot Found!!");
        }
        else
        {
            int ret = temp->val;
            printf("%d was found in the tree!!",ret);
        }

    }
    Node * binary_search(Node * r,int val)
    {
        if(r == NULL || val == r->val)
        {
            return r;
        }
        if(val < r->val)
        {
           return binary_search(r->left,val);
        }
        else
        {
            return binary_search(r->right,val);
        }
    }
    Node * Find_min(Node * r)
    {
        while(r->left != NULL)
        {
            r = r->left;
        }
        return r;
    }
    void Transplant(Node * u,Node * v)
    {
        if(u->parent == NULL)
        {
            root = v;
        }
        else if(u == u->parent->left)
        {
            u->parent->left = v;
        }
        else if(u == u->parent->right)
        {
            u->parent->right = v;
        }
        if(v != NULL)
        {
            v->parent = u->parent;
        }
    }
    void deleteByval(int val)
    {
        Node * temp = binary_search(root,val);
        if(temp == NULL)
        {
            printf("val not found!!\n");
        }
        else
        {
            Tree_delete(temp);
        }
    }
    void Tree_delete(Node * r)
    {
        if(r->left == NULL)
        {
            Transplant(r,r->right);
        }
        else if(r->right == NULL)
        {
            Transplant(r,r->left);
        }
        else
        {
            Node * y = Find_min(r->right);
            if(y->parent !=r)
            {
                Transplant(y,y->right);
                y->right = r->right;
                y->right->parent = y;
            }
            Transplant()
        }
    }
};
int main()
{
    BST b1;
    b1.insert(8);
    b1.insert(3);
    b1.insert(10);
    b1.insert(11);
    b1.insert(2);
    b1.insert(14);
    b1.inorder();
    b1.binary_search(7);
    //printf("\n%d",b1.Find_min(b1.root)->val);
    //b1.postorder();
}
