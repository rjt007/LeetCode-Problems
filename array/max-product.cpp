//https://leetcode.com/problems/maximum-product-difference-between-two-pairs/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N*log(N)) AND S.C->O(1).
int maxProductDifference(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int prod1 = nums[0] * nums[1];
    int prod2 = nums[n - 1] * nums[n - 2];
    int ans = prod2 - prod1;
    return ans;
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
    int ans = maxProductDifference(nums);
    cout << "Result is: "<<ans<<endl;
    return 0;
}