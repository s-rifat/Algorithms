
#include<bits/stdc++.h>
using namespace std;

int n;
vector <int> V[100],V2[100];
stack <int> stk;
int color[100],color2[100];
int cnt=0;
int crclno = 0;
int check = 0;

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
    stk.push(u);
}

void DFS2(int u)
{
    color2[u] = 1;
    int v;
    for(int i=0;i<V2[u].size();i++)
    {
        v = V2[u][i];
        if(color2[v]==0)
            DFS2(v);
    }
    color2[u] = 2;
    cout<<u<<" ";
    check++;
}

void topologicalSort()
{
    for(int i=1;i<=n;i++)
    {
        if(color[i]==0)
        {
            DFS(i);
        }
    }
}

void find_scc()
{
      topologicalSort();
      cout<<"Strongly Connected Components are:";
      while(!stk.empty())
      {
          int a = stk.top();
          stk.pop();
          check = 0;
          if(color2[a]==0)
          {
              cout<<endl;
              cnt++;
              DFS2(a);
          }
          if(check>1)
            crclno++;
      }
      cout<<endl;
}

int main()
{
    int E;
    cin>>n>>E;
    for( int i=0;i<E;i++)
    {
        int u,v;
        cin>>u>>v;
        if(v==u)
            crclno++;
        V[u].push_back(v);
        V2[v].push_back(u);
    }

    find_scc();
    cout<<"So the Number of SCC:"<<endl;
    cout<<cnt<<endl;

    cout<<"The number of cycle "<<crclno<<endl;
    return 0;
}
