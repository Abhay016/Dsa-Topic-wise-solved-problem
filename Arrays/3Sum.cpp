
/*   return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.   */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    set<vector<int>> s;
    sort(nums.begin(), nums.end());
    int j, k;
    for (int i = 0; i < nums.size() - 2; i++)
    {
        int temp = nums[i];
        j = i + 1;
        k = nums.size() - 1;
        while (j < k)
        {
            if ((nums[j] + nums[k] + temp) == 0)
            {
                s.insert({temp, nums[j], nums[k]});
                j++;
                k--;
            }
            else if ((nums[j] + nums[k] + temp) > 0)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }
    for (auto &itr : s)
    {
        ans.push_back(itr);
    }
    return ans;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = threeSum(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}