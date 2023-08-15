
/*   Buy Time to Buy and sell stock   */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int maxProfit(vector<int> &arr)
{
    int buy = arr[0], profit = 0;
    int i = 1;
    while (i < arr.size())
    {
        profit = max(profit, arr[i] - buy);
        buy = min(buy, arr[i]);
        i++;
    }
    return profit;
}

int main()
{
    vector<int>  arr={7,1,5,3,6,4};
    cout<<maxProfit(arr);
}