#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) & S.C->O(N)
bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
{
    stack<int> st;
    int n = pushed.size();
    int j = 0;
    for (int x : pushed)
    {
        st.push(x);
        while (!st.empty() && j < n && st.top() == popped[j])
        {
            st.pop();
            j++;
        }
    }
    if (j == n)
    {
        return true;
    }
    return false;
}
/*
//T.C->O(N) & S.C->O(1)
bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
{
    int i = 0, j = 0;
    for (int x : pushed)
    {
        pushed[i++] = x;
        while (i > 0 && pushed[i - 1] == popped[j])
            --i, ++j;
    }
    return i == 0;
}*/
int main()
{
    int n;
    cin >> n;
    vector<int> v1, v2;
    int val;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        v1.push_back(val);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        v2.push_back(val);
    }
    bool ans = validateStackSequences(v1, v2);
    cout << "Result is: " << ans << endl;
    return 0;
}