#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

void solve(vector<vector<int>> &res, vector<int> temp, int i, int k, int n)
{
    if(n<0 && temp.size()>k)
    {
        return;
    }
    if (temp.size() == k)
    {
        if (n == 0)
        {
            res.push_back(temp);
        }
        return;
    }
    for (int j = i+1; j <= 9; j++)
    {
        temp.push_back(j);
        n-=j;
        solve(res, temp, j, k, n);
        n+=j;
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> res;
    vector<int> temp;
    solve(res, temp, 0, k, n);
    return res;
}

int main()
{
    vector<vector<int>> res=combinationSum3(3, 9);
    for(int i=0; i<res.size(); i++)
    {
        for(int j=0; j<res[i].size(); j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}