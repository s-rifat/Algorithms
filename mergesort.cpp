#include<bits/stdc++.h>

using namespace std;

void Merge(int A[],int lo,int mid,int hi)

{
    int n1 = mid -lo +1;
    int n2 = hi - mid;

    int L[n1+1],R[n2+1];

    for(int i=0;i<n1;i++)
    {
       L[i] = A[lo+i];
    }

    for(int i=0;i<n2;i++)

    {
        R[i] = A[mid+1+i];
    }

    L[n1] = 100000;
    R[n2] = 100000;
    int i = 0, j = 0;

    for(int k=lo;k<=hi;k++)
    {
        if(L[i]<R[j])
        {
            A[k] = L[i];
            i++;
        }

        else
        {
            A[k] = R[j];
            j++;
        }
    }
}

void Mergesort(int A[],int lo, int hi)
{
   if(lo<hi)
   {
       int mid = (lo+hi)/2;
       Mergesort(A,lo,mid);
       Mergesort(A,mid+1,hi);
       Merge(A,lo,mid,hi);
   }
}
int main()

{
   int A[10] = {1,3,2,5,4,9,8,7,6,10};

   Mergesort(A,0,9);

   for(int i=0;i<10;i++)
   {
       cout<<A[i]<<" ";
   }

    return 0;
}
