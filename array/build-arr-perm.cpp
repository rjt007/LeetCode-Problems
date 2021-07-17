//https://leetcode.com/problems/build-array-from-permutation/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) & S.C->O(1)
vector<int> buildArray(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        ans.push_back(nums[nums[i]]);
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>v,ans;
    int val;
    for (int i = 0; i < n; i++)
    {
        cin>>val;
        v.push_back(val);
    }
    ans = buildArray(v);
    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}