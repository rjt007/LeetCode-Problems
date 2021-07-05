//https://leetcode.com/problems/max-consecutive-ones/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) AND S.C->O(1).
int findMaxConsecutiveOnes(vector<int> &nums)
{
    int n = nums.size();
    int cnt = 0;
    int maxcnt = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
        {
            cnt++;
        }
        else
        {
            cnt = 0;
        }
        maxcnt = max(cnt, maxcnt);
    }
    return maxcnt;
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
    int ans = findMaxConsecutiveOnes(nums);
    cout << "Result is: " << ans << endl;
    return 0;
}