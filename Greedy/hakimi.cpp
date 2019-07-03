#include<bits/stdc++.h>

using namespace std;

bool compare(int a, int b)
{
    return a>b;
}

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
            {
                cin>>arr[i];
            }

            bool b = true;
            for(int i=0;i<n;i++)
            {

                sort(arr,arr+n,compare);

                if( arr[i]> n-i-1)
                {
                    b = false;
                    break;
                }

                 for(int j=i+1,x=0;x<arr[i];j++,x++)
                 {

                    arr[j]--;
                    if(arr[j]<0)
                    {
                        b = false;
                        break;
                    }
                }

                if(b==false)
                    break;
            }

            if(b)

                cout<<"Possible"<<endl;

            else
                cout<<"Not possible"<<endl;

        }


    return 0;
}
