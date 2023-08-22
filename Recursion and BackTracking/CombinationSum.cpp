
#include <bits/stdc++.h> 
using namespace std;

void combination(vector<int> candidates, int target, int i, vector<vector<int>> &res, vector<int> temp)
{
    if (i == candidates.size())
    {
        if (target == 0)
        {
            res.push_back(temp);
        }
        return;
    }
    if (target < 0)
    {
        return;
    }
    temp.push_back(candidates[i]);
    combination(candidates, target - candidates[i], i, res, temp);
    temp.pop_back();
    combination(candidates, target, i + 1, res, temp);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> res;
    vector<int> temp;
    combination(candidates, target, 0, res, temp);
    return res;
}

int main()
{
    vector<int> nums={2,3,6,7};
    int target=7;
    vector<vector<int>> res=combinationSum(nums, target);
    for(int i=0; i<res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}