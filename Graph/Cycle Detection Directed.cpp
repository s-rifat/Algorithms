
#include<bits/stdc++.h>
using namespace std;

int const N = 101;

vector<int> V[N];
int color[N];
bool cycle  = false;

void DFS(int u)
{
    color[u] = 1;
    for(int i=0;i<V[u].size();i++)
    {
        int v = V[u][i];
        if(color[v]==0)
            DFS(v);
        else if ( color[v]==1)
            cycle = true;
    }
    color[u] = 2;
}
int main()
{
    while(true)
    {
        //clear
        cycle = false;
        for(int i=0;i<N;i++)
        {
            color[i] = 0;
            V[i].clear();
        }

        //input
        int n,E;
        cin>>n>>E;
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            V[u].push_back(v);
        }

        //DFS
        for(int i=1;i<=n;i++)
            if(color[i]==0)
                DFS(i);
    }

    return 0;
}
