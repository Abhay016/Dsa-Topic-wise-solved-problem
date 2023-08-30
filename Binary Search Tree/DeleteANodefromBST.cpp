
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->val == key)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->left && root->right == NULL)
        {
            TreeNode *temp = root->left;
            delete root;
            return temp;
        }
        else if (root->left == NULL && root->right)
        {
            TreeNode *temp = root->right;
            delete root;
            return temp;
        }
        else
        {
            TreeNode *temp = root->left;
            while (temp->right)
            {
                temp = temp->right;
            }
            int data = temp->val;
            root->val = data;
            root->left = deleteNode(root->left, data);
            return root;
        }
    }
    else if (root->val > key)
    {
        root->left = deleteNode(root->left, key);
        return root;
    }
    else
    {
        root->right = deleteNode(root->right, key);
        return root;
    }
    return root;
}