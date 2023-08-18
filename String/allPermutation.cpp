
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int factorial(int num)
{
    for (int i = num - 1; i >= 2; i--)
    {
        num = num * i;
    }
    return num;
}
vector<int> nextPermutation(vector<int> arr)
{
    int N = arr.size();
    int i = N - 1;
    int count = 0;
    while (i > 0)
    {
        if (arr[i - 1] >= arr[i])
        {
            count++;
            i--;
        }
        else
        {
            break;
        }
    }
    if (i == 0)
    {
        reverse(arr.begin(), arr.end());
        return arr;
    }
    int temp = i - 1;
    reverse(arr.begin() + i, arr.end());
    for (int j = i; j < N; j++)
    {
        if (arr[j] > arr[temp])
        {
            swap(arr[temp], arr[j]);
            break;
        }
    }
    return arr;
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    ans.push_back(nums);
    int i = factorial(nums.size()) - 1;
    int j = 0;
    while (i--)
    {
        ans.push_back(nextPermutation(ans[j]));
        j++;
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    vector<vector<int>> ans = permute(nums);
    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}