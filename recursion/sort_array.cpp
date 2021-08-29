//Sort Array Using Recursion.
#include<bits/stdc++.h>
using namespace std;
void insert(vector<int>&v,int ele)
{
    if(v.size()==0||v[v.size()-1]<=ele)
    {
        v.push_back(ele);
        return;
    }
    int val = v[v.size()-1];
    v.pop_back();
    insert(v,ele);
    v.push_back(val);
    return;
}
void sorrt(vector<int>&v)
{
    if(v.size()==1)
    {
        return;
    }
    int ele = v[v.size()-1];
    v.pop_back();
    sorrt(v);
    insert(v,ele);
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
    sorrt(v);
    cout<<"Sorted array is: ";
    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}