
/*   Search in rotated Sorted Array   */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int search(vector<int> &arr, int target)
{
    int s = 0;
    int e = arr.size() - 1;
    while (s <= e)
    {
        int mid = (s + (e - s) / 2);
        if (arr[mid] == target)
            return mid;
        else if (arr[s] <= arr[mid])
        {
            if (arr[s] <= target && target <= arr[mid])
                e = mid - 1;
            else
                s = mid + 1;
        }
        else if (arr[s] > arr[mid])
        {
            if (arr[mid] <= target && target <= arr[e])
                s = mid + 1;
            else
                e = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    cout<<search(nums, target);
}