//https://leetcode.com/problems/height-checker/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N*log(N)), S.C->O(N)
int heightChecker(vector<int> &heights)
{
    vector<int> v(heights);
    int n = heights.size(), ans = 0;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        if (heights[i] != v[i])
        {
            ans++;
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
    int ans = heightChecker(v);
    cout<<"Result is: "<<ans<<endl;
    return 0;
}