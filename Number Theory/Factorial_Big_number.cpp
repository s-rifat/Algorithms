#include<bits/stdc++.h>
using namespace std;

#define Max 10000
int Size;

void  multiply(int x,int fact[])
{
    int carry = 0;
    int i;

    for( i=0;i<Size;i++)
    {
        int temp = fact[i]*x+carry;

        fact[i] = temp%10;
        carry = temp/10;
    }

    while(carry)
    {
        fact[i] = carry%10;
        carry = carry/10;
        i++;
    }
    Size = i;
}
void factorial(int n)
{
    int fact[Max];
    Size = 1;
    fact[0] = 1;
    for(int i=2;i<=n;i++)
    {
        multiply(i,fact);
    }

    for(int i=Size-1;i>=0;i--)
        cout<<fact[i];
    cout<<endl;
}

int main()

{
    factorial(5);
    factorial(6);
    factorial(50);
    return 0;
}
