//https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) & S.C->O(1).
int minPartitions(string n)
{
    return *max_element(n.begin(), n.end()) - '0';
}
int main()
{
    string s="";
    cout<<"Enter string: ";
    cin>>s;
    int ans = minPartitions(s);
    cout<<"Result is: "<<ans<<endl;
}