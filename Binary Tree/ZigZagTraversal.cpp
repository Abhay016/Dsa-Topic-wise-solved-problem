
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

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> res;
    if (root == nullptr)
    {
        return res;
    }
    queue<TreeNode *> q;
    q.push(root);
    int flag = 0;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> temp;
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
            temp.push_back(node->val);
            q.pop();
        }
        if (flag == 1)
            reverse(temp.begin(), temp.end());
        flag = !flag;
        res.push_back(temp);
    }
    return res;
}