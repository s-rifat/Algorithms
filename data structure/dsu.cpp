#include<bits/stdc++.h>
using namespace std;
int const N = 30009;
int p[N];
int Find(int x)
{
    if(p[x]==x)
        return x;
    return p[x] = Find(p[x]);
}
void Union(int a, int b)
{
    p[Find(b)] = Find(a);
}
int main()
{
     int t;
     cin>>t;
     while(t--)
     {
         int n,E;
         cin>>n>>E;
         for(int i=1;i<=n;i++)
         {
             p[i] = i;
         }
         for(int i=0;i<E;i++)
         {
             int a,b;
             cin>>a>>b;
             Union(a,b);
         }
         for(int i=1;i<=n;i++)
         {
             Find(i);
         }
         set <int> s;
         for(int i=1;i<=n;i++)
         {
            s.insert(p[i]);
         }
         cout<<s.size()<<endl; // number of components
     }
    return 0;
}
