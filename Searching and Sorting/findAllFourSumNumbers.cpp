
/*   Find All four sum numbers    */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

vector<vector<int>> fourSum(vector<int> &arr, int k)
{
    // Your code goes here
    int n = arr.size();
    vector<vector<int>> ans;
    if (n < 4)
    {
        return ans;
    }
    set<vector<int>> st;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 3; i++)
    {
        int temp = arr[i];
        for (int j = i + 1; j < n - 2; j++)
        {
            temp += arr[j];
            int s = j + 1, e = n - 1;
            int sum = k - temp;
            while (s < e)
            {
                if (arr[s] + arr[e] == sum)
                {
                    st.insert({arr[i], arr[j], arr[s], arr[e]});
                    s++;
                    e--;
                }
                else if (arr[s] + arr[e] > sum)
                {
                    e--;
                }
                else
                {
                    s++;
                }
            }
            temp = arr[i];
        }
    }
    vector<int> temp;
    for (auto it = st.begin(); it != st.end(); it++)
    {
        temp = (*it);
        ans.push_back(temp);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<int> arr = {10, 2, 3, 4, 5, 7, 8};
    int k = 23;
    vector<vector<int>> ans = fourSum(arr, k);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j]<<" ";
        }
        cout << endl;
    }
}