
#include <bits/stdc++.h>
using namespace std;

void solve(int n, int i, int j, vector<string> &res, string temp)
{
    if (temp.size() == (2 * n))
    {
        res.push_back(temp);
        return;
    }
    if (i < n)
    {
        temp.push_back('(');
        solve(n, i + 1, j, res, temp);
        temp.pop_back();
    }
    if (j < i)
    {
        temp.push_back(')');
        solve(n, i, j + 1, res, temp);
        temp.pop_back();
    }
}
vector<string> generateParenthesis(int n)
{
    vector<string> res;
    solve(n, 0, 0, res, "");
    return res;
}

int main()
{
    vector<string> res=generateParenthesis(2);
    for(int i=0; i<res.size(); i++)
    {
        cout<<res[i]<<" ";
    }
}