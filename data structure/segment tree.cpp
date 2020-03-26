#include<bits/stdc++.h>
using namespace std;
int const N  = 100;
int arr[N];
int tree[4*N];
void build(int pos,int left, int right)
{
    if(left==right)
    {
        tree[pos] = arr[left];
        return;
    }
    int mid = (left+right)/2;
    build(2*pos,left,mid);
    build(2*pos+1,mid+1,right);
    tree[pos] = min(tree[2*pos],tree[2*pos+1]);
}
int query(int pos,int left, int right, int qleft, int qright)
{
    if(qleft<=left && qright>=right)
    {
        return tree[pos];
    }
    if(qleft> right || qright < left)
    {
        return INT_MAX;
    }
    int mid = (left+right)/2;
    return min(query(2*pos,left, mid, qleft,qright),query(2*pos+1,  mid+1, right,  qleft, qright));
}
void pupdate(int pos, int left, int right,int att, int val)
{
    if(left==right)
    {
        tree[pos] = val;
        return ;
    }
    int mid = (left+right)/2;

    if(att<=mid)
        pupdate(2*pos,left,mid,att,val);
    else
        pupdate(2*pos+1,mid+1,right,att,val);
    tree[pos]  = min(tree[2*pos],tree[2*pos+1]);
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
       cin>>arr[i];
    }
    build(1,1,n);
    int att , val;
    cin>>att>>val;
    pupdate(1,1,n,att,val);
    int x,y;
    cin>>x>>y;
    cout<<query(1,1,n,x,y)<<endl;
    return 0;
}


