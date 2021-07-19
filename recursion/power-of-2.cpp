#include <bits/stdc++.h>
using namespace std;
//T.C->O(log(N)) & S.C->O(N)
bool isPowerOfTwo(int n)
{

    if (n == 1)
    {
        return true;
    }
    if (n % 2 != 0)
    {
        return false;
    }
    return isPowerOfTwo(n / 2);
}
/*
//T.C->O(1) & S.C->O(1), using bit minpulation.
bool isPowerOfTwo(int n)
{
    if (n <= 0)
    {
        return false;
    }
    return !(n & (n - 1));
}*/
int main()
{
    int n;
    cin>>n;
    bool ans = isPowerOfTwo(n);
    cout<<"Result is: "<<ans<<endl;
    return 0;
}