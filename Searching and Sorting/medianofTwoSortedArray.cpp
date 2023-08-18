
/*   Median of Two Sorted array of different sizes   */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    if (n1 > n2)
        return findMedianSortedArrays(nums2, nums1);
    int s = 0, e = n1;
    while (s <= e)
    {
        int mid1 = s + (e - s) / 2;
        int mid2 = ((n1 + n2 + 1) / 2) - mid1;
        int left1 = INT_MIN, left2 = INT_MIN;
        int right1 = INT_MAX, right2 = INT_MAX;
        if (mid1 >= 1)
        {
            left1 = nums1[mid1 - 1];
        }
        if (mid2 >= 1)
        {
            left2 = nums2[mid2 - 1];
        }
        if (mid1 < n1)
        {
            right1 = nums1[mid1];
        }
        if (mid2 < n2)
        {
            right2 = nums2[mid2];
        }
        if (left1 <= right2 && left2 <= right1)
        {
            if ((n1 + n2) % 2 == 0)
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            else
                return max(left1, left2);
        }
        else if (left1 > right2)
        {
            e = mid1 - 1;
        }
        else
        {
            s = mid1 + 1;
        }
    }
    return 0;
}

int main()
{
    vector<int> nums1={2,4,6};
    vector<int> nums2={1,3,5};
    cout<<findMedianSortedArrays(nums1, nums2);
}