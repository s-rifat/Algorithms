

#include<bits/stdc++.h>

using namespace std;

const int N = 10001;

struct node{

    int x;
    int y;
};

bool operator<(node a, node b)
{
   return a.y > b.y;
}

vector <node> V[N];

int parent[N];

int popped[N];

int value[N];

int sum= 0;

priority_queue< node> q;

void prims(int s,int n)
{
     for(int i=1;i<=n;i++)
        {
            value[i] = 100000;

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

         if(parent[u.x]!=-1)
         {
             cout<<parent[u.x]<<" "<<u.x<<" "<<u.y<<endl;

             sum = sum+u.y;
         }

        for(int i=0;i<V[u.x].size();i++)
        {
            node v;

            v = V[u.x][i];

            if(popped[v.x]==0 && v.y<value[v.x])
            {
                parent[v.x] = u.x;

                value[v.x] = v.y;

                q.push(v);
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
        int u,v,w;
        cin>>u>>v>>w;

        node p;
        p.x = v;
        p.y = w;

        V[u].push_back(p);

        p.x = u;
        V[v].push_back(p);
    }
    cout<<endl;

    prims(1,n);

    cout<<"\ntotal "<<sum<<endl;

    return 0;
}
