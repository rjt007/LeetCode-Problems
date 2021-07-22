//https://leetcode.com/problems/maximum-units-on-a-truck/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N*log(N)), S.C->O(1)
int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
{
    sort(boxTypes.begin(), boxTypes.end(), [](vector<int> &first, vector<int> &second)
         { return first[1] > second[1]; });
    int ans = 0;
    for (auto box : boxTypes)
    {
        int x = min(box[0], truckSize);
        ans += (x * box[1]);
        truckSize -= x;
        if (truckSize == 0)
        {
            break;
        }
    }
    return ans;
}
int main()
{
    int m,n;
    cin>>m>>n;
    vector<int>v;
    vector<vector<int>>arr;
    int val;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>val;
            v.push_back(val);
        }
        arr.push_back(v);
        v.clear();
    }
    int truckSize;
    cin>>truckSize;
    int ans = maximumUnits(arr,truckSize);
    cout<<"Result is: "<<ans<<endl;
    return 0;
}