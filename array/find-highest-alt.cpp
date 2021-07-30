//https://leetcode.com/problems/find-the-highest-altitude/
#include <bits/stdc++.h>
using namespace std;
///T.C->O(N) & S.C->O(1);
int largestAltitude(vector<int> &gain)
{
    for (int i = 1; i < gain.size(); i++)
    {
        gain[i] += gain[i - 1];
    }
    return max(0, *max_element(gain.begin(), gain.end()));
}
int main()
{
    int n;
    cin>>n;
    vector<int>alt;
    int val;
    for (int i = 0; i < n; i++)
    {
        cin>>val;
        alt.push_back(val);
    }
    int ans = largestAltitude(alt);
    cout<<"Result is: "<<ans<<endl;
    return 0;
}