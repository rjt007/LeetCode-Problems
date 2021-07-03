//https://leetcode.com/problems/maximum-subarray/
//T.C->O(N)
//Kaden's Algorithm
#include <bits/stdc++.h>
using namespace std;
int maxSubArray(vector<int> &nums)
{
    int n = nums.size();
    int currsum = 0;
    int maxsum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        currsum += nums[i];
        maxsum = max(maxsum, currsum);
        if (currsum < 0)
        {
            currsum = 0;
        }
    }
    return maxsum;
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
    int ans = maxSubArray(nums);
    cout<<"Result is: "<<ans<<endl;
}