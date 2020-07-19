
#include<bits/stdc++.h>
using namespace std;

void print_LIS(vector<int>& f,int *arr,int n)
{
       int require = f[0];
       vector<int> T;

       for (int i=n; i>=1; i--)
       {
           if (f[i]==require)
           {
              T.push_back(arr[i]);
              require--;
           }
       }
       int i=T.size();
       while (i--)
            printf("%d ", T[i]);
       printf("\n");
}

/*vector<int>*/int LIS (int *arr, int n)
{
    vector<int>f(n+1);
    int b[n+1];
    int answer = 0;
    for (int i=1; i<=n; i++)
    {
          f[i]=lower_bound(b+1,b+answer+1,arr[i])- b;
          answer = max(answer, f[i]);
          b[f[i]]=arr[i];
    }
    return answer;
    /*f[0] = answer;//index zero contains the length of LIS
    print_LIS(f,arr,n);
    return f; // it can also return the only answer*/
}

int main()
{
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    cout<<LIS(arr,n)<<endl;

   /* vector <int> f;
    f = LIS(arr,n);

    cout<<f[0]<<endl;
    for(int i=1;i<=n;i++)
    {
       cout<<f[i]<<" ";
    }
    cout<<endl;*/
    return 0;
}
