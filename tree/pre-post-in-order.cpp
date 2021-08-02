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
//PostOrder
vector<int> ans;
vector<int> postorderTraversal(TreeNode *root)
{
    if (root == NULL)
    {
        return ans;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    ans.push_back(root->val);
    return ans;
}
//Preorder
vector<int>ans1;
vector<int> preorderTraversal(TreeNode *root)
{
    if (root == NULL)
    {
        return ans1;
    }
    ans1.push_back(root->val);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
    return ans1;
}
//Inorder
vector<int>ans2;
vector<int> inorderTraversal(TreeNode *root)
{
    if (root == NULL)
    {
        return ans2;
    }
    
    inorderTraversal(root->left);
    ans2.push_back(root->val);
    inorderTraversal(root->right);
    return ans2;
}
int main()
{
    /*
    (1)
    / \
   (2) (3)
   / 
  (4)*/
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    postorderTraversal(root);
    cout<<"PostOrder Traversal:\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    preorderTraversal(root);
    cout<<"PreOrder Traversal:\n";
    for (int i = 0; i < ans1.size(); i++)
    {
        cout<<ans1[i]<<" ";
    }
    cout<<endl;
    inorderTraversal(root);
    cout<<"InOrder Traversal:\n";
    for (int i = 0; i < ans2.size(); i++)
    {
        cout<<ans2[i]<<" ";
    }
    cout<<endl;
    return 0;
}