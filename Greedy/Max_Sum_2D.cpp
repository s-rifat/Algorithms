#include<bits/stdc++.h>

using namespace std;

int f(int arr[],int n)

{
        int c = arr[0],g = arr[0];

        for(int i=1;i<n;i++)
        {
            c = max(arr[i],arr[i]+c);

            if(c>g)
                g = c;

        }

        return g;

}

int main()

{


   int n;

   while(scanf("%d",&n)!=EOF)
   {




       int arr[n][n];
       for(int i=0;i<n; i++)
       {
            for(int j=0;j<n;j++)
            {
                cin>>arr[i][j];
            }
       }



       int Max = arr[0][0];
       for(int L=0;L<n;L++)
       {
            int temp[n];
            for(int i=0;i<n;i++)
                temp[i] = 0;



            for(int R=L;R<n;R++)
            {


               for(int i=0;i<n;i++)
               {
                   temp[i]= temp[i] + arr[i][R];
               }

               int sum = f(temp,n);


               if(sum>Max)
                 Max = sum;
            }


       }

       cout<<Max<<endl;
   }

    return 0;
}
