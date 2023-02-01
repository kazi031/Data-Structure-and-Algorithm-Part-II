#include <iostream>
using namespace std;

const int ALPHABET_SIZE = 26;

// trie node
struct Node
{
	Node *children[ALPHABET_SIZE];
	int isEndOfWord;
};


int main()
{

/*	string s;

    int n;
	struct Node *root = getNode();
	cout<<"How many words you want to insert?"<<endl;
	cin>>n;
	cout<<"Enter "<<n<<" words"<<endl;
	while(n!=0)
    {
        cin>>s;
        insert(root,s);
        n--;
    }
///--------------------search-------------

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

///---------------------print------------

    char arr[100];
    cout<<"Pre order print: " <<endl;
    preOrderprint(root,arr,0);

///---------------delete--------------------
    deleteWord(root,"abc");

///--------------print---------------
    cout<<"after deletion"<<endl;

    preOrderprint(root,arr,0);

*/

	return 0;
}

