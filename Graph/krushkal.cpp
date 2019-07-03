

#include<bits/stdc++.h>

using namespace std;

const int N = 101;

int parent[N];

int sum = 0;

int j = 0;


vector < pair <int , pair<int,int> > > Vec;

int find_parent(int r)

{
    if(parent[r]==r)
        return r;

    return parent[r] = find_parent( parent[r]);
        //return find_parent( parent[r] );

}

void Union(int U, int V, int W)
{

   int x = find_parent(U);
   int y = find_parent(V);
   if(x!=y)
   {

    parent[y] = x;
    sum = sum+W;
    j++;

  //  cout<<U<<" "<<V<<" "<<W<<endl;
   }


}

int main()

{


       int n,E;

       cin>>n>>E;

       for(int i=0;i<E;i++)

       {
            int u,v,w;
            cin>>u>>v>>w;
            Vec.push_back(make_pair( w,make_pair(u,v) ) );
       }


         sort(Vec.begin(),Vec.end() );


      for(int i=0;i<N;i++)
      {
          parent[i] = i;
      }

     // cout<<endl;

      for(int i=0; i<Vec.size();i++)
      {
          int W,U,V;
          W = Vec[i].first;
          U = Vec[i].second.first;
          V = Vec[i].second.second;


          Union(U,V,W);


          if(j==n-1)
          break;

      }

      cout<<"\nsum = "<<sum<<endl;


    return 0;
}

