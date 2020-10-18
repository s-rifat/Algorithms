#include <bits/stdc++.h>
using namespace std;
int isPrime[1000009];
vector<int> prime;
void sieve(int n)
{
    isPrime[2] = 1;
    for(int i=3;i<=n;i+=2)
        isPrime[i] = 1;
    for (int p=3; p*p<=n; p+=2)
    {
        if (isPrime[p] == 1)
        {
            for (int i=p*p; i<=n; i += 2*p)
                isPrime[i] = 0;
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(isPrime[i])
            prime.push_back(i);
    }
}
int main()
{
    sieve(30);
    for(int i=0;i<prime.size();i++)
        cout<<prime[i]<<" ";
    return 0;
}


