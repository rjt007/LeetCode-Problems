#include <bits/stdc++.h>
using namespace std;
//T.C->O(n*log(n)) & S.C->O(N)
vector<int> selfDividingNumbers(int left, int right)
{
    vector<int> ans;
    for (int i = left; i <= right; i++)
    {
        if (i < 10)
        {
            ans.push_back(i);
            continue;
        }
        int count = 1, check = i;

        while (check)
        {
            if (check % 10 == 0)
            {
                count = -1;
                break;
            }
            else
            {
                if (i % (check % 10) != 0)
                {
                    count = -1;
                    break;
                }
            }
            check /= 10;
        }
        if (count != -1)
        {
            ans.push_back(i);
        }
    }
    return ans;
}
int main()
{
    int l,r;
    cin>>l>>r;
    vector<int>ans = selfDividingNumbers(l,r);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}