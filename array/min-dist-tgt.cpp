//https://leetcode.com/problems/minimum-distance-to-the-target-element/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) AND S.C->O(1).
int getMinDistance(vector<int> &nums, int target, int start)
{
    int n = nums.size();
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == target)
        {
            ans = min(abs(start - i), ans);
        }
    }
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
    int target, start;
    cout<<"Enter target and start element: ";
    cin>>target>>start;
    int ans = getMinDistance(nums, target, start);
    cout << "Result is: " << ans << endl;
    return 0;
}