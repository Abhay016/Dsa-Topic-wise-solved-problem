
#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    vector<int> res;
    vector<int> adj[nodes];
    for(int i=0; i<edges; i++)
    {
        adj[graph[i][0]].push_back(graph[i][1]);
    }
    vector<int> indegree(nodes);
    for(int i=0; i<nodes; i++)
    {
        for(auto j: adj[i])
        {
            indegree[j]++;
        }
    }
    queue<int> q;
    for(int i=0; i<nodes; i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        res.push_back(node);
        for(auto j: adj[node])
        {
            indegree[j]--;
            if (indegree[j] == 0) {
              q.push(j);
            }
        }
    }
    return res;
}
