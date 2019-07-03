#include<bits/stdc++.h>

using namespace std;

vector <int> V[100];

int color[100];

queue <int > q;

void BFS(int s)
{
    color[s] = 1;
    q.push(s);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        cout<<u<<" ";

        int v;
        for(int i=0;i<V[u].size();i++)
        {
            v = V[u][i];
            if(color[v]==0)
            {
                q.push(v);
                color[v] = 1;
            }
        }
    }
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

    BFS(root);

    return 0;
}
