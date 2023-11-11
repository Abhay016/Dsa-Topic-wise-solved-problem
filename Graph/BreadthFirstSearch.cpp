
#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    vector<int> vis(V);
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    vector<int> res;
    while (!q.empty())
    {
        int temp = q.front();
        res.push_back(temp);
        q.pop();
        for (auto i : adj[temp])
        {
            if (!vis[i])
            {
                q.push(i);
                vis[i] = 1;
            }
        }
    }
    return res;
}