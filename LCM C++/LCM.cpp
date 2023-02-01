#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
    int c[10][10];
    char b[10][10];
    char x[10],y[10];
void print_lcs(int i,int j)
{
    if(i==0 || j==0)
       {
           return;
       }

       else if(b[i][j]=='D')
        {
            print_lcs(i-1,j-1);
            printf("%c",x[i-1]);
        }
        else if(b[i][j]=='U')
        {
            print_lcs(i-1,j);
        }
        else
        {
            print_lcs(i,j-1);
        }

}




int main()
{

    cout<<"Enter the string 1:";
    cin>>x;
    cout<<"Enter the string 2:";
    cin>>y;

    int m=strlen(x);
    int n=strlen(y);

    for(int i=0;i<=m;i++)
    {
        c[i][0]=0;
    }
    for(int j=0;j<=n;j++)
    {
        c[0][j]=0;
    }



    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(x[i-1]==y[j-1])
            {
                c[i][j]=1+c[i-1][j-1];
                b[i][j]='D';
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                b[i][j]='U';
            }
            else
            {
                c[i][j]=c[i][j-1];
                b[i][j]='l';
            }
        }
    }
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            printf("%d\t%c\t",c[i][j],b[i][j]);
        }
        cout<<"\n";
    }

 print_lcs(m,n);

}

