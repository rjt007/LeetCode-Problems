//https://leetcode.com/problems/minimum-time-visiting-all-points/
#include <bits/stdc++.h>
using namespace std;
///T.C->O(N) & S.C->O(1);
int minTimeToVisitAllPoints(vector<vector<int>> &points)
{
    int ans = 0;
    for (int i = 1; i < points.size(); i++)
    {
        ans += max(abs(points[i][1] - points[i - 1][1]), abs(points[i][0] - points[i - 1][0]));
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>v;
    int val;
    vector<vector<int>>p;
    for (int i = 0; i < n; i++)
    {
        for(int j=0;j<2;j++)
        {
            cin>>val;
            v.push_back(val);
        }
        p.push_back(v);
    }
    int ans = minTimeToVisitAllPoints(p);
    cout<<"Result is: "<<ans<<endl;
    return 0;
}