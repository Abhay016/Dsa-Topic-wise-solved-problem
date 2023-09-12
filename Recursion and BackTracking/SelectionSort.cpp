
#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& nums, int i)
{
    if(i==nums.size()-1)
    return;
    int minIndex=i;
    for(int j=i+1; j<nums.size(); j++)
    {
        if(nums[j]<nums[minIndex])
        {
            minIndex=j;
        }
    }
    swap(nums[i], nums[minIndex]);
    solve(nums, i+1);
}
int main()
{
    vector<int> nums={12, 45, 23, 51, 19, 8};
    solve(nums, 0);
    for (int i = 0; i < nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }
    
}