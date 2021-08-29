//Reverse stack using recursion.
#include <bits/stdc++.h>
using namespace std;

void solve(stack<int>&st,int temp)
{
    if(st.size()==0)
    {
        st.push(temp);
        return;
    }
    int val = st.top();
    st.pop();
    solve(st,temp);
    st.push(val);
    return;
}
void reversee(stack<int>&st)
{
    if(st.size()==0)
    {
        return;
    }
    int temp = st.top();
    st.pop();
    reversee(st);
    solve(st, temp);
    return;
}
int main()
{
    int n, val;
    cin >> n;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        st.push(val);
    }
    cout << "Reversed stack is: ";
    reversee(st);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    return 0;
}