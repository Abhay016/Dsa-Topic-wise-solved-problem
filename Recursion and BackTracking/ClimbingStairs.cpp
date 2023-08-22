
/* Climbing Stairs   */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int recursion(int n, vector<int> &dp)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = recursion(n - 1, dp) + recursion(n - 2, dp);
    return dp[n];
}
int climbStairs(int n)
{
    vector<int> dp(n + 1, -1);
    return recursion(n, dp);
}

int main()
{
    cout << climbStairs(40);
}