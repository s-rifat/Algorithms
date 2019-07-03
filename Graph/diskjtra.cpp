#include<bits/stdc++.h>

using namespace std;

const int N = 10001;
const int M = 50001;

struct node{

    int x;
    int y;
};



bool operator<(node a, node b)
{
   return a.y > b.y;
}

priority_queue< node> q;

void dijkstra(int s, int n, int parent[], int popped[], int value[],vector <node> V[])
{
     for(int i=1;i<=n;i++)
     {
         value[i] = INT_MAX;

         parent[i] = -1;
     }

    node p;

    value[s] = 0;

    p.x = s;

    p.y = value[s];

    q.push(p);

    while(!q.empty())
    {
        node u  =  q.top();

        q.pop();

        if(popped[u.x]==1)
            continue;

         popped[u.x] = 1;

        for(int i=0;i<V[u.x].size();i++)
        {
            node v;

            v = V[u.x][i];


            if(popped[v.x]==0 && (v.y+value[u.x])<value[v.x])
            {
                parent[v.x] = u.x;

                value[v.x] = v.y + value[u.x];

                v.y = value[v.x];

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



         int parent[N], popped[N],  value[N];

         for(int i=0;i<N;i++)
         {
             parent[i] = 0;
             popped[i] = 0;
             value[i] = 0;


         }



        int n,E,s,t,p;
        cin>>n>>E>>s>>t>>p;

        for( int i=0;i<E;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;

            node p;
            p.x = v;
            p.y = w;



            V[u].push_back(p);

        }


        dijkstra(s,n,parent,popped,value,V);

    }

    return 0;
}
