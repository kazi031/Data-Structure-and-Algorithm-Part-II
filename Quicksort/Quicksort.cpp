#include<iostream>
#include<stdio.h>
using namespace std;
//int A[] = {40,20,15,45,25,5,10,55};
int A[] = {8,7,6,5,1,3,2,10};

int count = 0;


void swap(int a , int b){
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;

}

int Find_pivot(int p,int r){
    int max = A[p];
    int min = A[r];
    for(int i=p;i<=r;i++){
        if(A[i]<min){
            min = A[i];
        }
        else if(A[i]>max){
            max = A[i];
        }
    }
    int median = (min+max)/2;
    int head = A[p];
    int index = p;
    for(int i=p;i<=r;i++){
        if(A[i] == median){
            return i;
        }
        else if(A[i]>head && A[i]<median){
            head = A[i];
            index = i;
        }
    }
    return index;

//printf("%d %d ",min,max);

}

int Partition(int p,int r){


    int x = A[r];

    int i = p - 1;

    for(int j=p ; j<=(r-1) ; j++){
        if(A[j]<=x){
            i++;
            swap(i,j);
            count++;
        }
    }
    swap(i+1,r);
    printf("pivot : %d\n",i+1);
    return i+1;
}



void QuickSort(int p,int r){
    if(p<r){
        int q = Partition(p,r);
        QuickSort(p,q-1);
        QuickSort(q+1,r);
    }
}


int main(){
    QuickSort(0,7);
    for(int i=0;i<=7;i++){
        printf("%d ",A[i]);
    }
    //printf("%d ",Find_pivot(4,7));
    printf("\n%d",count);
}
