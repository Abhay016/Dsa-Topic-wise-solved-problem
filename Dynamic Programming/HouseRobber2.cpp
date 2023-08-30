/*   Minimum cost climbing stairs*/

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

/*THROUGH RECURSION*/
int solve(vector<int> nums, int i)
{
    if (i == nums.size() - 1)
    {
        return nums[i];
    }
    if (i >= nums.size())
    {
        return 0;
    }
    int left = solve(nums, i + 2) + nums[i];
    int right = solve(nums, i + 1);
    return max(left, right);
}

/*USING DP(TABULATION)*/
int solve_tab(vector<int> nums)
{
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    int left = INT_MIN, right = INT_MIN;
    for (int i = 1; i < nums.size(); i++)
    {
        if (i == 1)
            left = nums[i];
        else
            left = dp[i - 2] + nums[i];
        right = dp[i - 1];
        dp[i] = max(left, right);
    }
    return dp[nums.size() - 1];
}

/*USING DP(SPACE OPTIMISATION)*/
int solve_space(vector<int> nums)
{
    int first = 0, second = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        int res = max(first + nums[i], second);
        first = second;
        second = res;
    }
    return second;
}

int rob(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];
    vector<int> vec1(nums.begin(), nums.end() - 1);
    vector<int> vec2(nums.begin() + 1, nums.end());
    return max(solve_space(vec1), solve_space(vec2));
}

int main()
{
    vector<int> nums = {2, 3, 2};
    cout << rob(nums);
}