
/*   Product of Array Except Self   */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
{
    if (n == 1)
    {
        return {1};
    }
    long long int left[n];
    long long int right[n];
    long long int prod = 1;
    for (int i = 0; i < n; i++)
    {
        prod *= nums[i];
        left[i] = prod;
    }
    prod = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        prod *= nums[i];
        right[i] = prod;
    }
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            nums[i] = right[i + 1];
        }
        else if (i == (n - 1))
        {
            nums[i] = left[i - 1];
        }
        else
        {
            nums[i] = left[i - 1] * right[i + 1];
        }
    }
    return nums;
}

int main()
{
    vector<long long int> nums={10,3,5,6,2};
    vector<long long int> ans=productExceptSelf(nums, nums.size());
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
}