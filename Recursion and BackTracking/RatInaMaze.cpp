
#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> m, int n, int i, int j, vector<vector<int>> &res, vector<vector<int>> v)
{
    if (i == n - 1 && j == n - 1)
    {
        v[n - 1][n - 1] = 1;
        vector<int> temp;
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v[i].size(); j++)
            {
                temp.push_back(v[i][j]);
            }
        }
        res.push_back(temp);
        return;
    }
    if (j + 1 < n && !v[i][j + 1] && m[i][j + 1])
    {
        v[i][j] = 1;
        solve(m, n, i, j + 1, res, v);
        v[i][j] = 0;
    }
    if (i + 1 < n && !v[i + 1][j] && m[i + 1][j])
    {
        v[i][j] = 1;
        solve(m, n, i + 1, j, res, v);
        v[i][j] = 0;
    }
    if (j - 1 >= 0 && !v[i][j - 1] && m[i][j - 1])
    {
        v[i][j] = 1;
        solve(m, n, i, j - 1, res, v);
        v[i][j] = 0;
    }
    if (i - 1 >= 0 && !v[i - 1][j] && m[i - 1][j])
    {
        v[i][j] = 1;
        solve(m, n, i - 1, j, res, v);
        v[i][j] = 0;
    }
}
vector<vector<int>> ratInAMaze(vector<vector<int>> &maze, int n)
{
    vector<vector<int>> v(n, vector<int>(n, 0));
    vector<vector<int>> res;
    solve(maze, n, 0, 0, res, v);
    return res;
}

int main()
{
    vector<vector<int>> maze={{1,0,1},{1,1,1},{1,1,1}};
    vector<vector<int>> res=ratInAMaze(maze, maze.size());
    for(int i=0; i<res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}