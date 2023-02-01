#include<stdio.h>
#define SIZE 5
using namespace std;
class Disjointset
{
    int parent[SIZE];
    int rank[SIZE];
public:
    Disjointset()
    {
        for(int i=0;i<SIZE;i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int find_set(int x)
    {
        if(parent[x] != x)
        {
            return find_set(parent[x]);
        }
        else
        {
            return x;
        }
    }
    void unionSet(int u,int v)
    {
        int uRoot = find_set(u);
        int vRoot = find_set(v);
        if(uRoot == vRoot)
        {
            return ;
        }
        if(rank[uRoot] > rank[vRoot])
        {
            parent[vRoot] = uRoot;
        }
        else if(rank[uRoot] < rank[vRoot])
        {
            parent[uRoot] = vRoot;
        }
        else
        {
            parent[vRoot] = uRoot;
            rank[uRoot]++;
        }
//        parent[vRoot] = uRoot;
//        rank[parent[vRoot]]++;
    }
    void display()
    {
//        for(int i=0;i<SIZE;i++)
//        {
//            printf("%d\t",parent[i]);
//        }
//        printf("\n");
//        for(int i=0;i<SIZE;i++)
//        {
//            printf("%d\t",i);
//        }
        for(int i=0;i<SIZE;i++)
        {
            printf("%d ",rank[i]);
        }
        printf("\n");
    }
};
int main()
{
    Disjointset d1;
    d1.unionSet(1,2);
    d1.unionSet(0,2);
    d1.unionSet(2,3);
    d1.unionSet(3,4);
    d1.display();
}
