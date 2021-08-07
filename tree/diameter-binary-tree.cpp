//https://leetcode.com/problems/diameter-of-binary-tree/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int v)
    {
        val = v;
        left = NULL;
        right = NULL;
    }
};
//T.C->O(N) & S.C->O(1)
int diameter(TreeNode *root, int *height)
{
    if (root == NULL)
    {
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int ld = diameter(root->left, &lh);
    int rd = diameter(root->right, &rh);

    int currdia = lh + rh;
    *height = max(lh, rh) + 1;
    return max(currdia, max(ld, rd));
}
int diameterOfBinaryTree(TreeNode *root)
{
    int height = 0;
    int ans = diameter(root, &height);
    return ans;
}
int main()
{
    /*
    (10)
    / \
   (8) (15)
   / 
  (6)*/
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(8);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(6);
    int ans = diameterOfBinaryTree(root);
    cout << "Result is: " << ans << endl;
}