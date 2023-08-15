
/*   kadane's Algorithm   */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int sum = nums[0], ans = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        sum = max(nums[i], sum + nums[i]);
        ans = max(sum, ans);
    }
    return ans;
}

int main()
{
    vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArray(nums);
}