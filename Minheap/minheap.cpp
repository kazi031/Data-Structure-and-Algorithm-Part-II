#include<stdio.h>
#define Size 10
using namespace std;
class Minheap
{
protected:
    //int arr[Size] = {7,4,7,8,9,2,6,5,0,0};
    int arr[Size] = {0};
public:
    void min_heapify(int i)
    {
        int left = 2 * i;
        int right = 2 * i + 1;
        int smallest;
        if(left <= arr[0] && arr[left] < arr[i])
        {
            smallest = left;
        }
        else
        {
            smallest = i;
        }
        if(right <= arr[0] && arr[right] < arr[smallest])
        {
            smallest = right;
        }
        if(i != smallest)
        {
            //swap(arr[i] , arr[largest]);
            int temp = arr[i];
            arr[i] = arr[smallest];
            arr[smallest] = temp;
            min_heapify(smallest);
        }
    }
    void build_minheap()
    {
        for(int i=arr[0]/2;i>=1;i--)
        {
            min_heapify(i);
        }
    }
    void print_arr()
    {
        for(int i=1;i<=arr[0];i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
};
class Priority_Queue : public Minheap
{
public:
    int top()
    {
        return arr[1];
    }
    void heap_increase_key(int i,int val)
    {
        if(val < arr[i])
        {
            printf("The new key is smaller than the prev key!!\n");
            return;
        }
        else
        {
            arr[i] = val;
            while(i>1 && arr[i/2] < arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[i/2];
                arr[i/2] = temp;
                i = i/2;
            }
        }
    }
    /*void push(int val)
    {
        arr[0]++;
        arr[arr[0]] = -9999;
        heap_increase_key(arr[0],val);

    }*/
    void push(int val)
    {
        arr[0]++;
        int N = arr[0];
        arr[N] = val;
        while(N>1 && arr[N/2] > arr[N])
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
        int min = arr[1];
        arr[1] = arr[arr[0]];
        arr[0]--;
        min_heapify(1);
        return min;
    }
};
int main()
{
    //Maxheap m1;
    //m1.print_arr();
    //m1.build_maxheap();
    //m1.print_arr();
    Priority_Queue pq;
    pq.push(4);
    pq.push(7);
    pq.push(8);
    pq.push(9);
    pq.push(2);
    pq.push(6);
    pq.push(5);
    pq.print_arr();
    for(int i=1;i<8;i++)
    {
        printf("%d\n",pq.pop());
    }

}
