#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int const N = 100001;
int const k = 17;

ll st[k][N];
ll arr[N];

void Sparse(ll n)
{
    ll row = floor(log2(n)) + 1;
    for(ll i=0; i<n; i++)
        st[0][i]=i;
    for(ll i=1; i<row; i++)
    {
        ll lim=n-(1<<i)+1;
        for(ll j=0; j<lim; j++)
        {
             ll x = st[i-1][j];
             ll y = st[i-1][j+(1<<i-1)];
             ///st[i][j] = arr[x]>arr[y]?x:y;       ///For Range Maximum Query
             st[i][j] = arr[x]<arr[y]?x:y;       ///For Range Minimum Query
        }
    }
}

void RMQ(ll in1,ll in2)
{
    ll n = log2(in2-in1);
    ll x = st[n][in1];
    ll y = st[n][in2-(1<<n)+1];
    ///printf("%d\n",arr[arr[x]>arr[y]?x:y]);   ///For Maximum Query
    printf("%d\n",arr[arr[x]<arr[y]?x:y]);      ///For Minimum Query
    ///return arr[arr[x]>arr[y]?x:y];
}

int main(void)
{

    ll n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    Sparse(n);
    int q;
    cin>>q;
    while(q--)
    {
        ll in1,in2;
        scanf("%lld %lld",&in1,&in2);
        RMQ(min(in1,in2),max(in1,in2));
    }
    return 0;
}
