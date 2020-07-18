#include<bits/stdc++.h>
using namespace std;

int const N = 101;
vector <int> V[N],ans;
int color[N];

void DFS(int u)
{
    color[u] = 1;
    for(int i=V[u].size()-1;i>=0;i--)
    {
        int v = V[u][i];
        if(color[v]==0)
            DFS(v);
    }
    ans.push_back(u);
}

void topologicalSort(int n)
{
    ans.clear();
    for(int i=n-1;i>=0;i--)
    {
        if(color[i]==0)
            DFS(i);
    }
    reverse(ans.begin(),ans.end());
}

int main()

{
    while(true)
    {
        //clear
        for(int i=0;i<N;i++)
        {
            V[i].clear();
            color[i] = 0;
        }

        //input
        int n,E;
        cin>>n>>E;
        for( int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            V[u].push_back(v);
        }

        //sort //optional // for printing lexicographically smallest
        for(int i=0;i<n;i++)
        {
            sort(V[i].begin(),V[i].end());
        }
        //top sort
        topologicalSort(n);
        //output
        for(int i=0;i<n;i++)
        {
            cout<<ans[i]<<" ";
        }
    }
    return 0;
}


