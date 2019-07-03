#include<bits/stdc++.h>

using namespace std;

void max_heapify(int arr[],int n,int i)

{
    int L,R;
    L = 2*i+1;
    R = 2*i+2;

    int largest = i;

    if(L<n && arr[L]>arr[largest])
        largest = L;
    if(R<n && arr[R] > arr[largest])
        largest = R;

    if(i!=largest)
    {
        swap(arr[i],arr[largest]);
        max_heapify(arr,n,largest);
    }

}

void build_max_heap(int arr[], int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        max_heapify(arr,n,i);
    }
}

void Heapsort(int arr[], int n)

{
    build_max_heap(arr,n);

    for(int i = n-1; i>=1;i--)
    {
        swap(arr[i],arr[0]);
        n = n-1;
        max_heapify(arr,n,0);
    }
}

int main()

{
    int arr[10] = {1,3,2,4,700,-5,6,-8,10,9};

    Heapsort(arr,10);

    for(int i=0;i<10;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}
