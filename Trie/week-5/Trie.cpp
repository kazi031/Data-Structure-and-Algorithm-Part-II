#include<stdio.h>
#include<iostream>
#define SIZE_OF_ALPHABET 26
using namespace std;
struct Node{
    bool e_o_w;
    Node * parent;
    Node * children[SIZE_OF_ALPHABET];
    Node(){
        e_o_w = false;
        for(int i=0;i<SIZE_OF_ALPHABET;i++)
        {
            children[i] = NULL;
            parent = NULL;
        }
    }
};
Node * getNode(){
    Node * newnode = new Node();
    return newnode;
}
Node* searchWord_(Node * current,string word)
{
    for(int i=0;i<word.length();i++)
    {
        int index = word[i] - 'a';
        if(current->children[index]==NULL)
        {
            return NULL;
        }
        current = current->children[index];
    }
    return current;
}
void deleteWord(Node * root,string word)
{
    Node * current = searchWord_(root,word);
    if(current!=NULL)
    {
        current->e_o_w = false;
        bool isLeaf = true;
        for(int i=0;i<SIZE_OF_ALPHABET;i++)
        {
            if(current->children[i]!=NULL)
            {
                isLeaf = false;
                break;
            }
        }
        while(current->parent!=NULL && isLeaf==true && current->e_o_w==0)
        {
            Node * p = current->parent;
            current = NULL;
            delete current;
            for(int i=0;i<SIZE_OF_ALPHABET;i++)
            {
                if(p->children[i]!=NULL)
                {
                    isLeaf = false;
                    break;
                }
            }
            current = p;
        }
    }
}
void InsertWord(Node * current,string word)
{
    for(int i=0;i<word.length();i++)
    {
        int index = word[i] - 'a';
        if(current->children[index]==NULL)
        {
            current->children[index] = getNode();
            current->children[index]->parent = current;
        }
        current = current->children[index];
    }
    current->e_o_w = true;
}
bool searchWord(Node * current,string word)
{
    for(int i=0;i<word.length();i++)
    {
        int index = word[i] - 'a';
        if(current->children[index]==NULL)
        {
            return false;
        }
        current = current->children[index];
    }
    return true;
}
void preOrderprint(Node * current,char word [],int arrsize)
{

    if(current->e_o_w == true)
    {
        for(int i=0;i<arrsize;i++)
        {
            cout<<word[i];
        }
        cout<<endl;
    }
    for(int i=0;i<SIZE_OF_ALPHABET;i++)
    {
        if(current->children[i]!=NULL)
        {
            word[arrsize] = i + 'a';
            arrsize++;
            preOrderprint(current->children[i],word,arrsize);
            arrsize--;
        }
    }
}
int main()
{
    string s;

    int n;
	struct Node *root = getNode();
	cout<<"How many words you want to insert?"<<endl;
	cin>>n;
	cout<<"Enter "<<n<<" words"<<endl;
	while(n!=0)
    {
        cin>>s;
        InsertWord(root,s);
        n--;
    }
    //Search//

    cout<<"enter a string that you want to search"<<endl;
    cin>>s;
    if(searchWord(root,s)==true)
    {

      cout<<"found"<<endl;
    }
    else
    {
        cout<<"not found"<<endl;
    }

    //Search//
    char arr[100];
    cout<<"Pre order print: " <<endl;
    preOrderprint(root,arr,0);


    deleteWord(root,"abc");

    cout<<"after deletion"<<endl;

    preOrderprint(root,arr,0);
}
