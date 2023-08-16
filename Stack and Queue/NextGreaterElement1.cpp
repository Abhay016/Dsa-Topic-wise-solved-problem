
/*   Next Greater Element   */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans;
    unordered_map<int, int> mp;
    for (int i = nums2.size() - 1; i >= 0; i--)
    {
        if (s.top() == -1 || nums2[i] < s.top())
        {
            mp[nums2[i]] = s.top();
            s.push(nums2[i]);
        }
        else if (nums2[i] >= s.top())
        {
            while (s.top() != -1 && nums2[i] >= s.top())
            {
                s.pop();
            }
            mp[nums2[i]] = s.top();
            s.push(nums2[i]);
        }
    }
    for (int i = 0; i < nums1.size(); i++)
    {
        auto itr = mp.find(nums1[i]);
        ans.push_back(itr->second);
    }
    return ans;
}

int main()
{
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> ans = nextGreaterElement(nums1, nums2);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}