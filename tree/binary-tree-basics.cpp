//BINARY TREE IMPLEMENTATION
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left, *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
//BFS INSERTION
node *bfsinsertion(node *root, int val)
{
    if (root == NULL)
    {
        return new node(val);
    }
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp->left == NULL)
        {
            temp->left = new node(val);
            return root;
        }
        else if (temp->right == NULL)
        {
            temp->right = new node(val);
            return root;
        }
        else
        {
            q.push(temp->left);
            q.push(temp->right);
        }
    }
    return root;
}
//BFS TRAVERSAL
void bfstraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp != NULL)
        {
            cout << temp->data << " ";
        }
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
    }
}
//INORDER TRAVERSAL
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
//PREORDER TRAVERSAL
void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
//POSTORDER TRAVERSAL
void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
//Height of Binary Tree
int height(node* root)
{
    if(root==NULL)
    {
        return -1;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh,rh)+1;
}
//Sum of All elements
int sum(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return sum(root->left)+sum(root->right)+root->data;
}
//INORDER USING STACK
void inorderiterative(node* root)
{
    if(root==NULL)
    {
        return;
    }
    stack<node*>st;
    node* curr = root;
    while (curr!=NULL || !st.empty())//both conds are important.
    {
        while (curr!=NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout << curr->data<<" ";
        curr = curr->right;
    }
    
}
//PREORDER USING STACK
void preorderiterative(node* root)
{
    if(root==NULL)
    {
        return;
    }
    stack<node*>st;
    node* curr = root;
    while (curr!=NULL || !st.empty())
    {
        while (curr!=NULL)
        {
            cout<<curr->data<<" ";
            if(curr->right!=NULL)
            {
                st.push(curr->right);
            }
            curr = curr->left;
        }
        if(!st.empty())
        {
            curr = st.top();
            st.pop();        
        }
    }
}
//POSTORDER USING STACK
void postorderiterative(node* root)
{
    if(root==NULL)
    {
        return;
    }
    stack<node*>st1,st2;
    st1.push(root);
    node* curr = NULL;
    while (!st1.empty())
    {
        curr = st1.top();
        st1.pop();
        st2.push(curr);
        if(curr->left!=NULL)
        {
            st1.push(curr->left);
        }
        if(curr->right!=NULL)
        {
            st1.push(curr->right);
        }
    }
    while (!st2.empty())
    {
        curr = st2.top();
        st2.pop();
        cout<<curr->data<<" ";
    }
}
int main()
{
    int n;
    cout<<"Enter number of nodes in tree: ";
    cin>>n;
    int val;
    node* root = NULL;
    while (n--)
    {
        cout << "Insert data in tree: ";
        cin>>val;
        root = bfsinsertion(root,val);
    }
    cout<<"Inorder Traversal: ";
    inorderiterative(root);
    cout<<endl;
    cout<<"Preorder Traversal: ";
    preorderiterative(root);
    cout<<endl;
    cout<<"POstorder Traversal: ";
    postorderiterative(root);
    cout<<endl;
    cout<<"Bfs Traversal: ";
    bfstraversal(root);
    cout<<endl;
    int h = height(root);
    cout<<"Height is: "<<h<<endl;
    int s = sum(root);
    cout<<"Sum is: "<<s<<endl;
}