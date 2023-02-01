#include<bits/stdc++.h>
#define SIZE_OF_ALPHABET 26
using namespace std;
struct Node
{
    bool end_of_word;
    Node * parent;
    Node * Children[SIZE_OF_ALPHABET];
    Node()
    {
        end_of_word = false;
        parent = NULL;
        for(int i = 0;i<SIZE_OF_ALPHABET;i++)
        {
            Children[i] = NULL;
        }
    }
    bool isLeaf()
    {
        for(int i=0;i<SIZE_OF_ALPHABET;i++)
        {
            if(Children[i] != NULL)
            {
                return false;
            }
        }
        return true;
    }
};
class Trie
{
    Node * root;
public:
    Trie()
    {
        root = new Node;
    }
    void Insert(char * str)
    {
        int len = strlen(str);
        Node * temp = root;

        for(int i=0;i<len;i++)
        {
            int index = str[i] - 'a';

            if(temp->Children[index] == NULL)
            {
                temp->Children[index] = new Node;
                temp->Children[index]->parent = temp;
            }
            temp = temp->Children[index];
        }
        temp->end_of_word = true;
    }
    void display()
    {
        char a[20];
        display(root,a,0);
    }
    void display(Node * r,char * a,int level)
    {
        if(r->end_of_word == true)
        {
            a[level] = '\0';
            printf("%s\n",a);
        }
        if(r->isLeaf()==true)
        {
            return;
        }
        else
        {
            for(int i=0;i<SIZE_OF_ALPHABET;i++)
            {
                if(r->Children[i]!=NULL)
                {
                    a[level] = i + 'a';
                    display(r->Children[i],a,level+1);
                }
            }
        }
    }
    Node * searchWord(char * word)
    {
        Node * temp = root;
        int len = strlen(word);
        for(int i=0;i<len;i++)
        {
            int index = word[i] - 'a';
            if(temp->Children[index]!=NULL)
            {
                temp = temp->Children[index];
            }
            else
            {
                return NULL;
            }
        }
        if(temp->end_of_word==true)
        {
            return temp;
        }
        else
        {
            return NULL;
        }
    }

    void deleteWord(char * word)
    {
        Node * current = searchWord(word);
        if(current != NULL)
        {
            current->end_of_word = false;
        }
        bool isLeaf = current->isLeaf();

        while(current->parent!=NULL && isLeaf == true && current->end_of_word == false)
        {
            Node * p = current->parent;
            current = NULL;
            delete current;
            isLeaf = p->isLeaf();
            current = p;
        }
    }
};

int main()
{
    Trie t1;
    t1.Insert("and");
    t1.Insert("to");
    t1.Insert("end");
    t1.Insert("ander");

    t1.display();
    cout<<t1.searchWord("ander")->end_of_word<<endl;
    t1.deleteWord("and");
    t1.display();
}

