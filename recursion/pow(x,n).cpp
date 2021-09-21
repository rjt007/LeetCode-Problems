//https://leetcode.com/problems/powx-n/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(log(N)) & S.C->O(1).
double myPow(double x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    double p = myPow(x, n / 2);

    if (n % 2)
    {
        return n < 0 ? (1 / x) * p * p : x * p * p;
    }

    return p * p;
}

int main()
{
    int n;
    double x;
    cin>>x>>n;
    double ans = myPow(x,n);
    cout<<"Result is: "<<ans<<endl;
    return 0;
}