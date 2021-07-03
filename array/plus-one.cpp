#include <bits/stdc++.h>
using namespace std;
//T.C->O(N) and S.C->O(1).
vector<int> plusOne(vector<int> &digits)
{
    int n = digits.size();
    int flag = 0;
    int carry = 0;
    for (int i = 0; i < n; i++)
    {
        if (digits[i] != 9)
        {
            flag = 1;
        }
    }
    if (flag == 0)
    {
        digits.clear();
        digits.push_back(1);
        for (int i = 1; i < n + 1; i++)
        {
            digits.push_back(0);
        }
        return digits;
    }
    else
    {
        if (digits[n - 1] != 9)
        {
            digits[n - 1]++;
            return digits;
        }

        for (int i = 0; i < n; i++)
        {

            if (digits[n - 1 - i] != 9)
            {
                digits[n - 1 - i] += carry;
                return digits;
            }
            else
            {
                digits[n - 1 - i] = 0;
                carry = 1;
            }
        }
    }
    return digits;
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> nums;
    int val;
    cout << "Enter Array:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        nums.push_back(val);
    }
    vector<int> ans = plusOne(nums);
    cout << "Result is:\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}