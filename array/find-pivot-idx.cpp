//https://leetcode.com/problems/find-pivot-index/
#include <bits/stdc++.h>
using namespace std;
int pivotIndex(vector<int> &nums)
{
    int n = nums.size();
    int leftsum = 0, rightsum = 0;
    int sum = 0, ans = -1;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }
    for (int i = 0; i < n; i++)
    {
        rightsum = sum - nums[i] - leftsum;
        if (leftsum == rightsum)
        {
            ans = i;
            break;
        }
        leftsum += nums[i];
    }
    return ans;
}
int main()
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int>nums;
    int val;
    cout<<"Enter array:\n";
    for(int i=0;i<n;i++)
    {
        cin>>val;
        nums.push_back(val);
    }
    int ans = pivotIndex(nums);
    cout<<"Result is: "<<ans<<endl;
}