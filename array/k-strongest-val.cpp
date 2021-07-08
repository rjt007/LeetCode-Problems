//https://leetcode.com/problems/the-k-strongest-values-in-an-array/
#include<bits/stdc++.h>
using namespace std;
//T.C->O(N*log(N)) and S.C->O(1)
vector<int> getStrongest(vector<int> &arr, int k)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int median = arr[(n - 1) / 2];
    vector<int> ans;
    int cnt = 0;
    int i = 0, j = n - 1;
    while (i <= j)
    {
        if (abs(median - arr[i]) > abs(median - arr[j]))
        {
            ans.push_back(arr[i]);
            i++;
        }
        else
        {
            ans.push_back(arr[j]);
            j--;
        }
        if (ans.size() == k)
        {
            break;
        }
    }
    return ans;
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
    int k;
    cout<<"Enter k: ";
    cin>>k;
    vector<int>ans = getStrongest(nums,k);
    cout<<"Result is:\n";
    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}