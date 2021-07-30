//https://leetcode.com/problems/flipping-an-image/
#include <bits/stdc++.h>
using namespace std;
//T.C->O(N*N) & S.C->O(1);
vector<vector<int>> flipAndInvertImage(vector<vector<int>> &image)
{
    int n = image.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < image[i].size() / 2; j++)
        {
            int temp = image[i][j];
            image[i][j] = image[i][image[i].size() - 1 - j];
            image[i][image[i].size() - 1 - j] = temp;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < image[i].size(); j++)
        {
            if (image[i][j] == 0)
            {
                image[i][j] = 1;
            }
            else
            {
                image[i][j] = 0;
            }
        }
    }
    return image;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    int val;
    vector<vector<int>> p;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> val;
            v.push_back(val);
        }
        p.push_back(v);
    }
    vector<vector<int>> ans = flipAndInvertImage(p);
    cout << "Result is: " << ans[0][0] << endl;
    return 0;
}