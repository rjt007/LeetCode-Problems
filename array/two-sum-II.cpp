//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) AND S.C->O(1).
vector<int> twoSum(vector<int> &numbers, int target)
{
    int n = numbers.size();
    int i = 0, j = n - 1;
    vector<int> v;
    while (i < j)
    {
        if (numbers[i] + numbers[j] == target)
        {
            v.push_back(i + 1);
            v.push_back(j + 1);
            break;
        }
        else if (numbers[i] + numbers[j] > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return v;
}
int main()
{
    int n;
    cout << "Enter Size of array: ";
    cin >> n;
    vector<int> nums;
    int val;
    cout << "Enter Array:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        nums.push_back(val);
    }
    int target;
    cout << "Enter target element: ";
    cin >> target;
    vector<int> ans;
    ans = twoSum(nums, target);
    cout << "Required indices are: ";
    for (int i = 0; i < 2; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}