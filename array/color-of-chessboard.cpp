#include <bits/stdc++.h>
using namespace std;
//T.C->O(1) & S.C->O(1)
bool squareIsWhite(string coordinates)
{
    int cal = coordinates[0] + (coordinates[1] - '0');
    bool ans = false;
    if (cal % 2 == 1)
    {
        ans = true;
    }
    return ans;
}
int main()
{
    string s="";
    cin>>s;
    bool ans = squareIsWhite(s);
    cout<<"Result is: "<<ans<<endl;
    return 0;
}