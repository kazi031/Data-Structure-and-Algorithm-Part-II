#include<stdio.h>
#define Size 10
using namespace std;
struct Element
{
    int val;
    int priority;
};
class Maxheap
{
protected:
    //int arr[Size] = {7,4,7,8,9,2,6,5,0,0};
    Element arr[Size];
public:
    Maxheap()
    {
        arr[0].val = 0;
    }
    void max_heapify(int i)
    {
        int left = 2 * i;
        int right = 2 * i + 1;
        int largest;
        if(left <= arr[0].val && arr[left].priority > arr[i].priority)
        {
            largest = left;
        }
        else
        {
            largest = i;
        }
        if(right <= arr[0].val && arr[right].priority > arr[largest].priority)
        {
            largest = right;
        }
        if(i != largest)
        {
            //swap(arr[i] , arr[largest]);
            Element temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            max_heapify(largest);
        }
    }
    void build_maxheap()
    {
        for(int i=arr[0].val/2;i>=1;i--)
        {
            max_heapify(i);
        }
    }
    void print_arr()
    {
        for(int i=1;i<=arr[0].val;i++)
        {
            printf("(%d %d)\n",arr[i].priority,arr[i].val);
        }
        printf("\n");
    }
};
class Priority_Queue : public Maxheap
{
public:
    int top()
    {
        return arr[1].val;
    }
   /* void heap_increase_key(int i,int val)
    {
        if(val < arr[i].val)
        {
            printf("The new key is smaller than the prev key!!\n");
            return;
        }
        else
        {
            arr[i].val = val;
            while(i>1 && arr[i/2] < arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[i/2];
                arr[i/2] = temp;
                i = i/2;
            }
        }
    }*/
    /*void push(int val)
    {
        arr[0]++;
        arr[arr[0]] = -9999;
        heap_increase_key(arr[0],val);

    }*/
    void push(int val,int p)
    {
        arr[0].val++;
        int N = arr[0].val;
        arr[N].val = val;
        arr[N].priority = p;
        while(N>1 && arr[N/2].priority < arr[N].priority)
        {
            Element temp = arr[N];
            arr[N] = arr[N/2];
            arr[N/2] = temp;
            N = N/2;
        }
    }
    int pop()
    {
        if(arr[0].val == 0)
        {
            return -1;
        }
        int max = arr[1].val;
        arr[1] = arr[arr[0].val];
        arr[0].val--;
        max_heapify(1);
        return max;
    }
};
int main()
{
    //Maxheap m1;
    //m1.print_arr();
    //m1.build_maxheap();
    //m1.print_arr();
    Priority_Queue pq;
    pq.push(203 , 1);
    pq.push(105 , 3);
    pq.push(100 , 2);
    pq.print_arr();
    for(int i=1;i<4;i++)
    {
        printf("%d\n",pq.pop());
    }

}
