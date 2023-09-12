
#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> &nums, int size)
{
    if(size==0)
    return;
    bool flag=false;
    for (int j = 0; j < size; j++)
    {
        if(nums[j]>nums[j+1])
        {
            swap(nums[j], nums[j+1]);
            flag=true;
        }
    }
    if(flag==0)
    return;
    solve(nums, size-1);    
}
int main()
{
    vector<int> nums={12, 45, 23, 51, 19, 8};
    solve(nums, nums.size()-1);
    for (int i = 0; i < nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }
    
}