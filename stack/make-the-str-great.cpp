//https://leetcode.com/problems/make-the-string-great/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) & S.C->O(N)
string makeGood(string s)
{
    stack<char> st;
    int n = s.size();
    st.push(s[0]);
    string ans = "";
    for (int i = 1; i < n; i++)
    {
        if (!st.empty() && (s[i] == char(st.top() + 32) || s[i] == char(st.top() - 32)))
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());

    return ans;
}
int main()
{
    string s="";
    cin>>s;
    string ans = makeGood(s);
    cout<<"Result is: "<<ans<<endl;
}