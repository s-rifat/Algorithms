#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll const N = 100000000;
ll status[N/32];
vector<ll> prime;


bool Check(ll N,ll pos)
{
    return (bool)(N & (1<<pos));
}
ll Set(ll N,ll pos)

{
    return N=N | (1<<pos);
}


void sieve(ll  N)
{
     ll i, j, sqrtN;
     sqrtN = ll( sqrt( N ) );
     for( i = 3; i <= sqrtN; i += 2 )
     {
		 if( Check(status[i/32],i%32)==0)
		 {
	 		 for( j = i*i; j <= N; j += 2*i )
			 {
				 status[j/32]=Set(status[j/32],j % 32);
	 		 }
		 }
	 }

     prime.push_back(2);
     for(i=3;i<=N;i+=2)
     {
		 if( Check(status[i/32],i%32)==0)
         {
	 	    prime.push_back(i);
         }
     }
}

ll phi(ll n)
{
    ll sqrtn = sqrt(n);
    ll ans = n;
    for(ll i = 0; i<prime.size() && prime[i]<=sqrtn;i++)
    {
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
                n = n/prime[i];
            ans = (ans/prime[i])*(prime[i]-1);
        }
        sqrtn = sqrt(n);
    }
    if(n!=1)
        ans = ans/n*(n-1);
    return ans;
}


int main()
{
      sieve(1000);
      while (true)
      {
         ll n;
         cin>>n;
         cout<<phi(n)<<endl;
      }
      return 0;
}
