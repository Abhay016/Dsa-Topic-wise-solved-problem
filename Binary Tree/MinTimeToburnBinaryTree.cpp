
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

int amountOfTime(TreeNode *root, int start)
{
    int res = 0;
    unordered_map<TreeNode *, TreeNode *> mp;
    TreeNode *node = NULL;
    queue<TreeNode *> q;
    q.push(root);
    mp[root] = NULL;
    while (!q.empty())
    {
        TreeNode *temp = q.front();
        if (temp->val == start)
        {
            node = temp;
        }
        if (temp->left)
        {
            mp[temp->left] = temp;
            q.push(temp->left);
        }
        if (temp->right)
        {
            mp[temp->right] = temp;
            q.push(temp->right);
        }
        q.pop();
    }
    unordered_map<TreeNode *, bool> vis;
    q.push(node);
    vis[node] = 1;
    while (!q.empty())
    {
        int n = q.size();
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            TreeNode *temp = q.front();
            if (temp->left && !vis[temp->left])
            {
                q.push(temp->left);
                vis[temp->left] = 1;
                flag = 1;
            }
            if (temp->right && !vis[temp->right])
            {
                q.push(temp->right);
                vis[temp->right] = 1;
                flag = 1;
            }
            if (mp[temp] && !vis[mp[temp]])
            {
                q.push(mp[temp]);
                vis[mp[temp]] = 1;
                flag = 1;
            }
            q.pop();
        }
        if (flag == 1)
            res++;
    }
    return res;
}