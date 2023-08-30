

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

class Solution
{
public:
    bool isValid(TreeNode *root, int i, int j)
    {
        if (root == NULL)
        {
            return true;
        }
        if (root->val > i && root->val < j)
        {
            bool left=isValid(root->left, i, root->val);
            bool right=isValid(root->right, root->val, j);
            return left && right;
        }
        else
        {
            return false;
        }
    }
    bool isValidBST(TreeNode *root)
    {
        return isValid(root, INT_MIN, INT_MAX);
    }
};