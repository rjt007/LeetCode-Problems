//https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N^2*log(n)) && S.C->O(N)
int kthSmallest(vector<vector<int>> &matrix, int k)
{
    int n = matrix.size();
    priority_queue<int> pq;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            pq.push(matrix[i][j]);
        }
    }
    int l = pq.size();
    while (l - k)
    {
        pq.pop();
        l--;
    }
    return pq.top();
}
int main()
{
    vector<vector<int>>v;
    int n;
    cin>>n;
    int val;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            cin>>val;
            temp.push_back(val);
        }
        v.push_back(temp);
    }
    int k;
    cin>>k;
    int ans = kthSmallest(v,k);
    cout<<"REsult is: "<<ans<<endl;
    return 0;
}