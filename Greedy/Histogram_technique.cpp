#include<bits/stdc++.h>

using namespace std;
 int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        int ans = 0;
        for(int i=0;i<n;)
        {
            if(s.empty() || heights[i]>heights[s.top()])
            {
                s.push(i);
                i++;
            }
            else
            {
                int top = s.top();
                s.pop();
                if(s.empty())
                {
                   ans = max(ans,heights[top]*i);
                }
                else
                {
                    ans = max(ans,heights[top]*(i-s.top()-1));
                }
            }
        }
        while(!s.empty())
        {
                int top = s.top();
                s.pop();
                if(s.empty())
                {
                   ans = max(ans,heights[top]*n);
                }
                else
                {
                    ans = max(ans,heights[top]*(n-s.top()-1));
                }
        }
        return ans;
    }
int main()

{


    return 0;
}

