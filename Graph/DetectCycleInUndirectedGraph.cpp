
#include <bits/stdc++.h>
using namespace std;

/*  Using Breadth First Search  */
class Graph
{

public:
    bool bfs(vector<int> adj[], vector<int> &vis, int i)
    {
        queue<pair<int, int>> q;
        q.push({i, -1});
        vis[i] = 1;
        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for (auto i : adj[node])
            {
                if (!vis[i])
                {
                    q.push({i, node});
                    vis[i] = 1;
                }
                else if (parent != i)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool detectCycle(int V, vector<int> adj[])
    {
        vector<int> vis(V);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                if (bfs(adj, vis, i))
                    return true;
        }
        return false;
    }
};

/*  Using Depth First Search  */
class Graph
{

public:
    bool dfs(vector<int> adj[], vector<int> &vis, int i, int parent)
    {
        vis[i] = 1;
        for (auto j : adj[i])
        {
            if (!vis[j])
            {
                if (dfs(adj, vis, j, i))
                    return true;
            }
            else if (parent != j)
            {
                return true;
            }
        }
        return false;
    }
    bool detectCycle(int V, vector<int> adj[])
    {
        vector<int> vis(V);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                if (dfs(adj, vis, i, -1))
                    return true;
        }
        return false;
    }
};