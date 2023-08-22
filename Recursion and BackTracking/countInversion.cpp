
#include <bits/stdc++.h>
using namespace std;

void merge(long long* &nums, int s, int mid, int e, long long& count)
{
    vector<int> temp;
    int i = s;
    int j = mid+1;
    while (i <= mid && j <= e)
    {
        if (nums[i] < nums[j])
        {
            temp.push_back(nums[i++]);
        }
        else if (nums[i] > nums[j])
        {
            temp.push_back(nums[j++]);
            count+=(mid-i+1);
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
    for(int i=s; i<=e; i++)
    {
        nums[i]=temp[i-s];
    }
}

void sort(long long* &nums, int s, int e, long long& count)
{
        if(s>=e)
        return;
        int mid=(s+(e-s)/2);
        sort(nums, s, mid, count);
        sort(nums, mid+1, e, count);
        merge(nums, s, mid, e, count);
}

long long getInversions(long long *arr, int n){
    long long count=0;
    sort(arr, 0, n-1, count);
    return count;
}

int main()
{
    long long arr[]={2,5,1,3,4};
    cout<<getInversions(arr, 5);
}