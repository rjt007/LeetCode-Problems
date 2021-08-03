//https://leetcode.com/problems/next-greater-element-ii/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) & S.C->O(N)
vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> s;
    for (int i = 0; i < 2 * n; i++)
    {
        int elem = nums[i % n];
        while (!s.empty() && nums[s.top()] < elem)
        {
            ans[s.top()] = elem;
            s.pop();
        }
        if (i < n)
        {
            s.push(i);
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
    vector<int> ans = nextGreaterElements(nums);
    cout << "Result is:\n";
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}