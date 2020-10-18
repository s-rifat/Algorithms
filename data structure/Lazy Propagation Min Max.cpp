#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int const N  = 100009;
ll  arr[N];
ll  tree[4*N];
ll  lazy[4*N];
void build(ll  pos,ll  left, ll  right)
{
    if(left==right)
    {
        tree[pos] = arr[left];
        lazy[pos] = 0;
        return;
    }
    ll  mid = (left+right)/2;
    build(2*pos,left,mid);
    build(2*pos+1,mid+1,right);
    tree[pos] = min(tree[2*pos],tree[2*pos+1]);///edit
    lazy[pos] = 0;
}
ll  query(ll  pos,ll  left, ll  right, ll  qleft, ll  qright)
{
    if(left>right || qleft>right || qright<left) //invalid and no overlap
    {
        return INT_MAX;///edit
    }
    if(lazy[pos]!=0) // making sure if propagation is done
    {
        tree[pos]+= lazy[pos];///edit
        if(left!=right)//not a leaf node
        {
            lazy[2*pos] += lazy[pos];
            lazy[2*pos+1] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    if(qleft<=left && qright>=right)// total overlap
    {
        return tree[pos];
    }
    //partial overlap
    ll  mid = (left+right)/2;
    return min(query(2*pos,left, mid, qleft,qright),query(2*pos+1,  mid+1, right,  qleft, qright));///edit
}

ll  point_query(ll  pos,ll  left, ll  right, ll  att)
{
    if(lazy[pos]!=0) // making sure if propagation is done
    {
        tree[pos]+= lazy[pos];///edit
        if(left!=right)//not a leaf node
        {
            lazy[2*pos] += lazy[pos];
            lazy[2*pos+1] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    if(left==right)
    {
       return tree[pos];
    }
    int mid = (left+right)/2;

    if(att<=mid)
        return point_query(2*pos,left,mid,att);
    else
        return point_query(2*pos+1,mid+1,right,att);
}

void update(ll  pos, ll  left, ll  right,ll  qleft, ll  qright, ll  val)
{
    if(lazy[pos]!=0) // making sure if propagation is done. this should be before no overlap condition
    {
        tree[pos]+= lazy[pos];///edit
        if(left!=right)//not a leaf node
        {
            lazy[2*pos] += lazy[pos];
            lazy[2*pos+1] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    if(left > right || qleft>right || qright<left ) //invalid and no overlap
    {
        return ;
    }
    if(qleft<=left && qright>=right)// total overlap
    {
        tree[pos]+=val;///edit
        if(left!=right) //not a leaf node
        {
            lazy[2*pos] += val;
            lazy[2*pos+1] += val;
        }
        return ;
    }
    //partial overlap
    ll  mid = (left+right)/2;
    update(2*pos,left,mid,qleft,qright,val);
    update(2*pos+1,mid+1,right,qleft,qright,val);
    tree[pos] = min(tree[2*pos],tree[2*pos+1]);///edit
}
int main()
{
    ll  n;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    build(1,1,n);

    ll  x,y,v;
    scanf("%lld%lld%lld",&x,&y,&v);
    update(1, 1, n,x, y, v);

    scanf("%lld%lld",&x,&y);
    printf("%lld\n",query(1,1,n, x, y));

    return 0;
}
