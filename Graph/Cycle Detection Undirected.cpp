#include<bits/stdc++.h>
using namespace std;

const int N = 1001;

vector <int> V[N];
int father[N], color[N];
bool cycle = false;

void DFS(int u)
{
    color[u] = 1;
    for(int i=0;i<V[u].size();i++)
    {
        int v = V[u][i];
        if(color[v]==0)
        {
            father[v] = u;
            DFS(v);
        }
        else if(color[v]==1 && father[u]!=v)
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
            father[i] = -1;
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
            V[v].push_back(u);
        }

        //DFS
        for(int i=1;i<=n;i++)
            if(color[i]==0)
                DFS(i);
    }

    return 0;
}
