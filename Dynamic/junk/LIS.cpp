#include<bits/stdc++.h>

using namespace std;

void LIS(int arr[], int n)

{
    int arr2[n];
    for(int i=0;i<n;i++)
        arr2[i] = 1;

    for(int i=1;i<n;i++)
    {
        for( int j=0;j<i;j++)
        {
            if(arr[j]<arr[i])
                arr2[i] = max(arr2[i],arr2[j]+1);
        }
    }

    for(int i=0;i<n;i++)
    cout<<arr2[i]<<" ";

}

int main()

{



    int arr[] = {3,4,-1,0,6,2,3};

    LIS(arr,7);



    return 0;
}
