
#include <bits/stdc++.h>
using namespace std;

void combination(vector<int> candidates, int target, int idx, vector<int> temp, vector<vector<int>> &res)
{
    if (target == 0)
    {
        res.push_back(temp);
        return;
    }
    for (int i = idx; i < candidates.size(); i++)
    {
        if (i > idx && candidates[i - 1] == candidates[i])
        {
            continue;
        }
        else if (target < candidates[i])
        {
            return;
        }
        else
        {
            temp.push_back(candidates[i]);
            combination(candidates, target - candidates[i], i + 1, temp, res);
            temp.pop_back();
        }
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<vector<int>> res;
    vector<int> temp;
    sort(candidates.begin(), candidates.end());
    combination(candidates, target, 0, temp, res);
    return res;
}

int main()
{
    vector<int> nums={10,1,2,7,6,1,5};
    int target=8;
    vector<vector<int>> res=combinationSum2(nums, target);
    for(int i=0; i<res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}