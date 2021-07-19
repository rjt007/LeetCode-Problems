#include <bits/stdc++.h>
using namespace std;
//T.C->O(log(N)) & S.C->O(N)
bool isPowerOfThree(int n)
{
    if (n == 1)
    {
        return true;
    }
    if (n % 3 != 0)
    {
        return false;
    }
    return isPowerOfThree(n / 3);
}
/*
//T.C->O(1) & S.C->O(1)
bool isPowerOfThree(int n)
{
    return fmod(log10(n) / log10(3), 1) == 0;
}*/

int main()
{
    int n;
    cin>>n;
    bool ans = isPowerOfThree(n);
    cout<<"Result is: "<<ans<<endl;
    return 0;
}