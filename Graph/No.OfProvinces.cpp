
#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[], vector<int> &vis, int i)
{
    queue<int> q;
    q.push(i);
    vis[i] = 1;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (auto j : adj[temp])
        {
            if (!vis[j])
            {
                q.push(j);
                vis[j] = 1;
            }
        }
    }
}

int findNumOfProvinces(vector<vector<int>> &roads, int n)
{
    vector<int> adj[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (roads[i][j])
                adj[i].push_back(j);
        }
    }
    vector<int> vis(n);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            bfs(adj, vis, i);
            res++;
        }
    }
    return res;
}