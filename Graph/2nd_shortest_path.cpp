#include<bits/stdc++.h>

using namespace std;

const int N = 5001;

struct node{

    int degree;
    int x;
    int y;
};

bool operator<(node a, node b)
{
   return a.y > b.y;
}

priority_queue< node> q;

void dijkstra(int s, int n, int popped[][N], int value[][N], vector <node> V[])
{

    for(int i=0;i<2;i++)
    {
        for(int j=0;j<N;j++)
        {

            value[i][j] = INT_MAX;
        }
    }

    value[0][s] = 0;

    node p;

    p.degree = 0;

    p.x = s;

    p.y = value[0][s];

    q.push(p);

    while(!q.empty())
    {
        node u  =  q.top();

        q.pop();

        if(popped[u.degree][u.x]==1)
            continue;

        popped[u.degree][u.x] = 1;

        for(int i = 0;i<V[u.x].size();i++)
        {
            node v;

            v = V[u.x][i];

            int temp = v.y+value[u.degree][u.x];

            if(popped[v.degree][v.x]==0 && temp <value[0][v.x])
            {
                value[1][v.x] = value[0][v.x];
                v.y = value[1][v.x];
                v.degree = 1;
                q.push(v);

                value[0][v.x] = temp;
                v.y = value[0][v.x];
                v.degree = 0;
                q.push(v);

            }
            else if ( temp >value[0][v.x] && temp <value[1][v.x])
            {
                value[1][v.x] = temp;
                v.y = value[1][v.x];
                v.degree = 1;
                q.push(v);

            }
        }
    }
}

int main()
{


    int t;
    cin>>t;
    int cnt2 = 0;

    while(t--)
    {
         cnt2++;

         vector <node> V[N];

         int popped[2][N], value[2][N];

         for(int i=0;i<2;i++)
         {
             for(int j=0;j<N;j++)
             {
                 popped[i][j] = 0;
                 value[i][j] = 0;
             }
         }

        int n,E;
        cin>>n>>E;

        for( int i=0;i<E;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;

            node p;
            p.x = v;
            p.y = w;
            p.degree = 0;

            V[u].push_back(p);

            p.x = u;
            V[v].push_back(p);
        }

        dijkstra(1,n,popped,value,V);

        cout<<"Case "<<cnt2<<": "<<value[1][n]<<endl;

    }

    return 0;
}
