#include<bits/stdc++.h>

using namespace std;

struct node{
    int s;
    int t;
};

bool compare(node a, node b)

{
    return a.s < b.s;
}
bool operator<(node a, node b)
{
    return a.t>b.t;
}
int main()

{
    int t;

    cin>>t;

    int cnt2 = 0;

    while(t--)
    {
        cnt2++;
        int n;
        cin>>n;
        node arr[n];

        for(int i=0;i<n;i++)
        {
            int a,b;
            cin>>a>>b;

            arr[i].s =a;
            arr[i].t = b;
        }

        sort(arr,arr+n,compare);

        priority_queue<node> q;

        q.push(arr[0]);

        int h=1;

        for(int i=1; i<n;i++)
        {
            if(arr[i].s>q.top().t)
            {
                q.pop();
                q.push(arr[i]);
            }
            else
            {
                   q.push(arr[i]);
                   h++;

            }
        }

        cout<<"Case "<<cnt2<<": "<<h<<endl;


    }


    return 0;
}
