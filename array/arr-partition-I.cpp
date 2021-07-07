//https://leetcode.com/problems/array-partition-i/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(n*log(n)) & S.C->O(1).
int arrayPairSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            sum += nums[i];
        }
    }
    return sum;
}
int main()
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int>nums;
    int val;
    cout<<"Enter Array:\n";
    for (int i = 0; i < n; i++)
    {
        cin>>val;
        nums.push_back(val);
    }
    int ans = arrayPairSum(nums);
    cout<<"Result is: "<<ans<<endl;
}