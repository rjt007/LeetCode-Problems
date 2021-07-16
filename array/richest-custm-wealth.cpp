//https://leetcode.com/problems/richest-customer-wealth/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) & S.C->O(1).
int maximumWealth(vector<vector<int>> &accounts)
{
    int n = accounts.size();
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < accounts[i].size(); j++)
        {
            sum += accounts[i][j];
        }
        mx = max(mx, sum);
    }
    return mx;
}
int main()
{
    int n,m;
    cin >> n>>m;
    vector<vector<int>> v;
    vector<int>v1;
    int val;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <m; j++)
        {
            cin >> val;
            v1.push_back(val);
        }
        v.push_back(v1);
    }
    int ans = maximumWealth(v);
    cout<<ans<<endl;
    return 0;
}