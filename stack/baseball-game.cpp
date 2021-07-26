//https://leetcode.com/problems/baseball-game/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) & S.C->O(N)
int calPoints(vector<string> &ops)
{
    int n = ops.size();
    stack<int> st;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (ops[i] == "+")
        {
            int s1 = st.top();
            st.pop();
            int s2 = st.top();
            st.push(s1);
            st.push(s1 + s2);
        }
        else if (ops[i] == "D")
        {
            st.push(2 * st.top());
        }
        else if (ops[i] == "C")
        {
            st.pop();
        }
        else
        {
            st.push(stoi(ops[i]));
        }
    }
    while (!st.empty())
    {
        ans += st.top();
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
    int ans = calPoints(v);
    cout<<"Result is: "<<ans<<endl;
    return 0;
}