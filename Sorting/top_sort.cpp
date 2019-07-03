#include<bits/stdc++.h>

using namespace std;

vector <int> V[101];

int color[101];

stack<int> stk;


void DFS(int u)
{
    color[u] = 1;

    int v;

    for(int i=V[u].size()-1;i>=0;i--)
    {
        v = V[u][i];
        if(color[v]==0)
            DFS(v);

    }

    color[u] = 2;
    stk.push(u);
    //cout<<u<<" ";
}

void topologicalSort(int n)

{



    for(int i=n;i>=1;i--)
    {
        if(color[i]==0)
            DFS(i);
    }
}

int main()

{


    int n,E;

    cin>>n>>E;

    for( int i=0;i<E;i++)
    {
        int u,k;
        cin>>u>>k;





        for(int i=1;i<=k;i++)
        {

            int v;
            cin>>v;
            V[v].push_back(u);

        }

    }


      for(int i=1;i<=n;i++)
        {

            sort(V[i].begin(),V[i].end());

        }

    topologicalSort(n);


    while(!stk.empty())
    {
        if(stk.size()!=1)
        cout<<stk.top()<<" ";
        else
            cout<<stk.top()<<endl;

        stk.pop();
    }



    return 0;
}
