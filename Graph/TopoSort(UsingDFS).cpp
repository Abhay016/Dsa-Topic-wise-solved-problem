
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], vector<int> &vis, vector<int> &res, int node)
{
    vis[node] = 1;
    for (auto i : adj[node])
    {
        if (!vis[i])
        {
            dfs(adj, vis, res, i);
        }
    }
    res.push_back(node);
}
vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    vector<int> vis(nodes);
    vector<int> res;
    vector<int> adj[nodes];
    for(int i=0; i<edges; i++)
    {
        adj[graph[i][0]].push_back(graph[i][1]);
    }
    for(int i=0; i<nodes; i++)
    {
        if(!vis[i])
        dfs(adj, vis, res, i);
    }
    reverse(res.begin(), res.end());
    return res;
}
