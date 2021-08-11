//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
#include<bits/stdc++.h>
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
//T.C->O(N) & S.C->O(N)
vector<int> v;
void inorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    v.push_back(root->val);
    inorder(root->right);
}
bool findTarget(TreeNode *root, int k)
{
    inorder(root);
    int n = v.size();
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (v[i] + v[j] == k)
        {
            return true;
        }
        else if (v[i] + v[j] < k)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return false;
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
    int target;
    cin>>target;
    bool ans = findTarget(root, target);
    cout << endl;
    return 0;
}