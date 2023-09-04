
#include <bits/stdc++.h>
using namespace std;

bool solve(vector<vector<char>> &board, string &word, int i, int j, int k, int m, int n)
{
    if (k == word.length())
    {
        return true;
    }
    if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[k])
    {
        return false;
    }
    char ch = board[i][j];
    board[i][j] = '.';
    bool a = solve(board, word, i, j + 1, k + 1, m, n) || solve(board, word, i + 1, j, k + 1, m, n) || solve(board, word, i, j - 1, k + 1, m, n) || solve(board, word, i - 1, j, k + 1, m, n);
    board[i][j] = ch;
    return a;
}
bool exist(vector<vector<char>> &board, string word)
{
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == word[0])
            {
                if (solve(board, word, i, j, 0, m, n))
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> board = {{'o', 'k', 'f', 'y', 'g'},
                                  {'l', 'v', 's', 'a', 'h'},
                                  {'a', 'f', 'y', 'b', 'q'},
                                  {'a', 'e', 'm', 'u', 'b'},
                                  {'m', 'n', 'x', 'l', 'h'},
                                  {'h', 'd', 'x', 'h', 'x'}};
    string word = "umxlhxhbqbysfygha";
    cout << exist(board, word);
}
