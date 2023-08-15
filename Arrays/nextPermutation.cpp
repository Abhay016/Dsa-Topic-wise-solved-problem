
/*   Next Permutation   */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i=n-2;
        while(i>=0)
        {
            if(nums[i+1]>nums[i])
            {
                break;
            }
            i--;
        }
        if(i==-1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        for(int j=n-1; j>i; j--)
        {
            if(nums[i]<nums[j])
            {
                swap(nums[i], nums[j]);
                break;
            }
        }
        reverse(nums.begin()+(i+1), nums.end());
    }

    int main()
    {
        vector<int> nums={1,1,5};
        nextPermutation(nums);
        for(int i=0; i<nums.size(); i++)
        {
            cout<<nums[i]<<" ";
        }
    }