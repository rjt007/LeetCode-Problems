//https://leetcode.com/problems/count-good-triplets/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N^3) & S.C->O(1).
int countGoodTriplets(vector<int> &arr, int a, int b, int c)
{
    int cnt = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (abs(arr[i] - arr[j]) <= a)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c)
                    {
                        cnt++;
                    }
                }
            }
        }
    }
    return cnt;
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
    int a,b,c;
    cout<<"Enter triplets: a,b,c: ";
    cin>>a>>b>>c;
    int ans = countGoodTriplets(nums,a,b,c);
    cout<<"Result is: "<<ans<<endl;
}