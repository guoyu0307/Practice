#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void preorder_Traversal_Recursion(TreeNode *root)
{
    if(root != NULL)
    {
        cout<<root->val<<" ";
        preorder_Traversal_Recursion(root->left);
        preorder_Traversal_Recursion(root->right);
    }
    else
    {
        return;
    }
}

void preorder_Traversal_NonRecursion(TreeNode *root)
{
    stack<TreeNode*> store;
    TreeNode* index = root;
    while((index != NULL) || (!store.empty()))
    {
        while(index != NULL)
        {
            store.push(index);
            cout<<index->val<<" ";
            index = index->left;
        }
        if(!store.empty())
        {
            index = store.top();
            store.pop();
            index = index->right;
        }
    }
}

void midorder_Traversal_Recursion(TreeNode *root)
{
    if(root != NULL)
    {
        midorder_Traversal_Recursion(root->left);
        cout<<root->val<<" ";
        midorder_Traversal_Recursion(root->right);
    }
    else
    {
        return;
    }
}

void midorder_Traversal_NonRecursion(TreeNode *root)
{
    stack<TreeNode*> store;
    TreeNode* index = root;
    while((index != NULL) || !store.empty())
    {
        while(index != NULL)
        {
            store.push(index);
            index = index->left;
        }

        if(!store.empty())
        {
            index = store.top();
            store.pop();
            cout<<index->val;
            index = index->right;
        }
    }
}

void postorder_Traversal_Recursion(TreeNode *root)
{
    if(root != NULL)
    {
        postorder_Traversal_Recursion(root->left);
        postorder_Traversal_Recursion(root->right);
        cout<<root->val<<" ";
    }
    else
    {
        return;
    }
}

void postorder_Traversal_NonRecursion(TreeNode *root)
{
    stack<TreeNode*> store;
    store.push(root);
    TreeNode* head = root;

    while(!store.empty())
    {
        TreeNode* cur = store.top();

        if((cur->right == head) || (cur->left == head) || ((cur->right == NULL) && (cur->left == NULL)))
        {
            store.pop();
            cout<<cur->val;
            head = cur;
        }
        else
        {
            if(cur->right != NULL)  store.push(cur->right);
            if(cur->left != NULL)   store.push(cur->left);
        }
    }

}
/***********************************************
                0
            1        2
         3     4         5
              6         7  8

pre-order:  0 1 3 4 6 2 5 7 8
mid-order:  3 1 6 4 0 2 7 5 8
post-order: 3 6 4 1 7 8 5 2 0
***********************************************/
int main()
{
    TreeNode* root = new TreeNode(0);
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n6 = new TreeNode(6);
    TreeNode* n7 = new TreeNode(7);
    TreeNode* n8 = new TreeNode(8);

    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->right = n5;
    n4->left = n6;
    n5->left = n7;
    n5->right = n8;

    postorder_Traversal_NonRecursion(root);
}
