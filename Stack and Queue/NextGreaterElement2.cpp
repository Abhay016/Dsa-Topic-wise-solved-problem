
/*
           Given a circular integer array nums
(i.e., the next element of nums[nums.length - 1] is nums[0]),
  return the next greater number for every element in nums.
*/

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

vector<int> nextGreaterElements(vector<int> &arr)
{
    stack<int> s;
    vector<int> ans;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        if (s.empty())
        {
            ans.push_back(-1);
            s.push(arr[i]);
        }
        else if (arr[i] < s.top())
        {
            ans.push_back(s.top());
            s.push(arr[i]);
        }
        else if (arr[i] >= s.top())
        {
            while (!s.empty() && arr[i] >= s.top())
            {
                s.pop();
            }
            if (s.empty())
                ans.push_back(-1);
            else
                ans.push_back(s.top());
            s.push(arr[i]);
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        if (ans[i] == -1)
        {
            if (s.empty())
            {
                ans[i] = -1;
            }
            else if (arr[i] < s.top())
            {
                ans[i] = s.top();
            }
            else if (arr[i] >= s.top())
            {
                while (!s.empty() && arr[i] >= s.top())
                {
                    s.pop();
                }
                if (s.empty())
                    ans[i] = -1;
                else
                    ans[i] = s.top();
            }
        }
        s.push(arr[i]);
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 8, -1, -100, -1, 222, 1111111, -111111};
    vector<int> ans = nextGreaterElements(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
