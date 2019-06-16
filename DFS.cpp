#include<bits/stdc++.h>

using namespace std;

vector <int> V[100];

int color[100];

void DFS(int u)
{
    color[u] = 1;

    int v;

    for(int i=0;i<V[u].size();i++)
    {
        v = V[u][i];
        if(color[v]==0)
            DFS(v);
    }

    color[u] = 2;
    cout<<u<<" ";
}

int main()

{
    int n,E;

    cin>>n>>E;

    for( int i=0;i<E;i++)
    {
        int u,v;

        cin>>u>>v;

        V[u].push_back(v);
        V[v].push_back(u);
    }

    int root;
    cin>>root;

    DFS(root);

    return 0;
}
