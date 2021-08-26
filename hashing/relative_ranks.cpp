//https://leetcode.com/problems/relative-ranks/
#include<bits/stdc++.h>
using namespace std;
//T.C->O(n*log(n)) && S.C->O(N)
vector<string> findRelativeRanks(vector<int> &score)
{
    unordered_map<int, int> m;
    int n = score.size();
    vector<string> ans(n, "0");
    for (int i = 1; i <= n; i++)
    {
        m[score[i - 1]] = i;
    }
    sort(score.begin(), score.end(), greater<int>());
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            ans[m[score[i]] - 1] = "Gold Medal";
        }
        else if (i == 1)
        {
            ans[m[score[i]] - 1] = "Silver Medal";
        }
        else if (i == 2)
        {
            ans[m[score[i]] - 1] = "Bronze Medal";
        }
        else
        {
            ans[m[score[i]] - 1] = to_string(i + 1);
        }
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>v;
    int val;
    for (int i = 0; i < n; i++)
    {
        cin>>val;
        v.push_back(val);
    }
    vector<string>ans = findRelativeRanks(v);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}