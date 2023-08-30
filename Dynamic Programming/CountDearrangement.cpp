/*   Minimum cost climbing stairs*/

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

/*THROUGH RECURSION*/
int solve(int n)
{
    if(n==1 || n==2)
    return n-1;
    int res=(n-1)*((solve(n-2)%MOD) + (solve(n-1)%MOD));   
}

/*USING DP(TABULATION)*/
long long solve_tab(int n)
{
    vector<long long> dp(n+1, 0);
    dp[1]=0;
    dp[2]=1;
    for(int i=3; i<=n; i++)
    {
        dp[i]=((i-1)*(((dp[i-2]%MOD) + (dp[i-1]%MOD))%MOD))%MOD;
    }
    return dp[n];
}

/*USING DP(SPACE OPTIMISATION)*/
int solve_space(int n)
{
    long long first=0;
    long long second=1;
    for(int i=3; i<=n; i++)
    {
        long long res=((i-1)*(((first%MOD)+(second%MOD))%MOD))%MOD;
        first=second;
        second=res;
    }
    return second;
}

long long int countDerangements(int n) {
    return solve_space(n);
}

int main()
{
    cout<<countDerangements(4);
}