#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;


int n , m;
int pi[50];

void ComputePrefix(char*);




void ComputePrefix(char * p){
    m = strlen(p);
    pi[0] = 0;
    int k = 0;
    for(int q=1 ; q<m ; q++){
        while(k>0 && p[k]!=p[q]){
            k = pi[k-1];
        }
        if(p[k] == p[q]){
            k = k + 1;
        }
        pi[q] = k;
    }
}

void KMP_Matcher(char* t,char* p)
{
    n =strlen(t);
    ComputePrefix(p);
    int q=0;
    for(int i=0;i<n;i++)
    {
        while(q>0 && p[q]!=t[i])
            q=pi[q-1];
        if(p[q]==t[i])
            q++;
        if(q==m)
        {
            cout<<"Pattern occurs with shift "<<i-m+1<<endl;
            q=pi[q-1];
        }
    }
}








int main(){

    char s1[20],s2[20];
    gets(s1);
    gets(s2);
    KMP_Matcher(s1,s2);
}

