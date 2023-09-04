
#include <bits/stdc++.h>
using namespace std;

/*THROUGH RECURSION*/
int solve(vector<int> days, vector<int> cost, int i, int n)
{
    if(i>=n)
    {
        return 0;
    }
    int x=cost[0]+solve(days, cost, i+1, n);
    int j=i;
    for(j=i; j<n && days[j]<days[i]+7; j++);
    int y=cost[1]+solve(days, cost, j, n);
    for(j=i; j<n && days[j]<days[i]+30; j++);
    int z=cost[2]+solve(days, cost, j, n);
    return min(x, min(y, z));
}

/*USING DYNAMIC PROGRAMMING(MEMOIZATION)*/
int solve_mem(vector<int> days, vector<int> cost, int i, int n, vector<int> &dp)
{
    if(i>=n)
    {
        return 0;
    }
    if(dp[i]!=-1)
    return dp[i];
    int x=cost[0]+solve_mem(days, cost, i+1, n, dp);
    int j=i;
    for(j=i; j<n && days[j]<days[i]+7; j++);
    int y=cost[1]+solve_mem(days, cost, j, n, dp);
    for(j=i; j<n && days[j]<days[i]+30; j++);
    int z=cost[2]+solve_mem(days, cost, j, n, dp);
    dp[i]=min(x, min(y, z));
    return dp[i];
}

/*USING DP(TABULATION)*/
int solve_tab(vector<int> days, vector<int> cost, int n)
{
    vector<int> dp(n+1, INT_MAX);
    dp[n]=0;
    for(int i=n-1; i>=0; i--)
    {
        int x=cost[0]+dp[i+1];
        int j=i;
        for(j=i; j<n && days[j]<days[i]+7; j++);
        int y=cost[1]+dp[j];
        for(j=i; j<n && days[j]<days[i]+30; j++);
        int z=cost[2]+dp[j];
        dp[i]=min(x, min(y,z));
    }
    return dp[0];
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // return solve(days, cost, 0, n);

    // vector<int> dp(n+1, -1);
    // return solve(days, cost, 0, n, dp);

    solve_tab(days, cost, n);

}