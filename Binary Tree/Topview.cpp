
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

vector<int> topView(Node *root)
{
    vector<int> res;
    map<int, int> mp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        pair<Node *, int> p = q.front();
        q.pop();
        int h = p.second;
        Node *temp = p.first;
        if (mp.find(h) == mp.end())
            mp[h] = temp->data;
        if (temp->left)
            q.push({temp->left, h - 1});
        if (temp->right)
            q.push({temp->right, h + 1});
    }
    for (auto i : mp)
    {
        res.push_back(i.second);
    }
    return res;
}