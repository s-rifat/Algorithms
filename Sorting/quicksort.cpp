#include<bits/stdc++.h>

using namespace std;

int partision(int A[],int lo, int hi)

{
    int pivot = A[hi];

    int i = lo-1;

    for(int j = lo ; j<=hi-1;j++)
    {
        if(A[j]<pivot)
           {
               i++;
               swap(A[i],A[j]);
           }


    }
     swap(A[i+1],A[hi]);

    return (i+1);
}

void quickSort(int A[],int lo, int hi)
{
    if(lo<hi)
    {
        int p = partision(A,lo,hi);
        quickSort(A,lo,p-1);
        quickSort(A,p+1,hi);

    }
}

int main()

{

   int A[10] = {10,9,1,0,6,5,4,3,2,1};

   quickSort(A,0,9);

   for(int i=0;i<10;i++)
   {
       cout<<A[i]<<" ";
   }

   return 0;
}
