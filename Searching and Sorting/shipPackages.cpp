
/*   Capacity to Ship Packages within D Days   */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int func(vector<int> nums, int k, int mid)
{
    int sum = 0;
    int count = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        
        if(sum + nums[i] <= mid)
        sum += nums[i];
        else
        {
            count++;
            sum = nums[i];
        }
    }
    return count;
}
int shipWithinDays(vector<int> &weights, int days)
{
    int i = INT_MIN;
    int j = 0;
    for (int k = 0; k < weights.size(); k++)
    {
        i = max(i, weights[k]);
        j += weights[k];
    }
    cout<<i<<" "<<j<<endl;
    int ans = -1;
    while (i <= j)
    {
        int mid = (i + (j - i) / 2);
        if (func(weights, days, mid)<=days)
        {
            ans = mid;
            j = mid - 1;
        }
        else
        {
            i = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;
    cout << shipWithinDays(arr, days);
}