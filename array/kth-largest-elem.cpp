//https://leetcode.com/problems/kth-largest-element-in-an-array/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(n*log(n)) and S.C->O(1)
int findKthLargest(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end(), greater<int>());
    int n = nums.size();
    int ans = nums[k - 1];
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
    int k;
    cout<<"Enter integer to be searched: ";
    cin>>k;
    int ans = findKthLargest(nums,k);
    cout << "Result is: "<<ans<<endl;
    return 0;
}