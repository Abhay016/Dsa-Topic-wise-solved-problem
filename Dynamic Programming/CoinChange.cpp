/*   Minimum cost climbing stairs*/

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

/*THROUGH RECURSION*/
int solve(vector<int> coins, int amount)
{
    if (amount == 0)
        return 0;
    if (amount < 0)
        return INT_MAX;
    int res = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        int val = solve(coins, amount - coins[i]);
        if (val != INT_MAX)
            res = min(res, 1 + val);
    }
    return res;
}

/*USING DYNAMIC PROGRAMMING(MEMOIZATION)*/
int solve_memo(vector<int> coins, int amount, vector<int> &dp)
{
    if (amount == 0)
        return 1;
    if (amount < 0)
        return INT_MAX;
    if (dp[amount] != -1)
        return dp[amount];
    int res = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        int val = solve(coins, amount - coins[i]);
        if (val != INT_MAX)
            res = min(res, 1 + val);
    }
    dp[amount] = res;
    return dp[amount];
}

/*USING DP(TABULATION)*/
int solve_tab(vector<int> coins, int amount)
{
    vector<int> dp(amount + 1, -1);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < coins.size(); j++)
        {
            if (i >= coins[j] && dp[i - coins[j]] != INT_MAX)
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
        }
    }
    return dp[amount];
}

int coinChange(vector<int> &coins, int amount)
{
    int res = solve(coins, amount);
    if (res == INT_MAX)
        return -1;
    else
        return res;
}

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount=11;
    cout << coinChange(coins, amount);
}