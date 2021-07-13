//https://leetcode.com/problems/replace-all-digits-with-characters/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) & S.C->O(1).
string replaceDigits(string s)
{
    int n = s.size();
    int i = 1;
    while (i < n)
    {
        int dig = s[i - 1] + (s[i] - '0');
        char c = dig;
        s[i] = c;
        i += 2;
    }
    return s;
}
int main()
{
    string s="";
    cin>>s;
    string ans = replaceDigits(s);
    cout<<"Result is: "<<ans<<endl;
    return 0;
}
