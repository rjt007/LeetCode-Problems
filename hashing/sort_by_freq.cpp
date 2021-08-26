//https://leetcode.com/problems/sort-characters-by-frequency/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) && S.C->O(N)
string frequencySort(string s)
{
    unordered_map<char, int> m;
    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
        m[s[i]]++;
    }
    map<int, string> mp;
    for (auto x : m)
    {
        mp[x.second] += string(x.second, x.first);
    }
    for (auto it = mp.rbegin(); it != mp.rend(); it++)
    {
        ans += it->second;
    }
    return ans;
}
int main()
{
    string s;
    cin >> s;
    string ans = frequencySort(s);
    cout << "Result is: " << ans << endl;
    return 0;
}
