
/*   Find the Duplicate Number   */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int findDuplicate(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int index = abs(nums[i]);
        if (nums[index] < 0)
        {
            return index;
        }
        else
        {
            nums[index] = -nums[index];
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {1, 3, 4, 2, 2};
    cout<<findDuplicate(nums);   
}