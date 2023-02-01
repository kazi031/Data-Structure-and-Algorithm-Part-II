#include <stdio.h>
#define SIZE_OF_ALPHABET 26
struct Node
{
    bool end_of_word;
    Node * children[SIZE_OF_ALPHABET];

    Node()
    {
        end_of_word = false;
        for (int i = 0; i<SIZE_OF_ALPHABET; i++)
            children[i] = NULL;
    }

    bool isLeaf()
    {
        for (int i = 0; i< SIZE_OF_ALPHABET; i++)
            if(children[i]!= NULL)
                return false;
        return true;
    }
};

class Trie
{
    Node * root;
public:+
    Trie()
    {
        root = new Node();
    }
    void insert(char * str)
    {
        int len = strlen(str);
        Node * temp = root;

        for (int i = 0; i<len; i++)
        {
            int index = str[i] - 'a';
            if (temp->children[index] == NULL)
                temp->children[index] = new Node();
            temp = temp->children[index];
        }

        temp->end_of_word = true;
    }



    void display(Node * root, char * arr, int level)
    {
        if (root->end_of_word == true)
        {
            arr[level] = '\0';
            printf("%s\n", arr);
        }
        if(root->isLeaf()) return;
        for (int i = 0; i<SIZE_OF_ALPHABET; i++)
            if(root->children[i]!= NULL)
            {
                arr[level] = 'a' + i;
                display(root->children[i], arr, level+1);
            }


    }
};

int main()
{

}
