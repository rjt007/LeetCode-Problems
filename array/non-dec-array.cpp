//https://leetcode.com/problems/non-decreasing-array/
#include<bits/stdc++.h>
using namespace std;
//T.C->O(N) and S.C->O(1)
bool checkPossibility(vector<int> &nums)
{
    int cnt = 0;
    for (int i = 1; i < nums.size() && cnt <= 1; i++)
    {
        if (nums[i - 1] > nums[i])
        {
            cnt++;
            if (i - 2 < 0 || nums[i - 2] <= nums[i])
            {
                nums[i - 1] = nums[i];
            }

            else
            {
                nums[i] = nums[i - 1];
            }
        }
    }
    return cnt <= 1;
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
    bool ans = checkPossibility(nums);
    cout << "Result is: "<<ans;
    cout << endl;
    return 0;
}