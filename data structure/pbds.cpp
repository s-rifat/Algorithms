
#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void print(ordered_set& os)
{
    cout<<"printing values of os: "<<endl;
    for(auto a = os.begin();a!=os.end();a++)
    {
        cout<<*a<<" ";
    }
    cout<<endl;
}
void printReverse(ordered_set& os)
{
    cout<<"printing values of os in reverse: "<<endl;
    for(auto a = os.rbegin();a!=os.rend();a++)
    {
        cout<<*a<<" ";
    }
    cout<<endl;
}
int main()
{
    ordered_set os;

    cout<<"Inserted 1 to 11"<<endl;
    for(int i=1;i<=11;i++)
    {
        os.insert(i);
    }
    cout<<"Erased 11"<<endl;
    os.erase(11);

    print(os);

    cout<<"Current size of os "<<os.size()<<endl;

    cout<<"the smallest number is "<<*os.begin()<<endl;

    cout<<"the largest number is "<<*os.rbegin()<<endl;

    if(os.find(9)!=os.end())
        cout<<"9 is Found"<<endl;
    else
        cout<<"9 is not found"<<endl;

    cout<<"number of value less than 7 is  "<<os.order_of_key(7)<<endl;
    cout<<"number of value less than equal to 7 is  "<<os.order_of_key(7+1)<<endl;

    cout<<"number of value greater than 7 is  "<<os.size()-os.order_of_key(7+1)<<endl;
    cout<<"number of value greater than equal to 7 is  "<<os.size()-os.order_of_key(7)<<endl;

    cout<<"3rd smallest number is "<<*os.find_by_order(3-1)<<endl;
    cout<<"2nd largest number is "<<*os.find_by_order(os.size()-2)<<endl;

    cout<<"Deleting 3rd smallest element that is 3"<<endl;
    os.erase(os.find_by_order(3-1));
    print(os);

    cout<<"Deleting 4th largest element that is 7"<<endl;
    os.erase(os.find_by_order(os.size()-4));
    print(os);

    cout<<"Deleting smallest number "<<endl;
    os.erase(os.begin());
    print(os);

    cout<<"Deleting largest number "<<endl;
    os.erase(os.rbegin());
    print(os);
    printReverse(os);


    if(os.lower_bound(6)!=os.end())
        cout<<"lower bound of 6 is "<<*os.lower_bound(6)<<endl;
    if(os.upper_bound(6)!=os.end())
        cout<<"upper bound of 6 is "<<*os.upper_bound(6)<<endl;

    cout<<"Clearing os "<<endl;
    os.clear();

    if(os.empty())
        cout<<"Os is empty"<<endl;

    return 0;
}
