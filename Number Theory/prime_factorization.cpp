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

const int N =100000000;
int status[N/32];

int prime[N];

int p[N];
int e[N];

int nk = 0;

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

 void decomp(int n)

 {
    int sqrtn = sqrt(n);


    for(int i = 0; i<cnt && prime[i]<=sqrtn;i++)
    {

        int cnt2 = 0;
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
            {
                cnt2++;
                n = n/prime[i];
            }

            if(cnt2>0)
            {


                p[nk] = prime[i];
                e[nk] = cnt2;
                nk++;
            }


        }
        sqrtn = sqrt(n);
    }

     if(n!=1)
            {


                p[nk] = n;
                e[nk] = 1;

                nk++;
            }


 }

int main()

{


         nk = 0;

         cnt = 0;


         int n;
         cin>>n;

         int m = sqrt(n);

         sieve(m);
         decomp(n);

         cout<<n<<": ";
         int i,j;

         int cnt = 0;

         for( i=0;i<nk;i++)
         {

             for( j=0; j<e[i];j++)
             {



                  if(i==nk-1 && j==e[nk-1]-1)
                  cout<<p[i]<<endl;
                  else
                  cout<<p[i]<<" ";

                  cnt++;
             }


         }
         cout<<cnt<<endl;

    return 0;
}
