
#include <bits/stdc++.h>
using namespace std;

void mergeArray(vector<int> &nums, int s, int mid, int e, int &count)
{
    vector<int> temp;
    int i = s;
    int j = mid + 1;
    while (i <= mid && j <= e)
    {
        if (nums[i] < nums[j])
        {
            temp.push_back(nums[i++]);
        }
        else if (nums[i] > nums[j])
        {
            temp.push_back(nums[j++]);
        }
        else
        {
            temp.push_back(nums[i++]);
            temp.push_back(nums[j++]);
        }
    }
    while (i <= mid)
    {
        temp.push_back(nums[i++]);
    }
    while (j <= e)
    {
        temp.push_back(nums[j++]);
    }
    i = s;
    j = mid + 1;
    for (int i = s; i <= mid; i++)
    {
        while (j <= e && 1ll * nums[i] > 2LL * nums[j])
            j++;
        count += (j - (mid + 1));
    }
    for (int i = s; i <= e; i++)
    {
        nums[i] = temp[i - s];
    }
}

void mergeSort(vector<int> &nums, int s, int e, int &count)
{
    if (s >= e)
    {
        return;
    }
    int mid = (s + (e - s) / 2);
    mergeSort(nums, s, mid, count);
    mergeSort(nums, mid + 1, e, count);
    mergeArray(nums, s, mid, e, count);
}

int reversePairs(vector<int> &nums)
{
    int count = 0;
    mergeSort(nums, 0, nums.size() - 1, count);
    return count;
}

int main()
{
    vector<int> nums={1,3,2,3,1};
    cout<<reversePairs(nums);
}