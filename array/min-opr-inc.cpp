//https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) & S.C->O(1).
int minOperations(vector<int> &nums)
{
    int n = nums.size();
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] <= nums[i - 1])
        {
            cnt += nums[i - 1] - nums[i] + 1;
            nums[i] += nums[i - 1] - nums[i] + 1;
        }
    }
    return cnt;
}
int main()
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int>nums;
    int val;
    cout<<"Enter Array:\n";
    for (int i = 0; i < n; i++)
    {
        cin>>val;
        nums.push_back(val);
    }
    int ans = minOperations(nums);
    cout<<"Result is: "<<ans<<endl;
}