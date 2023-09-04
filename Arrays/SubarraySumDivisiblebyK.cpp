
#include <bits/stdc++.h>
using namespace std;

int subarraysDivByK(vector<int> &nums, int k)
{
    int res = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        int rem = sum % k;
        if (rem >= 0)
        {
            res += mp[rem];
            mp[rem]++;
        }
        else
        {
            res += mp[rem + k];
            mp[rem + k]++;
        }
    }
    return res;
}

int main()
{
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;
    cout << subarraysDivByK(nums, k);
}