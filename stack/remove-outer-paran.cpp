//https://leetcode.com/problems/remove-outermost-parentheses/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) & S.C->O(N)
string removeOuterParentheses(string s)
{
    string ans = "";
    int openparan = 0; //count the open paranthesis.
    for (char c : s)
    {
        if (c == '(')
        {
            if(openparan>0)
            {
                ans += c;
            }
            openparan++;
        }
            
        if (c == ')')
        {
            if(openparan>1)
            {
                ans+=c;
            }
            openparan--;
        }
    }
    return ans;
}
int main()
{
    string s="";
    cin>>s;
    string ans = removeOuterParentheses(s);
    cout<<"Result is: "<<ans<<endl;
}