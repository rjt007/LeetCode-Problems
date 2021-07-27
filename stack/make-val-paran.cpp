//https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) & S.C->O(1), without stack
int minAddToMakeValid(string s)
{
    int ans = 0, bal = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            bal++;
        }
        else
        {
            bal--;
        }
        if (bal == -1)
        {
            ans++;
            bal++;
        }
    }
    return ans + bal;
}
/*
//T.C->O(N) & S.C->O(N), using stack
int minAddToMakeValid(string s)
{
    int n = s.size();
    stack<char> st;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else
        {
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
    }
    return st.size();
}
*/
int main()
{
    string s="";
    cin>>s;
    int ans=minAddToMakeValid(s);
    cout<<"Result is: "<<ans<<endl;
    return 0;
}