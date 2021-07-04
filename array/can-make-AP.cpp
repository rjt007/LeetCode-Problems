#include <bits/stdc++.h>
using namespace std;
//T.C->O(N*log(N)) AND S.C->O(1).
bool canMakeArithmeticProgression(vector<int> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int cd = arr[1] - arr[0];
    for (int i = 2; i < n; i++)
    {
        if (arr[i] - arr[i - 1] != cd)
        {
            return false;
        }
    }
    return true;
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
    bool ans = canMakeArithmeticProgression(nums);
    cout << "Result is: " << ans << endl;
    return 0;
}