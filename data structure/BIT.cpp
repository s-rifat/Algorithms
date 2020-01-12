#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mx 1000

ll tree[mx];

ll query(ll idx)
{
    ll sum = 0;
    while (idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(ll idx, ll val, ll n)
{
     while (idx <= n){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int main()
{
    ll n;
    cin>>n;
    ll arr[n+1];
    for(ll i = 1;i<=n;i++)
    {
       cin>>arr[i];
       update(i,arr[i],n);
    }

    ll idx;
    cin>>idx;
    cout<<query(idx)<<endl;

    ll val;
    cin>>idx>>val;
    update(idx,val,n);

    cin>>idx;
    cout<<query(idx)<<endl;

    return 0;
}
