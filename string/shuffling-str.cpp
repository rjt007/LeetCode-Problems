//https://leetcode.com/problems/shuffle-string/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) & S.C->O(N).
string restoreString(string s, vector<int> &indices)
{
    int n = indices.size();
    string ans(n, '0');
    for (int i = 0; i < n; i++)
    {
        ans[indices[i]] = s[i];
    }
    return ans;
}
int main()
{
    string s="";
    cout<<"Enter string: ";
    cin>>s;
    vector<int>v;
    int val;
    for(int i=0;i<s.length();i++)
    {
        cin>>val;
        v.push_back(val);
    }
    string ans= restoreString(s,v);
    cout<<"Result is: "<<ans<<endl;
}
