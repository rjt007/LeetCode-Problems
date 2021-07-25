//https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) & S.C->O(N)
int maxDepth(string s)
{
    int length = 0, cnt = 0;
    int n = s.length();
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
            cnt++;
        }
        else if (s[i] == ')')
        {
            st.pop();
            cnt--;
        }
        length = max(cnt, length);
    }
    return length;
}
int main()
{
    string s="";
    cin>>s;
    int ans = maxDepth(s);
    cout<<"Result is: "<<ans<<endl;
}