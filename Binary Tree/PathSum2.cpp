
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

void solve(TreeNode *root, int targetSum, vector<vector<int>> &res, vector<int> temp)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        if (targetSum == root->val)
        {
            temp.push_back(root->val);
            res.push_back(temp);
        }
        return;
    }
    temp.push_back(root->val);
    solve(root->left, targetSum - root->val, res, temp);
    solve(root->right, targetSum - root->val, res, temp);
}
vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{
    vector<vector<int>> res;
    vector<int> temp;
    solve(root, targetSum, res, temp);
    return res;
}