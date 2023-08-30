

/*   Buy Time to Buy and sell stock 2  */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int maxProfit(vector<int> &prices)
{
    int res = 0;
    for (int i = 0; i < prices.size() - 1; i++)
    {
        int profit = prices[i + 1] - prices[i];
        if (profit > 0)
            res += profit;
    }
    return res;
}

int main()
{
    vector<int> arr = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(arr);
    cout<<(-3%2);
}
