//https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N*log(N)), S.C->O(1)
int maxProduct(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    return (nums[nums.size() - 1] - 1) * (nums[nums.size() - 2] - 1);
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
    int ans = maxProduct(v);
    cout<<"Result is: "<<ans<<endl;
    return 0;
}