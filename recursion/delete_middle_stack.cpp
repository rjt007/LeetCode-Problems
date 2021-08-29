//Delete middle(kth) element from stack
#include <bits/stdc++.h>
using namespace std;

void solve(stack<int>&st,int k)
{
    if(k==1)
    {
        st.pop();
        return;
    }
    int temp = st.top();
    st.pop();
    solve(st,k-1);
    st.push(temp);
    return;
}
stack<int>deletemiddle(stack<int>s,int size)
{
    if(s.size()==0)
    {
        return s;
    }
    int k = size/2+1;
    solve(s,k);
    return s;
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
    cout << "stack after deletion is: ";
    st = deletemiddle(st,n);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    return 0;
}