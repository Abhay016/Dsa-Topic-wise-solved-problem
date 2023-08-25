
#include <bits/stdc++.h>
using namespace std;

long long sumOfMaxAndMin(vector<int> &nums, int n, int k)
{
    long long ans = 0;
    deque<int> mini;
    deque<int> maxi;
    for (int i = 0; i < k; i++)
    {
        while (!mini.empty() && nums[i] <= nums[mini.back()])
        {
            mini.pop_back();
        }
        while (!maxi.empty() && nums[i] >= nums[maxi.back()])
        {
            maxi.pop_back();
        }
        mini.push_back(i);
        maxi.push_back(i);
    }
    ans += nums[mini.front()] + nums[maxi.front()];
    for (int i = k; i < n; i++)
    {
        while (!mini.empty() && i - mini.front() >= k)
        {
            mini.pop_front();
        }
        while (!maxi.empty() && i - maxi.front() >= k)
        {
            maxi.pop_front();
        }
        while (!mini.empty() && nums[i] <= nums[mini.back()])
        {
            mini.pop_back();
        }
        while (!maxi.empty() && nums[i] >= nums[maxi.back()])
        {
            maxi.pop_back();
        }
        mini.push_back(i);
        maxi.push_back(i);
        ans += nums[mini.front()] + nums[maxi.front()];
    }
    return ans;
}

int main()
{
    vector<int> nums={1,2,3,4,5};
    cout<<sumOfMaxAndMin(nums, nums.size(), 3);
}