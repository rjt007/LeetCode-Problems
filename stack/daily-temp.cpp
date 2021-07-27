//https://leetcode.com/problems/daily-temperatures/submissions/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) & S.C->O(N), uisng one stack
vector<int> dailyTemperatures(vector<int> &temperatures)
{
    stack<int> idx;
    int n = temperatures.size();
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        while (!idx.empty() && temperatures[i] > temperatures[idx.top()])
        {
            ans[idx.top()] = abs(i - idx.top());
            idx.pop();
        }
        idx.push(i);
    }
    return ans;
}
/*
//T.C->O(N) & S.C->O(N), uisng two stacks
vector<int> dailyTemperatures(vector<int> &temperatures)
{
    stack<int> st, idx;
    int n = temperatures.size();
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && temperatures[i] > st.top())
        {
            ans[idx.top()] = abs(i - idx.top());
            st.pop();
            idx.pop();
        }
        st.push(temperatures[i]);
        idx.push(i);
    }
    return ans;
}*/
int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> v;
    int val;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        v.push_back(val);
    }
    vector<int> ans = dailyTemperatures(v);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}