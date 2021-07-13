//https://leetcode.com/problems/count-items-matching-a-rule/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) && S.C->O(1)
int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue)
{
    int n = items.size(), cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (ruleKey == "type")
        {
            if (items[i][0] == ruleValue)
            {
                cnt++;
            }
        }
        else if (ruleKey == "color")
        {
            if (items[i][1] == ruleValue)
            {
                cnt++;
            }
        }
        else if (ruleKey == "name")
        {
            if (items[i][2] == ruleValue)
            {
                cnt++;
            }
        }
    }
    return cnt;
}
int main()
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<string>v;
    vector<vector<string>>s;
    string val;
    for(int i=0;i<n;i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin>>val;
            v.push_back(val);
        }
        s.push_back(v);
        v.clear();
    }
    string ruleKey="", ruleValue="";
    cout<<"Enter RK, RV: ";
    cin>>ruleKey>>ruleValue;
    int ans = countMatches(s,ruleKey,ruleValue);
    cout<<"Result is: "<<ans<<endl;
}