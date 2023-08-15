
/*   Minimum days to make M bouquets   */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

bool func(vector<int> bloomDay, int m, int k, int mid)
{
    int count = 0, subcount = 0;
    for (int i = 0; i < bloomDay.size(); i++)
    {
        if (bloomDay[i] <= mid)
        {
            subcount++;
        }
        else if (bloomDay[i] > mid)
        {
            subcount = 0;
        }
        if (subcount == k)
        {
            count++;
            subcount = 0;
        }
        if (count == m)
        {
            return true;
        }
    }
    return false;
}
int minDays(vector<int> &bloomDay, int m, int k)
{
    int maxVal = INT_MIN;
    int minVal = INT_MAX;
    for (int i = 0; i < bloomDay.size(); i++)
    {
        maxVal = max(maxVal, bloomDay[i]);
        minVal = min(minVal, bloomDay[i]);
    }
    int i = minVal;
    int j = maxVal;
    int ans = -1;
    while (i <= j)
    {
        int mid = (i + (j - i) / 2);
        if (func(bloomDay, m, k, mid))
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
    vector<int> arr = {1, 10, 3, 10, 2};
    int m = 3, k = 1;
    cout << minDays(arr, m, k);
}