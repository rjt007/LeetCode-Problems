//https://leetcode.com/problems/relative-ranks/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(n*log(n)) && S.C->O(N)
vector<string> findRelativeRanks(vector<int> &score)
{
    priority_queue<pair<int, int>> pq;
    int n = score.size();
    vector<string> ans(n, "");
    for (int i = 0; i < n; i++)
    {
        pq.push(make_pair(score[i], i));
    }
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            ans[pq.top().second] = "Gold Medal";
        }
        else if (i == 1)
        {
            ans[pq.top().second] = "Silver Medal";
        }
        else if (i == 2)
        {
            ans[pq.top().second] = "Bronze Medal";
        }
        else
        {
            ans[pq.top().second] = to_string(i + 1);
        }
        pq.pop();
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    int val;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        v.push_back(val);
    }
    vector<string> ans = findRelativeRanks(v);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}