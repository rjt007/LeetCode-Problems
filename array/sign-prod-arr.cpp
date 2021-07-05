//https://leetcode.com/problems/sign-of-the-product-of-an-array/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) AND S.C->O(1).
int arraySign(vector<int> &nums)
{
    int n = nums.size();
    int cnt = 0;
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            ans = 0;
            cnt = 0;
            break;
        }
        if (nums[i] < 0)
        {
            cnt++;
        }
    }
    if (cnt != 0 && cnt % 2 == 0)
    {
        ans = 1;
    }
    else if (cnt != 0 && cnt % 2 != 0)
    {
        ans = -1;
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
    int ans = arraySign(nums);
    cout << "Result is: " << ans << endl;
    return 0;
}