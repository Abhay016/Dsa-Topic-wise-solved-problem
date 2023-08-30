
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

int solve(Node *root, int k, int node, stack<int> &temp)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->data == node)
    {
        temp.push(root->data);
        return 1;
    }
    temp.push(root->data);
    int left = solve(root->left, k, node, temp);
    if (left == 1)
        return 1;
    int right = solve(root->right, k, node, temp);
    if (right == 1)
        return 1;
    temp.pop();
}

int kthAncestor(Node *root, int k, int node)
{
    stack<int> temp;
    solve(root, k, node, temp);
    while (!temp.empty() && k--)
    {
        temp.pop();
    }
    if (temp.empty())
        return -1;
    else
        return temp.top();
}
