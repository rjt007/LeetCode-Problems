//https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) & S.C->O(N)
string removeDuplicates(string s)
{
    stack<char> st;
    string ans = "";
    for (char c : s)
    {
        if (!st.empty() && st.top() == c)
        {
            st.pop();
            continue;
        }
        st.push(c);
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
    string ans = removeDuplicates(s);
    cout<<"Result is: "<<ans<<endl;
}