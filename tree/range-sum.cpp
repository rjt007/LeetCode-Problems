//https://leetcode.com/problems/range-sum-of-bst/
#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left, *right;
    TreeNode(int v)
    {
        val = v;
        left=NULL;
        right=NULL;
    }
};
//T.C->O(N) & S.C->O(N)
int sum = 0;
int rangeSumBST(TreeNode *root, int low, int high)
{
    if (root == NULL)
    {
        return sum;
    }
    if (root->val >= low && root->val <= high)
    {
        sum += root->val;
    }
    rangeSumBST(root->left, low, high);
    rangeSumBST(root->right, low, high);
    return sum;
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
    int ans = rangeSumBST(root,8,15);
    cout<<"Result is: "<<ans<<endl;
}