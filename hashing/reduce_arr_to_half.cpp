//https://leetcode.com/problems/reduce-array-size-to-the-half/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(n*log(n)) && S.C->O(N)
int minSetSize(vector<int> &arr)
{
    int n = arr.size(), ans = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    vector<pair<int, int>> v;
    for (auto x : m)
    {
        v.push_back(make_pair(x.second, x.first));
    }
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    int cnt = 0;
    for (int i = 0; i < v.size(); i++)
    {
        //cout<<v[i].first<<" "<<v[i].second<<endl;
        cnt += v[i].first;
        ans++;
        if (cnt >= n / 2)
        {
            break;
        }
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
    int ans = minSetSize(v);
    cout<<"Result is: "<<ans;
    return 0;
}