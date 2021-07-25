//https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) & S.C->O(N)
vector<int> finalPrices(vector<int> &prices)
{
    stack<int> st, idx;
    idx.push(0);
    st.push(prices[0]);
    int n = prices.size();
    for (int i = 1; i < n; i++)
    {
        while (!st.empty() && st.top() >= prices[i])
        {
            prices[idx.top()] -= prices[i];
            idx.pop();
            st.pop();
        }
        idx.push(i);
        st.push(prices[i]);
    }
    return prices;
}
int main()
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int>v;
    int val;
    for (int i = 0; i < n; i++)
    {
        cin>>val;
        v.push_back(val);
    }
    vector<int>ans = finalPrices(v);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}