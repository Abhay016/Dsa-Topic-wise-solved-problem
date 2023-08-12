
/*   Minimum cost climbing stairs*/

#include <bits/stdc++.h>
#define MOD 1000000007 
using namespace std;

/*THROUGH RECURSION*/
int recursion(int n, vector<int> cost)
{
    if(n==0 || n==1)
    {
        return cost[n];
    }
    int left=recursion(n-1, cost);
    int right=recursion(n-2, cost);
    return cost[n] + min(left, right);
}

/*USING DYNAMIC PROGRAMMING(MEMOIZATION)*/
int dp_memo(int n, vector<int> cost, vector<int> &dp)
{
    if(n==0 || n==1)
    {
        return cost[n];
    }
    if(dp[n]!=-1)
    return dp[n];
    dp[n]=cost[n]+min(dp_memo(n-1, cost, dp),dp_memo(n-2, cost, dp));
    return dp[n];
}

/*USING DP(TABULATION)*/
int dp_tabu(int n, vector<int> cost)
{
    vector<int> dp(n+1, -1);
    dp[0]=cost[0];
    dp[1]=cost[1];
    for (int i = 2; i < n; i++)
    {
        dp[i]=cost[i]+min(dp[i-1], dp[i-2]);
    }
    return min(dp[n-1], dp[n-2]);
}

/*USING DP(SPACE OPTIMISATION)*/
int dp_space(int n, vector<int> cost)
{
    int first=cost[0];
    int second=cost[1];
    for (int i = 2; i < n; i++)
    {
        int curr=cost[i]+min(first, second);
        first=second;
        second=curr;
    }
    return min(first, second);
}

int minCostClimbingStairs(vector<int>& cost) 
{
    int n=cost.size();

    // return min(recursion(n-1, cost), recursion(n-2, cost));

    // vector<int> dp(n+1, -1);
    // return min(dp_memo(n-1, cost, dp), dp_memo(n-2, cost, dp));

    /*USING DP(TABULATION)*/
    // return dp_tabu(n, cost);

    return dp_space(n, cost);
}

int main()
{
    vector<int> cost={10,15,20};
    cout<<minCostClimbingStairs(cost);
}