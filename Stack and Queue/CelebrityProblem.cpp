
#include <bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int>> &M, int n)
{
    // code here
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }
    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if (M[a][b] == 0)
        {
            s.push(a);
        }
        else if (M[b][a] == 0)
        {
            s.push(b);
        }
    }
    if (s.empty())
        return -1;
    int c = s.top();
    for (int i = 0; i < n; i++)
    {
        if (M[c][i] != 0)
            return -1;
    }
    for (int j = 0; j < n; j++)
    {
        if (c == j)
        {
            continue;
        }
        if (M[j][c] != 1)
        {
            return -1;
        }
    }
    return c;
}

int main()
{
    vector<vector<int>> arr={{0,1,0},{0,0,0},{0,1,0}};
    cout<<celebrity(arr, arr.size());
}