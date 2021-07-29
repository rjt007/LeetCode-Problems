//https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) & S.C->O(1);
int countStudents(vector<int> &students, vector<int> &sandwiches)
{
    int a[] = {0, 0};
    for (int i = 0; i < students.size(); i++)
    {
        a[students[i]]++;
    }
    int k = 0;
    while (k < sandwiches.size())
    {
        if (a[sandwiches[k]] > 0)
        {
            a[sandwiches[k]]--;
        }
        else
        {
            break;
        }
        k++;
    }
    return sandwiches.size() - k;
}
int main()
{
    int n;
    cin>>n;
    vector<int>v1,v2;
    int val;
    cout<<"v1: \n";
    for (int i = 0; i < n; i++)
    {
        cin>>val;
        v1.push_back(val);
    }
    cout<<"v2 \n";
    for (int i = 0; i < n; i++)
    {
        cin>>val;
        v2.push_back(val);
    }
    int ans = countStudents(v1,v2);
    cout<<"Result is: "<<ans<<endl;
    return 0;
}