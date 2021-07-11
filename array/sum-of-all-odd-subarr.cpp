//https://leetcode.com/problems/sum-of-all-odd-length-subarrays/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N^2) & S.C-.O(1)
int sumOddLengthSubarrays(vector<int> &arr)
{
    int n = arr.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int odd = 0, cnt = 0;
        for (int j = i; j < n; j++)
        {
            odd += arr[j];
            cnt++;
            if (cnt % 2 != 0)
            {
                sum += odd;
            }
        }
    }
    return sum;
}

/*
//T.C->O(N) & S.C->O(1)
int sumOddLengthSubarrays(vector<int> &arr)
{
    int ans = 0, n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int contribution = ceil((i + 1) * (n - i) / 2.0);
        ans += (contribution * arr[i]);
    }
    return ans;
}*/

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> v;
    int val;
    cout << "Enter array:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        v.push_back(val);
    }
    int ans = sumOddLengthSubarrays(v);
    cout << "Result is: " << ans << endl;
}