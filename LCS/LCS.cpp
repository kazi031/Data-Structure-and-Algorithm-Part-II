#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
using namespace std;

int b[50][50];
char c[50][50];
char s1[20];
char s2[20];
void LCS();
void Print_LCS(int,int);

int main(){

    cin>>s1;
    cin>>s2;
    LCS();
    Print_LCS(strlen(s1),strlen(s2));

}
void LCS(){
    for(int i=0;i<=strlen(s1);i++){
        b[i][0] = 0;
    }
    for(int i=0;i<=strlen(s2);i++){
        b[0][i] = 0;
    }
    for(int i=1;i<=strlen(s1);i++){
        for(int j=1;j<=strlen(s2);j++){
            if(s1[i-1]==s2[j-1]){
                c[i][j] = 'D';
                b[i][j] = b[i-1][j-1] + 1;
            }
            else if(b[i-1][j] >= b[i][j-1]){
                b[i][j] = b[i-1][j];
                c[i][j] = 'U';
            }
            else{
                b[i][j] = b[i][j-1];
                c[i][j] = 'L';
            }
        }
    }








    for(int i=0;i<=strlen(s1);i++){
        for(int j=0;j<=strlen(s2);j++){
            printf("%d%c\t",b[i][j],c[i][j]);
        }
        printf("\n");
    }

}



void Print_LCS(int i,int j){
    if(i==0 || j==0){
        return;
    }
    else if(c[i][j]=='D'){

        Print_LCS(i-1,j-1);
        printf("%c",s1[i-1]);
    }
    else if(c[i][j] == 'L'){
        Print_LCS(i,j-1);
    }
    else if(c[i][j] == 'U'){
        Print_LCS(i-1,j);
    }

}




