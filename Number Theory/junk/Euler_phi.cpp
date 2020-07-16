#include<bits/stdc++.h>

using namespace std;

bool Check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
int Set(int N,int pos)

{
    return N=N | (1<<pos);
}

int const N = 100000000;
int status[N/32];

int prime[N];


int cnt = 0;

void sieve(int N)
{
     int i, j, sqrtN;
     sqrtN = int( sqrt( N ) );
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


	 prime[cnt++] = 2;
	 for(i=3;i<=N;i+=2)
     {

		 if( Check(status[i/32],i%32)==0)
         {


	 	    prime[cnt++] = i;

         }
     }

}

bool isPrime(int a)

{
    if(a<2)
        return false;
    if(a==2)
        return true;
    if(a%2==0)
        return false;
    if(Check(status[a/32],a%32)==0)
        return true;
    return false;
}

int phi(int n)

 {

     int sqrtn = sqrt(n);

     int ans = n;

    for(int i = 0; i<cnt && prime[i]<=sqrtn;i++)
    {


        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
            {

                n = n/prime[i];
            }

        ans = (ans/prime[i])*(prime[i]-1);
        }
        sqrtn = sqrt(n);


    }

     if(n!=1)
            {
                  ans = ans/n*(n-1);

            }


       return ans;

 }

int main()

{



      sieve(1000);
      int t;

      cin>>t;



      while (t--)
      {

         int n;
         cin>>n;


        cout<<phi(n)<<endl;

      }



    return 0;
}
