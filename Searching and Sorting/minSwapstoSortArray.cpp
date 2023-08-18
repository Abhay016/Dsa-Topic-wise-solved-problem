
/*   Minimum number of swaps to sort an array   */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int minSwaps(vector<int> &nums)
{
    vector<pair<int, int>> vec;
    for (int i = 0; i < nums.size(); i++)
    {
        vec.push_back({nums[i], i});
    }
    sort(vec.begin(), vec.end());
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        pair<int, int> p = vec[i];
        if (i != (p.second))
        {
            count++;
            swap(vec[i], vec[p.second]);
            i--;
        }
    }
    return count;
}

int main()
{
    vector<int> nums={10, 19, 6, 3, 5};
    cout<<minSwaps(nums);
}