#include<stdio.h>
#define Size 10
class Maxheap
{
protected:
    //int arr[Size] = {7,4,7,8,9,2,6,5,0,0};
    int arr[Size] = {0};
public:
    void max_heapify(int i)
    {
        int left = 2 * i;
        int right = 2 * i + 1;
        int largest;
        int N = arr[0];
        if(left <= N && arr[left] > arr[i])
        {
            largest = left;
        }
        else
        {
            largest = i;
        }
        if(right <= N && arr[right] > arr[largest])
        {
            largest = right;
        }
        if(i != largest)
        {
            //swap(arr[i] , arr[largest]);
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            max_heapify(largest);
        }
    }
    void build_maxheap()
    {
        int N = arr[0];
        for(int i = N/2;i>=1;i--)
        {
            max_heapify(i);
        }
    }
    void display()
    {
        int N = arr[0];
        for(int i=1;i<=N;i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
};
class Priority_Queue : public Maxheap
{
public:
    int top()
    {
        return arr[arr[1]];
    }
    /*void push_(int val)
    {
        arr[0]++;
        int N = arr[0];
        arr[N] = -9999;
        increase_key(N,val);
    }*/
    void push(int val)
    {
        arr[0]++;
        int N = arr[0];
        arr[N] = val;
        while(N>1 && arr[N/2] < arr[N])
        {
            int temp = arr[N];
            arr[N] = arr[N/2];
            arr[N/2] = temp;
            N = N/2;
        }
    }
    int pop()
    {
        if(arr[0] == 0)
        {
            return -1;
        }
        int max = arr[1];
        arr[1] = arr[arr[0]];
        arr[0]--;
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
    pq.push(4);
    pq.push(7);
    pq.push(8);
    pq.push(9);
    pq.push(2);
    pq.push(6);
    pq.push(5);
    pq.display();
    for(int i=1;i<8;i++)
    {
        printf("%d ",pq.pop());
    }
    printf("\n");
}
