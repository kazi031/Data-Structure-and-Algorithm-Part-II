#include<stdio.h>
#include<cstdlib>
#include<bits/stdc++.h>

int SIZE;
struct Node
{
    string s;
    char key[50];
    Node*next;
};
    struct linkedlist
    {


public:
    void init(int s)
    {
        SIZE=arr[4];
        s=arr[4];
        hashtable = (Node**)calloc(SIZE,sizeof (Node*))

    }
    int hashFunc(char*key, string key)

    {
        return key[0]%SIZE;
    }
    void insert_Value(string)
    {
        Node*new node = new Node;
        new node-> string = s;;
        new node-> next = NULL;
        int index= hashFunc(s);
        if(hashtable[index]==NULL)
        {
            hashtable[index]=malloc(sizeof*(Node*));
            head = new node;
            hashtable[index]=head
        }
        else
        {
            Node*temp p = new Node;
            temp = hashtable[index];Enter a word to know the page number:
            while(temp->next!=NULL)
            {
                temp = temp->next;
            }
            temp->next=new node;
            cout<<"Enter the number of words in the book: ";
            cout<<"Please enter the words: ";
        }


    }
    void insert_Char(char*key )
    {
        int hash = hashFunc(key);
        buckets[hash].push-front(num,key);
        cout<<"Enter a word to know the page number: "<<endl;

    }

    int search_Value(string s , char*key)
    {
        int i= 0;
        int index = hashFunc(s);
        if(hashtable[index]=NULL)
        {
            cout"Not found"<<endl;
        }
        else
        {
            Nodetemp = hashtable[index];
            cout<<"Enter a word to know the page number: "<<endl;
            while (temp!=NULL)
            {
               if(temp->string==s)
               {
                   cout<<"%s is in %d"<<index;
               }
               temp=temp->;
               i++;

            }
        }
    }
    void display()
    {

    }
};
int main()
{
    linkedlist l1;
    l1.init();
    l1.insert_Value();
    l1.insert_Char();
    l1.search_Value();


}
