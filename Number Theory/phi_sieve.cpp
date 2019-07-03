#include<bits/stdc++.h>

using namespace std;

int phi[100000];

void phiSieve(int n)

{
    for(int i=1; i<=n;i++)
        phi[i] = i;

    for(int i=2; i<=n; i++ )
    {
        if(phi[i]==i)
        {
            phi[i] = i-1;
            for(int j= 2*i;j<=n;j+=i)
            {
                phi[j] = (phi[j]/i)*(i-1);
            }
        }
    }
}


int main()


{
    int n = 10;
    phiSieve(n);
   for(int i=1;i<=n;i++)
   {
       cout<<i<<" "<<phi[i]<<endl;
   }

}
