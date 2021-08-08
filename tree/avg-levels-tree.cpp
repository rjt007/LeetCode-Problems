//https://leetcode.com/problems/average-of-levels-in-binary-tree/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};
//T.C->O(N) & S.C->O(m), m is max no pf nodes at any level.
vector<double> ans;
void bfs(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);
    double cnt = 0, sum = 0, avg = 0;
    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();
        if (temp != NULL)
        {

            sum += temp->val;
            cnt++;
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }

        else if (!q.empty())
        {
            q.push(NULL);
            avg = sum / cnt;
            ans.push_back(avg);
            cnt = 0;
            sum = 0;
        }
    }
    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();
        sum += temp->val;
        cnt++;
    }
    ans.push_back(sum / cnt);
}
vector<double> averageOfLevels(TreeNode *root)
{
    bfs(root);
    return ans;
}
int main()
{
    /*
    (5)
    / \
   (10) (15)
   / \     / \
  (20)(25)(30)(35)
     */
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(10);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(25);
    root->right->left = new TreeNode(30);
    root->right->right = new TreeNode(35);
    averageOfLevels(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}