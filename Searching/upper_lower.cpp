#include<bits/stdc++.h>

using namespace std;

int main()

{

    int n;

    cin>>n;
    vector  <int> v;
    for(int i=0;i<n;i++)

    {

        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());

        int Q;
        cin>>Q;

        vector<int>:: iterator lo = lower_bound(v.begin(), v.end(), Q);
        vector<int>:: iterator hi = upper_bound(v.begin(), v.end(), Q);

        int low,high;

        low = lo - v.begin();//index of lower bound
        high = hi - v.begin(); //index of higher bound

        return 0;
}
