//////////////////////////////

#include<bits/stdc++.h>


using namespace std;

const int N = 1001;
vector <int> V[N];

int father[N];

int color[N];
int cnt = 0;

bool cycle = false;
void DFS(int u)
{
    color[u] = 1;

    int v;

    for(int i=0;i<V[u].size();i++)
    {
        v = V[u][i];
        if(color[v]==0)
        {
            father[v] = u;

            DFS(v);
        }
        else if(color[v]==1 && father[u]!=v)
        {


            cycle = true;
        }
    }

    color[u] = 2;


}
//////////////////////////////////////


int main()

{
    int n,E;
    cin>>n>>E;

      for(int i=0;i<E;i++)

           {
                int u,v,w;
                cin>>u>>v>>w;


                    V[u].push_back(v);
                    V[v].push_back(u);


           }
           DFS(1);
    return 0;
}
