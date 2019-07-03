#include<bits/stdc++.h>

using namespace std;

struct node{
    int s;
    int f;

};

bool compare(node a, node b)

{
    return a.f < b.f;
}

int main()

{

    int t;

    cin>>t;

    while(t--)

    {
        int n;

        cin>>n;

        node arr[n];

        for(int i=0;i<n;i++)

        {
            int a,b;
            cin>>a>>b;

            arr[i].s = a;
            arr[i].f = b;
        }

        sort(arr,arr+n,compare);
        int cnt = 1;
         for(int i=1,k =0;i<n;i++)
       {

           if(arr[i].s>= arr[k].f)
           {
             cnt++;
             k = i;
           }
       }
       cout<<cnt<<endl;


    }


    return 0;
}
