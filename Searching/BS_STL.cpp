#include<bits/stdc++.h>

using namespace std;

int main()

{

        int n,k;

        cin>>n>>k;

        int arr[n];

        for(int i=0;i<n;i++)

        {

            cin>>arr[i];
        }

        sort(arr,arr+n);

        int cnt = 0;

        for(int i=0;i<n;i++)


        {
            if(arr[i]+k>arr[n-1])
                break;
            if (binary_search(arr+i, arr + n, arr[i]+k))
                cnt++;
        }
        cout<<cnt<<endl;

     return 0;

}
