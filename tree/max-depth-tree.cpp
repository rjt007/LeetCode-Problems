//https://leetcode.com/problems/maximum-depth-of-binary-tree/
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
//T.C->O(N) & S.C->O(H)
int maxDepth(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ld = maxDepth(root->left);
    int rd = maxDepth(root->right);
    return max(ld, rd) + 1;
}
int main()
{
    /*
    (1)
    / \
   (0) (1)
   / \   / \
  (0)(1)(0) (1)
     */
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);
    int res = maxDepth(root);
    cout << res << endl;
    return 0;
}