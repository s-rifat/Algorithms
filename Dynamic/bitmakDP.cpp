#include<bits/stdc++.h>
using namespace std;

int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}

int n;
int dp[(1 << 15) + 2];

int f(int mask)
{
   if (mask == (1 << n) - 1)
        return 0;
   if(dp[mask]!=-1)
        return dp[mask];
}
int main()
{
    return 0;
}






