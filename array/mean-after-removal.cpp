//https://leetcode.com/problems/mean-of-array-after-removing-some-elements/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) AND S.C->O(1).
double trimMean(vector<int> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int rm = (n * 5) / 100;
    int sum = 0;
    double mean = 0;
    for (int i = rm; i < n - rm; i++)
    {
        sum += arr[i];
    }
    mean = (double)sum / (n - 2 * rm);
    return mean;
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
    double ans = trimMean(nums);
    cout << "Result is: " << ans << endl;
    return 0;
}