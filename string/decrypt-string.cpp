//https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) && S.C->O(1)
string freqAlphabets(string s)
{
    string ans = "";
    for (int i = 0; i < s.length();)
    {
        if (i + 2 < s.length() && s[i + 2] == '#')
        {
            int it = (s[i] - '0') * 10 + (s[i + 1] - '0');
            ans.push_back(char(it + 'a' - 1));
            i += 3;
        }
        else
        {
            ans.push_back(char(s[i] - '0' - 1 + 'a'));
            i++;
        }
    }
    return ans;
}
int main()
{
    string s="";
    cin>>s;
    string ans = freqAlphabets(s);
    cout<<"Result is: "<<ans<<endl;
}