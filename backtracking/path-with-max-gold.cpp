//https://leetcode.com/problems/path-with-maximum-gold/
#include <bits/stdc++.h>
using namespace std;
int DIR[5] = {0, 1, 0, -1, 0};
int findMaxGold(vector<vector<int>> &grid, int m, int n, int r, int c)
{
    if (r < 0 || r == m || c < 0 || c == n || grid[r][c] == 0)
        return 0;
    int origin = grid[r][c];
    grid[r][c] = 0; // mark as visited
    int maxGold = 0;
    for (int i = 0; i < 4; i++)
        maxGold = max(maxGold, findMaxGold(grid, m, n, DIR[i] + r, DIR[i + 1] + c));
    grid[r][c] = origin; // backtrack
    return maxGold + origin;
}

int getMaximumGold(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    int maxGold = 0;
    for (int r = 0; r < m; r++)
        for (int c = 0; c < n; c++)
            maxGold = max(maxGold, findMaxGold(grid, m, n, r, c));
    return maxGold;
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
    int ans = getMaximumGold(arr);
    cout<<"Result is: "<<ans<<endl;
    return 0;
}