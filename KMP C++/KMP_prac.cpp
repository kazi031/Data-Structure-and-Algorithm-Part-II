#include<bits/stdc++.h>
using namespace std;
int pi[20];
char string1[20];
char string2[20];
int n,m;

void prefixGenerator(char * t){
    m = strlen(t);
    int k = 0;
    pi[0] = 0;
    for(int i=1;i<m;i++){
        while(k>0 && t[k] != t[i]){
            k = pi[k-1];
        }
        if(t[k] == t[i]){
            k++;
        }
        pi[i] = k;
    }

}

void KMP(char * string1,char * pattern){
    int n = strlen(string1);
    prefixGenerator(pattern);

    int k = 0;
    for(int i=0;i<n;i++){
        while(k>0 && pattern[k] != string1[i]){
            k = pi[k-1];
        }
        if(pattern[k] == string1[i]){
            k++;
        }
        if(k==m){
            printf("Left shift : %d\n",i-m+1);
            k = pi[k-1];
        }
    }



}




int main(){
    printf("Please enter a String : ");
    gets(string1);
    printf("please enter a pattern : ");
    gets(string2);
    //prefixGenerator(string1);
    /*for(int i=0;i<m;i++){
        printf("%d ",pi[i]);
    }*/
    KMP(string1,string2);
}
