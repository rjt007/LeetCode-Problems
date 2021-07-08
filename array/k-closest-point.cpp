//https://leetcode.com/problems/k-closest-points-to-origin/
#include<bits/stdc++.h>
using namespace std;
//T.C->O(N) and S.C->O(N)
vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    int n = points.size();
    multimap<int, int> m;
    int cnt = 0;
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        int p1 = points[i][0];
        int p2 = points[i][1];
        int dist = pow(p1, 2) + pow(p2, 2);
        m.insert({dist, i});
    }
    for (auto x : m)
    {
        ans.push_back(points[x.second]);
        cnt++;
        if (cnt == k)
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
    int val1,val2;
    vector<int>v;
    vector<vector<int>>nums;
    for (int i = 0; i < n; i++)
    {
        cin>>val1;
        cin>>val2;
        v.push_back(val1);
        v.push_back(val2);
        nums.push_back(v);
        v.pop_back();
        v.pop_back();
    }
    int k;
    cout<<"Enter value of k: ";
    cin>>k;
    vector<vector<int>>ans = kClosest(nums,k);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
    return 0;
}