
/*   Maximum Product Subarray   */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long maxProduct(vector<int> arr, int n)
{
    // code here
    long long int prod = 1, maxProd = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        prod *= arr[i];
        maxProd = max(prod, maxProd);
        if (prod == 0)
        {
            prod = 1;
        }
    }
    prod = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        prod *= arr[i];
        maxProd = max(prod, maxProd);
        if (prod == 0)
        {
            prod = 1;
        }
    }
    return maxProd;
}

int main()
{
    vector<int> nums={6,-3,-10,0,2};
    cout<<maxProduct(nums, nums.size());
}