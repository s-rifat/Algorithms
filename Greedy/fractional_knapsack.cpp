#include<bits/stdc++.h>

using namespace std;

struct node {

    int item;
    double wt;
    double value;
    double Ratio;

};
double x[100];
vector<node> v;

bool compare(node a, node b)

{
    return a.Ratio > b.Ratio;
}

void fractional_knapsack(int n,double c)
{
    sort(v.begin(),v.end(),compare);

    int i;
    for( i=0;i<v.size();i++)

    {
       if(v[i].wt>c)
        break;
       x[i] = 1.0;
       c = c - v[i].wt;
    }
    if(i<=n)
        x[i] = c/v[i].wt;
}


int main()

{
    int n;
    double c;

    cin>>n>>c;

     for(int i=1;i<=n;i++)

    {
        double wt,value;
        cin>>wt>>value;

        node temp;

        temp.item = i;
        temp.wt = wt;
        temp.value= value;

        temp.Ratio = value/wt;
        v.push_back(temp);


    }

    fractional_knapsack(n,c);

    for(int i=0;i<n;i++)
    {
        cout<<x[i]<<endl;

    }

}


