#include<stdio.h>
#include<string.h>
#include<cstdlib>
using namespace std;
int SIZE;
struct Item
{
    char name[10];
    int id;
    Item * next;
};
class Myexception
{
    char * ex;
public:
    Myexception(char * e)
    {
        ex = new char[strlen(e)+1];
        strcpy(ex,e);
    }
    Myexception(const Myexception &obj)
    {
        ex = new char[strlen(obj.ex)+1];
        strcpy(ex,obj.ex);
    }
    char * get_massage()
    {
        return ex;
    }
    ~Myexception()
    {
        delete [] ex;
    }
};
class LinkedList
{
    Item ** Hashtable;
public:
    LinkedList(int size)
    {
        SIZE = size;
        Hashtable = (Item**)calloc(SIZE,sizeof(Item*));
    }
    int Hash_func(char * key)
    {
        int val = 0;
        for(int i=0;i<strlen(key);i++)
        {
            val = val + key[i];
        }
        int HashVal = val % SIZE;
        return HashVal;
    }
    void Insert(char * n,int i)
    {
        Item * temp = new Item;
        strcpy(temp->name,n);
        temp->id = i;
        temp->next = NULL;
        int HashVal = Hash_func(n);
        if(Hashtable[HashVal]==NULL)
        {
            Hashtable[HashVal] = temp;
        }
        else
        {
            temp->next = Hashtable[HashVal];
            Hashtable[HashVal] = temp;
        }
    }
    void display()
    {
        for(int i=0;i<SIZE;i++)
        {
            Item * temp = Hashtable[i];
            printf("%d-->",i);
            while(temp!=NULL)
            {
                printf("%s %d",temp->name,temp->id);
                printf("-->");
                temp = temp->next;
            }
            printf("\n");
        }
    }
    int search_by_key(char * key)
    {
        int HashVal = Hash_func(key);
        Item * temp = Hashtable[HashVal];
        if(temp == NULL)
        {
            Myexception m1("Name not Found!!");
            throw m1;
        }
        else if(strcmp(temp->name,key)==0)
        {
            return temp->id;
        }
        else
        {
            while(temp!=NULL)
            {
                if(strcmp(temp->name,key)==0)
                {
                    return temp->id;
                }
                temp = temp->next;
            }
            Myexception m1("Name not Found!!");
            throw m1;
        }
    }
};
int main()
{
    LinkedList list1(10);
    list1.Insert("Kazi",201814022);
    list1.Insert("Putul",201814048);
    list1.Insert("Saba",201814053);
    list1.Insert("Shaqran",201814059);
    list1.Insert("Rushad",201814056);
    list1.Insert("Medha",201814054);
    list1.Insert("Shuvra",201814028);
    list1.Insert("Akash",201814036);
    list1.Insert("Fatima",201814017);
    list1.Insert("Ishraq",201814023);
    list1.display();
    try{
    printf("%d",list1.search_by_key("Reza"));
    }
    catch(Myexception &obj)
    {
        printf("%s",obj.get_massage());
    }
}
