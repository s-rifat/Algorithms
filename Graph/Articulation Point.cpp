#include<bits/stdc++.h>
using namespace std;

int const N = 10009;
vector<int> V[N];
int ap[N];
int color[N];
int d[N];
int L[N];
int p[N];
int k = 0;

void DFS(int u)
{
    color[u] = 1;
    d[u] = k;
    L[u] = k++;
    int child = 0;
    for(int i=0;i<V[u].size();i++)
    {
        int v = V[u][i];
        if(p[u]==v)
            continue;
        if(color[v]==0)
        {
            child++;
            p[v] = u;
            DFS(v);
            if(p[u]!=-1 && d[u]<=L[v])
                ap[u] = 1;
            L[u] = min(L[u],L[v]);
        }
        else
             L[u] = min(L[u],d[v]);
    }
    if(p[u]==-1 && child >1)
            ap[u] =1;
}

int main()
{
    int n,E;
    scanf("%d%d",&n,&E);
    for(int i=0;i<E;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        V[u].push_back(v);
        V[v].push_back(u);
    }
    p[1] = -1;
    DFS(1);
    int sum = 0;
    for(int i=1;i<=n;i++)
        sum+=ap[i];
    printf("%d\n",sum);
}

