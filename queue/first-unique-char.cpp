//https://leetcode.com/problems/first-unique-character-in-a-string/
#include <bits/stdc++.h>
using namespace std;
//O(N) & O(1), as only 26 char to store
int firstUniqChar(string s)
{
    unordered_map<char, int> m;
    int n = s.length(), ans = -1;
    for (int i = 0; i < n; i++)
    {
        m[s[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (m[s[i]] == 1)
        {
            ans = i;
            break;
        }
    }
    return ans;
}
int main()
{
    string s="";
    cin>>s;
    int ans = firstUniqChar(s);
    cout<<"Result is: "<<ans<<endl;
    return 0;
}