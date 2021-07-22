//https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N), S.C->O(N)
vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
{
    multimap<int, int> m;
    vector<int> ans;
    int n = mat.size();
    for (int i = 0; i < n; i++)
    {
        int val = 0;
        for (int j = 0; j < mat[i].size(); j++)
        {
            if (mat[i][j] == 1)
            {
                val++;
            }
        }
        m.insert({val, i});
    }
    for (auto x : m)
    {
        if (k == 0)
        {
            break;
        }
        ans.push_back(x.second);
        k--;
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
    int k;
    cin>>k;
    vector<int> ans = kWeakestRows(arr,k);
    cout<<"Result is:\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}