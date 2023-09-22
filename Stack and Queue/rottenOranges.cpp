
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> vis(m, vector<int>(n, -1));
    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({i, j});
                vis[i][j] = 2;
            }
            if (grid[i][j] == 0)
            {
                vis[i][j] = 0;
            }
        }
    }
    int time = 0;
    while (!q.empty())
    {
        int size = q.size();
        int flag = 0;
        for (int i = 0; i < size; i++)
        {
            int row = q.front().first;
            int col = q.front().second;
            if (row > 0 && grid[row - 1][col] == 1 && vis[row - 1][col] == -1)
            {
                vis[row - 1][col] = 2;
                q.push({row - 1, col});
                flag = 1;
            }
            if (row < m - 1 && grid[row + 1][col] == 1 && vis[row + 1][col] == -1)
            {

                vis[row + 1][col] = 2;
                q.push({row + 1, col});
                flag = 1;
            }
            if (col > 0 && grid[row][col - 1] == 1 && vis[row][col - 1] == -1)
            {
                vis[row][col - 1] = 2;
                q.push({row, col - 1});
                flag = 1;
            }
            if (col < n - 1 && grid[row][col + 1] == 1 && vis[row][col + 1] == -1)
            {
                vis[row][col + 1] = 2;
                q.push({row, col + 1});
                flag = 1;
            }
            q.pop();
        }
        if (flag == 1)
            time++;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis[i][j] == -1)
                return -1;
        }
    }
    return time;
}