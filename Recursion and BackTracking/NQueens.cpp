
#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> board, int n, int r, int c)
{
    int i=r, j=c;
    while(j>=0)
    {
        if(board[i][j])
        {
            return false;
        }
        j--;
    }
    i=r, j=c;
    while(i>=0 && j>=0)
    {
        if(board[i][j])
        {
            return false;
        }
        i--;
        j--;
    }
    i=r, j=c;
    while(j>=0 && i<n)
    {
        if(board[i][j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void solve(vector<vector<int>> &board, int n, int c, vector<vector<int>>& res)
{
    if(c==n)
    {
        vector<int> temp;
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[i].size(); j++)
            {
                temp.push_back(board[i][j]);
            }
        }
        res.push_back(temp);
        return;
    }
    for(int r=0; r<n; r++)
    {
        if(isSafe(board, n, r, c))
        {
            board[r][c]=1;
            solve(board, n, c+1, res);
            board[r][c]=0;
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<vector<int>> board(n, vector<int> (n, 0));
    vector<vector<int>> res;
    solve(board, n, 0, res);
    sort(res.begin(), res.end());
    return res;
}

int main()
{
    vector<vector<int>> board=solveNQueens(4);
    for(int i=0; i<board.size(); i++)
    {
        for(int j=0; j<board[i].size(); j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}