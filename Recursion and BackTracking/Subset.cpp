
#include <bits/stdc++.h>
using namespace std;

void subsequence(vector<int> &nums, vector<vector<int>> &res, int i, vector<int> temp)
{
    if (i == nums.size())
    {
        res.push_back(temp);
        return;
    }
    subsequence(nums, res, i + 1, temp);
    temp.push_back(nums[i]);
    subsequence(nums, res, i + 1, temp);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<int> temp;
    subsequence(nums, res, 0, temp);
    return res;
}

int main()
{
    vector<int> nums={1,2,3};
    vector<vector<int>> res=subsets(nums);
    for(int i=0; i<res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}