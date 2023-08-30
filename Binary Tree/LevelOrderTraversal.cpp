
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

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> res;
    if (root == nullptr)
    {
        return res;
    }
    queue<TreeNode *> q;
    q.push(root);
    q.push(nullptr);
    vector<int> temp;
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if (node == nullptr)
        {
            res.push_back(temp);
            temp.clear();
            if (!q.empty())
                q.push(nullptr);
        }
        else
        {
            temp.push_back(node->val);
            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
        }
    }
    return res;
}