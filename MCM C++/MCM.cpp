#include<iostream>
#include<cstdio>
using namespace std;

void Matrix_Chain_Order(int *p)
{
 //   int n = sizeof(p)/sizeof(p[0]);
    int n = 4;
    int m[n][n];
    int j;
    //int s[n-1][]
    for (int i=0;i<n ;i++ )
    {
        for (int j=0;j<n ;j++ )
            m[i][j] = 0;
    }
    for (int l=2;l<=n ;l++ )
    {
        for (int i=1;i<n-l+1 ;i++ )
        {
            j = i+l-1;
            m[i][j] = 9999;
            for (int k=i;k<=j-1 ;k++ )
            {
                cout << "hello"<<endl;
                int q = m[i][k]+m[k+1][j]+((p[i-1])*(p[k])*(p[j]));
                //cout << q<<endl;
                if(q<m[i][j])
                {
                    m[i][j] = q;
                    //m[j][i] = k;
                }
            }
        }
    }
    //cout << "e";
    for (int i=0;i<n ;i++ )
    {
        for (int j=0;j<n ;j++ )
            cout << m[i][j]<<" ";
        cout << endl;

    }
}

int main()
{
    int p[]={5,4,6,2,7};
    int A1[5][4];
    int A2[4][6];
    int A3[6][2];
    int A4[2][7];
    int a = 4;
    for (int i=0; i<5 ; i++ )
    {
        for (int j=0; j<4 ; j++ ){}
            //cin >> A1[i][j];
    }
    for (int i=0; i<4 ; i++ )
    {
        for (int j=0; j<6 ; j++ ){}
            //cin >> A2[i][j];
    }
    for (int i=0; i<6 ; i++ )
    {
        for (int j=0; j<2 ; j++ ){}
            //cin >> A3[i][j];
    }
    for (int i=0; i<2 ; i++ )
    {
        for (int j=0; j<7 ; j++ ){}
            //cin >> A4[i][j];
    }
    Matrix_Chain_Order(p);
}
