#include<bits/stdc++.h>

using namespace std;

int f(int arr[],int n)


{
       stack <int> s;


       int area;
       int Max = 0;
       int top;
       int i;
       for( i=0;i<n;)
        {


            if( s.empty() || arr[i]>=arr[s.top()] )
            {
                s.push(i);
                i++;
            }
            else
            {
                    top = s.top();
                    s.pop();

                    if(s.empty())

                        area = arr[top]*i;

                    else

                        area = arr[top]*(i-s.top()-1);

                    if(area>Max)
                            Max = area;
            }


        }



        while(!s.empty())
        {
                    top = s.top();
                    s.pop();

                    if(s.empty())

                        area = arr[top]*i;

                    else

                        area = arr[top]*(i-s.top()-1);
                    if(area>Max)
                        Max = area;
        }

        return Max;
}

int main()

{


    while(true)
    {
        int m,n;

        cin>>m>>n;
        if(m==0 && n==0)
            break;
        int arr[m][n];

        for(int i=0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                int x;
                cin>>x;

                if(x == 1)
                    x = 0;
                else
                    x = 1;
                arr[i][j] = x;
            }
        }

        int Max = 0;
        int arr2[n];
        for(int j=0;j<n;j++)
            arr2[j] = arr[0][j];
        int a = f(arr2,n);
           if(a>Max)
            Max = a;


        for(int i=1;i<m;i++)
        {

            for(int j=0;j<n;j++)
            {

                if(arr[i][j]==0)
                arr2[j] = arr[i][j];
                else
                arr2[j]++;
            }

           a = f(arr2,n);
           if(a>Max)
            Max = a;
        }

        cout<<Max<<endl;
    }


    return 0;
}
