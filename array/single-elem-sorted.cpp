//https://leetcode.com/problems/single-element-in-a-sorted-array/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(log(N)) and S.C->O(N)
int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    while (low < high)
    {
        int mid = (low + high) / 2;
        if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 == 1 && nums[mid] == nums[mid - 1]))
            low = mid + 1;
        else
            high = mid;
    }
    return nums[low];
}
int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> nums;
    int val;
    cout << "Enter Array:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        nums.push_back(val);
    }
    int ans = singleNonDuplicate(nums);
    cout << "Result is: "<<ans;
    cout << endl;
    return 0;
}