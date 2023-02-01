#include<stdio.h>
#include<string.h>
#define Size 10
struct Element
{
    int val;
    int priority;
};
struct Student
{
    int marks;
    char name[15];
};
class Maxheap
{
protected:
    //int arr[Size] = {7,4,7,8,9,2,6,5,0,0};
    Student arr[Size];
public:
    Maxheap()
    {
        arr[0].marks = 0;
    }
    void max_heapify(int i)
    {
        int left = 2 * i;
        int right = 2 * i + 1;
        int largest;
        int N = arr[0].marks;
        if(left <= N && arr[left].marks > arr[i].marks)
        {
            largest = left;
        }
        else
        {
            largest = i;
        }
        if(right <= N && arr[right].marks > arr[largest].marks)
        {
            largest = right;
        }
        if(i != largest)
        {
            //swap(arr[i] , arr[largest]);
            Student temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            max_heapify(largest);
        }
    }
    void build_maxheap()
    {
        int N = arr[0].marks;
        for(int i = N/2;i>=1;i--)
        {
            max_heapify(i);
        }
    }
    void display()
    {
        int N = arr[0].marks;
        for(int i=1;i<=N;i++)
        {
            printf("%d %s\n",arr[i].marks,arr[i].name);
        }
        printf("\n");
    }
};
class Priority_Queue : public Maxheap
{
public:
    int top()
    {
        return arr[1].marks;
    }
    /*void push_(int val)
    {
        arr[0]++;
        int N = arr[0];
        arr[N] = -9999;
        increase_key(N,val);
    }*/
    void push(int m,char * p)
    {
        arr[0].marks++;
        int N = arr[0].marks;
        arr[N].marks = m;
        strcpy(arr[N].name,p);
        while(N>1 && arr[N/2].marks < arr[N].marks)
        {
            Student temp = arr[N];
            arr[N] = arr[N/2];
            arr[N/2] = temp;
            N = N/2;
        }
    }
    Student pop()
    {
        /*if(arr[0].marks == 0)
        {
            return "empty" ;
        }*/
        /*int max = arr[1].marks;
        char ret[15];
        strcpy(ret,arr[1].name);*/
        Student max = arr[1];
        arr[1] = arr[arr[0].marks];
        arr[0].marks--;
        max_heapify(1);
        return max;
    }
    /*void increase_key(int index,int val)
    {
        if(val < arr[index])
        {
            printf("The value is smaller than the index value!\n");
            return;
        }
        else
        {
            //int N = arr[0];
            arr[index] = val;
            while(index > 1 && arr[index/2] < arr[index])
            {
                int temp = arr[index];
                arr[index] = arr[index/2];
                arr[index/2] = temp;
                index = index/2;
            }
        }

    }*/
};
int main()
{
    /*Maxheap m1;
    m1.display();
    m1.build_maxheap();
    m1.display();*/
    Priority_Queue pq;
    /*pq.push(4);
    pq.push(7);
    pq.push(8);
    pq.push(9);
    pq.push(2);
    pq.push(6);
    pq.push(5);*/
    pq.push(100 , "Rushad");
    pq.push(98 , "Rezwan");
    pq.push(90 , "Medha");
    pq.push(100, "Putul");
    pq.display();
    for(int i=1;i<5;i++)
    {
        printf("%d. %s \n",i,pq.pop().name);
    }
    printf("\n");
}
