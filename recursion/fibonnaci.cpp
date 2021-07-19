#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) && S.C->O(N)
int fib(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}
int main()
{
    cout<<log2(8);
    int n;
    cin>>n;
    int ans = fib(n);
    cout<<"Result is: "<<ans<<endl;
    return 0;
}