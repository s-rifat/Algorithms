#include<bits/stdc++.h>
using namespace std;

int arr[50][50];
char c[50];

int Max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int main()

{
    string s,s2;

    cin>>s>>s2;

    s = "0"+s;
    s2 = "0"+s2;

    for(int i=1;i< s.length();i++)
    {
        for(int j=1;j<s2.length();j++)
        {
            if(s[i]==s2[j])
                arr[i][j] = arr[i-1][j-1]+1;
            else
                arr[i][j] = Max(arr[i-1][j],arr[i][j-1]);
        }
    }

    int i = s.length()-1;
    int j = s2.length()-1;

    string S;
    int k = 49;
    while(i>=1 && j>=1)
    {
        if(s[i]==s2[j])
        {

            c[k--] = s[i];
            i--;
            j--;
        }
        else if(arr[i-1][j]>=arr[i][j-1])
            i--;
        else
            j--;

    }

    for(int i=k;i<50;i++)
        cout<<c[i];

    return 0;
}


