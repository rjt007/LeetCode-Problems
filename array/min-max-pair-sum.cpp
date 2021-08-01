//https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N*log(N)) & S.C->O(1)
int minPairSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int i = 0, j = n - 1, ans = 0;
    while (i < n && j > 0)
    {
        ans = max(nums[i] + nums[j], ans);
        i++;
        j--;
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
    int ans = minPairSum(v);
    cout<<"Result is: "<<ans<<endl;
    return 0;
}