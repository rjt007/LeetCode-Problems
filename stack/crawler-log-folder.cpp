//https://leetcode.com/problems/crawler-log-folder/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) & S.C->O(N)
int minOperations(vector<string> &logs)
{
    stack<string> st;
    int n = logs.size(), ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (logs[i] == "../")
        {
            if (!st.empty())
            {
                st.pop();
            }
        }
        else if (logs[i] == "./")
        {
            continue;
        }
        else
        {
            st.push(logs[i]);
        }
    }
    while (!st.empty())
    {
        ans++;
        st.pop();
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<string>v;
    string val="";
    for (int i = 0; i <n; i++)
    {
        cin>>val;
        v.push_back(val);
    }
    int ans = minOperations(v);
    cout<<"Result is: "<<ans<<endl;
    return 0;
}