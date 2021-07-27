//https://leetcode.com/problems/backspace-string-compare/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) & S.C->O(1)
bool backspaceCompare(string s, string t)
{
    int i = 0;
    while (i < s.length())
    {
        if (s[i] == '#' && i == 0)
        {
            s.erase(i, 1);
        }
        else if (s[i] == '#' && i > 0)
        {
            s.erase(i - 1, 2);
            i--;
        }
        else
        {
            i++;
        }
    }
    int j = 0;
    while (j < t.length())
    {
        if (t[j] == '#' && j == 0)
        {
            t.erase(j, 1);
        }
        else if (t[j] == '#' && j > 0)
        {
            t.erase(j - 1, 2);
            j--;
        }
        else
        {
            j++;
        }
    }
    if (s == t)
    {
        return true;
    }
    return false;
}
int main()
{
    string s="",t="";
    cin>>s>>t;
    bool ans = backspaceCompare(s,t);
    cout<<"Result is: "<<ans<<endl;
}
