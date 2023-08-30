
/*  
     Given 2 Arrays of Inorder and preorder traversal. 
The tree can contain duplicate elements. Construct a tree and 
            print the Postorder traversal.   
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node *constructTree(int preorder[], int inorder[], int n, int &i, int s, int e, unordered_map<int, queue<int>> &mp)
{
    if (i >= n || s > e)
    {
        return NULL;
    }
    Node* root;
    // new Node(preorder[i]);
    int j = mp[preorder[i]].front();
    mp[preorder[i]].pop();
    i++;
    root->left = constructTree(preorder, inorder, n, i, s, j - 1, mp);
    root->right = constructTree(preorder, inorder, n, i, j + 1, e, mp);
    return root;
}
Node *buildTree(int in[], int pre[], int n)
{
    unordered_map<int, queue<int>> mp;
    for (int i = 0; i < n; i++)
    {
        mp[in[i]].push(i);
    }
    int i = 0;
    Node *root = constructTree(pre, in, n, i, 0, n - 1, mp);
    return root;
}