#include<stdio.h>
#include<iostream>
#include<cstdlib>
using namespace std;
int SIZE;
struct Node
{
    int val;
    Node * next;
};
struct LinkedList
{
private:
    Node ** hashTable;
public:
    void init(int s)
    {
        SIZE = s;
        hashTable = (Node**)calloc(SIZE,sizeof(Node*));
    }
    int hash_function(int key)
    {
        int sq = key * key;
        int arr[10];
        int n = sq;
        int c = 0;
        while(n!=0)
        {
            arr[c] = n%10;
            n = n/10;
            c++;
        }
        if(c%2==0)
        {
            int hash_val = ((arr[c/2] + arr[c/2-1])/2) % 10;
            return hash_val;
        }
        else
        {
            int hash_val = arr[c/2] % 10;
            return hash_val;
        }
    }
    void insert_value(int v)
    {
        Node * temp = new Node;
        temp->val = v;
        temp->next = NULL;
        int HashVal = hash_function(v);

        if(hashTable[HashVal] == NULL)
        {
            hashTable[HashVal] = temp;
        }
        else
        {
            temp->next = hashTable[HashVal];
            hashTable[HashVal] = temp;
        }
    }
    int search_value(int v)
    {

        int HashVal = hash_function(v);
        Node * temp = hashTable[HashVal];

        if(temp->val == v)
        {

            return v;
        }
        else
        {
            while(temp!=NULL)
            {
                if(temp->val == v)
                {
                    return v;
                }
                temp = temp->next;
            }
            return -1;
        }
        //return hashTable[HashVal]->val;

    }
    void display()
    {
        for(int i=0;i<SIZE;i++)
        {
            printf("%d-->",i);
            Node * temp = hashTable[i];
            while(temp != NULL)
            {
                printf("%d-->",temp->val);
                temp = temp->next;
            }
            printf("\n");
        }
    }

};
int main()
{
    LinkedList l1;
    l1.init(10);
    l1.insert_value(22);
    l1.insert_value(32);
    l1.insert_value(42);
    l1.insert_value(52);
    l1.insert_value(27);
    l1.insert_value(10807);
    l1.display();
    cout<<l1.search_value(18);
}
