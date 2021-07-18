#include <bits/stdc++.h>
using namespace std;
//T.C->O(1) & S.C->O(N)
int numIdenticalPairs(vector<int> &nums)
{
    unordered_map<int, int> m;
    int n = nums.size(), ans = 0;
    for (int i = 0; i < n; i++)
    {
        m[nums[i]]++;
    }
    for (auto x : m)
    {
        ans += ((x.second) * (x.second - 1)) / 2;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>v;
    int val;
    for (int i = 0; i < n; i++)
    {
        cin>>val;
        v.push_back(val);
    }
    int ans = numIdenticalPairs(v);
    cout<<"Result is: "<<ans<<endl;
    return 0;
}