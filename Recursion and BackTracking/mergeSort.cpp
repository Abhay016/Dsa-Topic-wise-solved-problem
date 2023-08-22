
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

void merge(vector<int> &nums, int s, int mid, int e)
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
    for (int i = s; i <= e; i++)
    {
        nums[i] = temp[i - s];
    }
}
void sort(vector<int> &nums, int s, int e)
{
    if (s >= e)
        return;
    int mid = (s + (e - s) / 2);
    sort(nums, s, mid);
    sort(nums, mid + 1, e);
    merge(nums, s, mid, e);
}

void sortArray(vector<int> &nums)
{
    sort(nums, 0, nums.size() - 1);
}

int main()
{
    vector<int> nums = {3, 5, 6, 2, 1, 5, 7, 3, 6, 8, 9};
    sortArray(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }
    
}