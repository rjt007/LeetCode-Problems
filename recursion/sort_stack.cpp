//Sort Stack Using Recursion.
#include <bits/stdc++.h>
using namespace std;

void insert(stack<int>&st,int val)
{
    if(st.empty()||st.top()>=val)
    {
        st.push(val);
        return;
    }
    int temp = st.top();
    st.pop();
    insert(st,val);
    st.push(temp);
    return;
}
void sorrt(stack<int>&st)
{
    if(st.size()==1)
    {
        return;
    }
    int val = st.top();
    st.pop();
    sorrt(st);
    insert(st,val);
}
int main()
{
    int n,val;
    cin>>n;
    stack<int>st;
    for (int i = 0; i < n; i++)
    {
        cin>>val;
        st.push(val);
    }
    cout<<"Sorted stack is: ";
    sorrt(st);
    while (!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    return 0;
}