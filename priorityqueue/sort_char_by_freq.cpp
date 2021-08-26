//https://leetcode.com/problems/sort-characters-by-frequency/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(n*log(n)) && S.C->O(N)
string frequencySort(string s)
{
    unordered_map<char, int> m;
    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
        m[s[i]]++;
    }
    priority_queue<pair<int, char>> pq;
    for (auto x : m)
    {
        pq.push(make_pair(x.second, x.first));
    }
    while (!pq.empty())
    {
        string temp(pq.top().first, pq.top().second);
        ans += temp;
        pq.pop();
    }
    return ans;
}
int main()
{
    string s;
    cin>>s;
    string ans = frequencySort(s);
    cout<<"Result is: "<<ans<<endl;
    return 0;
}