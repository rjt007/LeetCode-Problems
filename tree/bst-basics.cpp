//BST IMPLEMENTATION
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* left, *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
//BST INSERTION
node* bstinsertion(node* root, int val)
{
    if(root==NULL)
    {
        return new node(val);
    }
    else if(val<root->data)
    {
        root->left = bstinsertion(root->left,val);
    }
    else
    {
        root->right = bstinsertion(root->right,val);
    }
    return root;
}
//BFS TRAVERSAL
void bfstraversal(node* root)
{
    if(root==NULL)
    {
        return;
    }
    queue<node*>q;
    q.push(root);
    while (!q.empty())
    {
        node* temp = q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left!=NULL)
        {
            q.push(temp->left);
        }
        if(temp->right!=NULL)
        {
            q.push(temp->right);
        }
    }
}
//INORDER TRAVERSAL
void inorderiterative(node* root)
{
    if(root==NULL)
    {
        return;
    }
    stack<node*>st;
    node* curr = root;
    while (curr!=NULL || !st.empty())
    {
        while(curr!=NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout<<curr->data<<" ";
        curr = curr->right;
    }
}
//PREORDER TRAVERSAL
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
            curr=curr->left;
        }
        if (!st.empty())
        {
            curr = st.top();
            st.pop();
        }
    }
}
//SEARCH IN BST
bool search(node* root, int key)
{
    if(root==NULL)
    {
        return false;
    }
    else if(root->data==key)
    {
        return true;
    }
    else if(key<root->data)
    {
        return search(root->left,key);
    }
    else
    {
        return search(root->right,key);
    }
    return false;
}
//MAXIMUM ELEMENT IN BST
int maximum(node* root)
{
    if(root==NULL)
    {
        return -1;
    }
    node* temp = root;
    while (temp->right!=NULL)
    {
        temp = temp->right;
    }
    return temp->data;
    /*
    //RECURSIVE APPROACH
    if(root==NULL)
    {
        return -1;
    }
    else if(root->right==NULL)
    {
        return root->data;
    }
    return maximum(root->right);*/
}
//MINIMUM ELEMENT IN BST
int minimum(node* root)
{
    if(root==NULL)
    {
        return -1;
    }
    node* temp = root;
    while (temp->left!=NULL)
    {
        temp = temp->left;
    }
    return temp->data;
    /*
    //RECURSIVE APPROACH
    if(root==NULL)
    {
        return -1;
    }
    else if(root->left==NULL)
    {
        return root->data;
    }
    return minimum(root->left);*/
}
//DELETION IN BST
node* inordersuccesor(node* root)
{
    if(root==NULL)
    {
        return NULL;
    }
    else if(root->left==NULL)
    {
        return root;
    }
    return inordersuccesor(root->left);
}
node* deletion(node* root, int key)
{
    if(root==NULL)
    {
        return root;
    }
    else if(key<root->data)
    {
        root->left = deletion(root->left,key);
    }
    else if(key>root->data)
    {
        root->right = deletion(root->right,key);
    }
    //key found
    else
    {
        if(root->left==NULL && root->right==NULL) //Case1
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL) //Case2-a
        {
            node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) //Case2-b
        {
            node* temp = root->left;
            free(root);
            return temp;
        }
        //case 3
        //using inorder succesor - finding min in right sub tree.
        else
        {
            node *temp = inordersuccesor(root->right);
            root->data = temp->data;
            root->right = deletion(root->right, temp->data);
        }
    }
    return root;
}
//Check tree is BST or NOT
bool isBst(node* root, node* min, node* max)
{
    if(root==NULL)
    {
        return true;
    }
    if(min!=NULL && root->data<=min->data)
    {
        return false;
    }
    if(max!=NULL && root->data>=max->data)
    {
        return false;
    }
    bool leftvalid = isBst(root->left,min,root);
    bool rightvalid = isBst(root->right,root,max);
    return leftvalid && rightvalid;
}
int main()
{
    /*
    (10)
    /  \
   (5) (20)
    \   / \
    (8)(15)(25)
    */
    int n;
    cout<<"Enter number of nodes in bst: ";
    cin>>n;
    int val;
    node* root = NULL;
    while (n--)
    {
        cout<<"Insert node in bst: ";
        cin>>val;
        root = bstinsertion(root,val);
    }
    cout<<"BFS TRAVERSAL IS: ";
    bfstraversal(root);
    cout<<endl;
    cout<<"INORDER TRAVERSAL IS: ";
    inorderiterative(root);
    cout<<endl;
    cout<<"PREORDER TRAVERSAL IS: ";
    preorderiterative(root);
    cout<<endl;
    bool ans = search(root,50);
    cout<<"Is key found? "<<ans<<endl;
    int max = maximum(root);
    cout<<"Maximum element in bst is: "<<max<<endl;
    int min = minimum(root);
    cout<<"Maximum element in bst is: "<<min<<endl;
    root = deletion(root,20);
    cout << "BFS TRAVERSAL IS: ";
    bfstraversal(root);
    cout << endl;
    bool bst = isBst(root,NULL,NULL);
    cout<<"Is Tree is BST? "<<bst<<endl;
}