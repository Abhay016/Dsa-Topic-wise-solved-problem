
#include <bits/stdc++.h>
using namespace std;

void subsetSum(vector<int> arr, int i, int sum, vector<int> &res)
{
    if (i == arr.size())
    {
        res.push_back(sum);
        return;
    }
    subsetSum(arr, i + 1, sum, res);
    subsetSum(arr, i + 1, sum + arr[i], res);
}
vector<int> subsetSums(vector<int> arr, int N)
{
    vector<int> res;
    subsetSum(arr, 0, 0, res);
    sort(res.begin(), res.end());
    return res;
}

int main()
{
    vector<int> nums={5,2,1};
    int target=8;
    vector<int> res=subsetSums(nums, nums.size());
    for(int i=0; i<res.size(); i++)
    {
        cout<<res[i]<<" ";
    }
}