#include<bits/stdc++.h>
using namespace std;

vector<int> odd_pal(string s)
{
    int n = s.length();
    vector<int> d1(n);
    for (int i = 0, l = 0, r = -1; i < n; i++)
    {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k])
        {
            k++;
        }
        d1[i] = k--;
        if (i + k > r)
        {
            l = i - k;
            r = i + k;
        }
    }
    return d1;
}

vector<int> even_pal(string s)
{
    int n = s.length();
    vector<int> d2(n);
    for (int i = 0, l = 0, r = -1; i < n; i++)
    {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k])
        {
            k++;
        }
        d2[i] = k--;
        if (i + k > r)
        {
            l = i - k - 1;
            r = i + k ;
        }
    }
    return d2;
}

int main()
{
    string s;
    cin>>s;
    vector<int> d1,d2;

    d1 = odd_pal(s);
    d2 = even_pal(s);

    for(int i=0;i<s.size();i++) //length = 2*d[i]-1
    {
        cout<<i<<" "<<d1[i]<<endl;
    }

    cout<<endl;

    for(int i=0;i<s.size();i++) //length = 2*d[i]
    {
        cout<<i<<" "<<d2[i]<<endl;
    }

    return 0;
}
