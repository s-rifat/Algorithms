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

void sieve()
{
     int i, j, sqrtN;
     sqrtN = int( sqrt( N ) );
     for( i = 3; i <= sqrtN; i += 2 )
     {
		 if( Check(status[i/32],i%32)==0)
		 {
	 		 for( j = i*i; j <= N; j += 2*i )
			 {
				 status[j/32]=Set(status[j/32],j % 32)   ;
	 		 }
		 }
     }
   /*puts("2");
     for(i=3;i<=N;i+=2)
     {
		 if( Check(status[i/32],i%32)==0)
         {
	 	    printf("%d\n",i);
         }
     }*/
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
int main()
{
    sieve();

    int a = 99998953; // largest prime less than 10^8 is 99998953
    cout<<isPrime(a)<<endl;

    return 0;

}
