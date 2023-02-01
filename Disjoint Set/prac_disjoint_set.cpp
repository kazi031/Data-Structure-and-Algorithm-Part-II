#include<bits/stdc++.h>
#define SIZE 10
using namespace std;
class Disjointset
{
    int parent[SIZE];
    int rank1[SIZE];
public:
    Disjointset()
    {
        for(int i=0;i<SIZE;i++)
        {
            parent[i] = i;
            rank1[i] = 0;
        }
    }
    int findSet(int x)
    {
        if(x == parent[x])
        {
            return x;
        }
        else
        {
            return findSet(parent[x]);
        }
    }
    void unionSet(int v,int u)
    {
        int Uroot = findSet(u);
        int Vroot = findSet(v);
        parent[Vroot] = Uroot;
        rank1[Uroot]++;
    }
    void display()
    {
        for(int i=0;i<SIZE;i++)
        {
            printf("%d ",rank1[i]);
        }
        printf("\n");
    }
};
int main()
{
    Disjointset d1;
    d1.unionSet(1,2);

    d1.unionSet(4,2);
    d1.unionSet(3,5);
    d1.unionSet(2,3);
    d1.display();
}
