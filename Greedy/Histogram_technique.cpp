#include<bits/stdc++.h>

using namespace std;

int main()

{

    int t;

    cin>>t;

    int cnt2 = 0;
    while(t--)

    {
        cnt2++;
        int n;

        cin>>n;

        int arr[n];

        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }

        stack <int> s;

       int area;
       int Max = -1;
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

          cout<<"Case "<<cnt2<<": "<<Max<<endl;


    }

    return 0;
}

