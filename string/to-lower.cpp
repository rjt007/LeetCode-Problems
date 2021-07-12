//https://leetcode.com/problems/to-lower-case/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) & S.C->O(1).
string toLowerCase(string s)
{
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] += 32;
        }
    }
    return s;
}
int main()
{
    string s="";
    cout<<"Enter string: ";
    cin>>s;
    string ans= toLowerCase(s);
    cout<<"Result is: "<<ans<<endl;
}
