
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

void LeftNode(Node *root, vector<int> &res)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }
    res.push_back(root->data);
    LeftNode(root->left, res);
    if (root->left == NULL)
        LeftNode(root->right, res);
}
void RightNode(Node *root, vector<int> &res)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }
    RightNode(root->right, res);
    if (root->right == NULL)
        RightNode(root->left, res);
    res.push_back(root->data);
}
void LeafNode(Node *root, vector<int> &res)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        res.push_back(root->data);
        return;
    }
    LeafNode(root->left, res);
    LeafNode(root->right, res);
}
vector<int> boundary(Node *root)
{
    vector<int> res;
    if (root == NULL)
        return res;
    res.push_back(root->data);
    LeftNode(root->left, res);
    LeafNode(root->left, res);
    LeafNode(root->right, res);
    RightNode(root->right, res);
    return res;
}