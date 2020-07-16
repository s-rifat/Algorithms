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

void sieve(long long  N)
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

long long SOD(long long n)

 {
    long long  sqrtn = sqrt(n);
    long long product = 1;


    for(int i = 0; i<cnt && prime[i]<=sqrtn;i++)
    {

        long long cnt2 = 0;
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
            {
                cnt2++;
                n = n/prime[i];
            }
            if(cnt>0)
            {
                long long temp=1;
                for(int j=0;j<=cnt2;j++)
                {
                    temp = temp*prime[i];
                }
                temp = (temp-1)/(prime[i]-1);

                product = product*temp;

            }

        }
        sqrtn = sqrt(n);

    }

     if(n!=1)
     {


            long long temp=1;
            for(int j=0;j<=1;j++)
            {
                temp = temp*n;
            }
            temp = (temp-1)/(n-1);
            product = product*temp;
     }

       return product;
 }

int main()

{
        sieve(100000);

        long long  n;
        cin>>n;

        cout<<SOD(n)<<endl;

       return 0;
}
