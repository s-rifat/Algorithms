#include<bits/stdc++.h>

using namespace std;

int left(int i)

{
    return 2*i+1;
}

int right(int i)

{
    return 2*i+2;
}

void max_heapify(int arr[],int i,int heap_size)

{
    int l,r,large;

    l = left(i);
    r = right(i);

    if(l<heap_size && arr[l]>arr[i])
    {
        large = l;
    }
    else
    {
        large = i;
    }
    if(r<heap_size && arr[r]>arr[large])
    {
        large = r;
    }
    if(large!=i)
    {
        swap(arr[i],arr[large]);
        max_heapify(arr,large,heap_size);
    }

}

void build_max_heap(int arr[],int length,int heap_size)

{

    heap_size = length;

    for(int i = floor((length/2-1));i>=0;i--)
    {
        max_heapify(arr,i,heap_size);
    }

}

void heapsort(int arr[],int length, int heap_size)

{
    build_max_heap(arr,length,heap_size);

    for(int i = length-1; i>=1;i--)
    {
        swap(arr[0],arr[i]);
        heap_size = heap_size-1;
        max_heapify(arr,0,heap_size);
    }
}

int main()
{
    int arr[] = {-5,100,2,-10,5,5};
    heapsort( arr,6, 6);

    for(int i=0;i<6;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
