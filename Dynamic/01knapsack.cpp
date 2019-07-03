#include<bits/stdc++.h>
using namespace std;

struct node
{
    int wt;
    int value;
};
int T[1001][1001];
    int result[1001];

int Max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int main()
{

    int cp;
    cin>>cp;

    int n;
    cin>>n;

    node arr[n+1];
    for(int i=1;i<=n;i++)
    {
        int wt,value;
        cin>>wt>>value;

        node temp;
        temp.wt= wt;
        temp.value = value;

        arr[i] = temp;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=cp;j++)
        {
            if(j < arr[i].wt)
                T[i][j] = T[i-1][j];
            else
            {
                int value = arr[i].value;
                int wt = arr[i].wt;
                T[i][j] = Max(value+T[i-1][j-wt],T[i-1][j]);
            }
        }
    }

   for(int i=n,j=cp;i>=1;i--)
   {
       if(T[i][j]>T[i-1][j])
       {
         result[i] = 1;
         j = j - arr[i].wt;
       }
   }

    for(int i=1;i<=n;i++)
        cout<<result[i]<<" ";

    return 0;
}

