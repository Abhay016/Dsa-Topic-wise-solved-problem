
#include <bits/stdc++.h>
using namespace std;

// using recursion
void dfs(vector<int> adj[], vector<int> &vis, vector<int> &res, int i)
{
    res.push_back(i);
    vis[i] = 1;
    for (auto j : adj[i])
    {
        if (!vis[j])
        {
            dfs(adj, vis, res, j);
        }
    }
}
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<int> vis(V);
    vector<int> res;
    dfs(adj, vis, res, 0);
    return res;
}


// using stack
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    stack<int> s;
    vector<int> res;
    vector<int> vis(V);
    s.push(0);
    res.push_back(0);
    vis[0] = 1;
    while (!s.empty())
    {
        int temp = s.top();
        int flag = 0;
        for (auto j : adj[temp])
        {
            if (!vis[j])
            {
                s.push(j);
                res.push_back(j);
                vis[j] = 1;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            s.pop();
    }
    return res;
}