//https://leetcode.com/problems/kth-missing-positive-number/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) AND S.C->O(N).
int findKthPositive(vector<int> &arr, int k)
{
    int n = arr.size();
    int ans = 0;
    vector<int> v(1001, -1);
    for (int i = 0; i < n; i++)
    {
        v[arr[i]]++;
    }
    int cnt = 0;
    for (int i = 1; i < 1001; i++)
    {
        if (v[i] == -1)
        {
            cnt++;
            ans = i;
        }
        if (cnt == k)
        {
            break;
        }
    }
    if (k > cnt)
    {
        ans = (1000 + k) - cnt;
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
    int k;
    cout<<"Enter integer to be searched: ";
    cin>>k;
    int ans = findKthPositive(nums,k);
    cout << "Result is: "<<ans<<endl;
    return 0;
}