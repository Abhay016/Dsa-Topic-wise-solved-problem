
/*   Spiral traversal of a matrix   */

#include <bits/stdc++.h>
using namespace std;

vector<int> spiralPathMatrix(vector<vector<int>> matrix, int n, int m)
{
    // Write your code here.
    vector<int> vec;
    int count = 0, total = n * m;
    if (n == 1 || m == 1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                vec.push_back(matrix[i][j]);
            }
        }
    }
    else
    {
        int row_start = 0, row_end = n - 1, column_start = 0, column_end = m - 1;
        while (count < total)
        {
            for (int i = column_start; i <= column_end; i++)
            {
                vec.push_back(matrix[row_start][i]);
                count++;
            }
            row_start++;
            if (count < total)
            {
                for (int j = row_start; j <= row_end; j++)
                {
                    vec.push_back(matrix[j][column_end]);
                    count++;
                }
                column_end--;
            }
            else
                break;
            if (count < total)
            {
                for (int i = column_end; i >= column_start; i--)
                {
                    vec.push_back(matrix[row_end][i]);
                    count++;
                }
                row_end--;
            }
            else
                break;
            if (count < total)
            {
                for (int j = row_end; j >= row_start; j--)
                {
                    vec.push_back(matrix[j][column_start]);
                    count++;
                }
                column_start++;
            }
            else
                break;
        }
    }

    return vec;
}
int main()
{
    vector<vector<int>> mat = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    vector<int> res= spiralPathMatrix(mat, mat.size(), mat[0].size());
    for (int i = 0; i < res.size(); i++)
    {
       cout<<res[i]<<" ";
    }
}