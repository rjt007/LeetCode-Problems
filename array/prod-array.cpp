//https://leetcode.com/problems/product-of-array-except-self/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(n) and S.C->O(1)
vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    int fromBegin = 1;
    int fromLast = 1;
    vector<int> res(n, 1);

    for (int i = 0; i < n; i++)
    {
        res[i] *= fromBegin;
        fromBegin *= nums[i];
        res[n - 1 - i] *= fromLast;
        fromLast *= nums[n - 1 - i];
    }
    return res;
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
    vector<int>ans = productExceptSelf(nums);
    cout<<"Result is:\n";
    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}