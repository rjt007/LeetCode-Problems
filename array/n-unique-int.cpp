//https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) and S.C->O(1)
vector<int> sumZero(int n)
{
    vector<int> v;
    int sum = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        v.push_back(i);
        v.push_back(-i);
    }
    if (n % 2 != 0)
    {
        v.push_back(0);
    }
    return v;
}
int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> ans = sumZero(n);
    cout << "Result is:\n";
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}