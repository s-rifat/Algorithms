#include<bits/stdc++.h>

using namespace std;

int main()

{
    while(true)
    {

        int n;
        cin>>n;

        if(n==0)
            break;

        int arr[n];

        for(int i=0;i<n;i++)
            cin>>arr[i];

        int c = arr[0],g = arr[0];

        for(int i=1;i<n;i++)
        {
            c = max(arr[i],arr[i]+c);

            if(c>g)
                g = c;

        }
        if(g>0)
        cout<<"The maximum winning streak is "<<g<<"."<<endl;

        else
            cout<<"Losing streak."<<endl;

    }


    return 0;
}
