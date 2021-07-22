//https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N*log(N)), S.C->O(1)
vector<int> minSubsequence(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size(), sum = 0, ans = 0;
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }
    int j = n - 1;
    while (j >= 0)
    {
        ans += nums[j];
        res.push_back(nums[j]);
        if (ans > (sum - ans))
        {
            break;
        }
        j--;
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    int val;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        v.push_back(val);
    }
    vector<int> ans = minSubsequence(v);
    cout<<"Result is:\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}