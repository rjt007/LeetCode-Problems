//https://leetcode.com/problems/search-insert-position/
//T.C->O(N) and S.C->O(1)

#include <bits/stdc++.h>
using namespace std;
int searchInsert(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    int ans = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
            ans = low;
        }
        else
        {
            high = mid - 1;
        }
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
    cout<<"Enter Array:\n";
    for (int i = 0; i < n; i++)
    {
        cin>>val;
        nums.push_back(val);
    }
    int target;
    cout<<"Enter target element: ";
    cin>>target;
    int ans = searchInsert(nums, target);
    cout<<"Result is: "<<ans<<endl;
}