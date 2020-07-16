#include<bits/stdc++.h>
using namespace std;

int LIS(vector<int>& v)
{
    if (v.size() == 0)
        return 0;

    std::vector<int> tail(v.size(), 0);
    int length = 1;
    tail[0] = v[0];

    for (int i = 1; i < v.size(); i++)
    {
        auto b = tail.begin();
        auto e = tail.begin() + length;
        auto it = lower_bound(b, e, v[i]);

        if (it == tail.begin() + length)
            tail[length++] = v[i];  //if greatest of all so far adding in the last. case 2. geeks
        else
            *it = v[i];  // if smallest of all so far or in between, assigning to the appropriate place. case 1 & 3. geeks
    }

    return length;
}

int main()
{
    int n;
    cin>>n;
    vector<int> v;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<LIS(v)<<endl;
    return 0;
}
