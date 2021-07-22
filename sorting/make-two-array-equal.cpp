//https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N*LOG(N)) & S.C->O(1);
bool canBeEqual(vector<int> &target, vector<int> &arr)
{
    sort(target.begin(), target.end());
    sort(arr.begin(), arr.end());
    int n = arr.size();
    bool ans = true;
    for (int i = 0; i < n; i++)
    {
        if (target[i] != arr[i])
        {
            ans = false;
            break;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>v,v1;
    int val;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        v.push_back(val);
    }
    for(int i=0;i<n;i++)
    {
        cin>>val;
        v1.push_back(val);
    }
    bool ans = canBeEqual(v,v1);
    cout<<"Result is: "<< ans <<endl;
}