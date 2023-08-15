
/*   Longest Consectuive sequence   */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int longestConsecutive(vector<int>& nums) {
    int maxlen=0;
    unordered_set<int> s;
    for(int i=0; i<nums.size(); i++)
    {
        s.insert(nums[i]);
    }
    for(int i=0; i<nums.size(); i++)
    {
        if(s.count(nums[i]-1))
        {
            continue;
        }
        else
        {
            int count=0;
            int j=nums[i];
            while(s.count(j))
            {
                count++;
                j++;
            }
            maxlen=max(count, maxlen);
        }
    }
    return maxlen;
}

int main()
{
    vector<int> nums={100, 4, 200, 1, 3, 2};
    cout<<longestConsecutive(nums);
}