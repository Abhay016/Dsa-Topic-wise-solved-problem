
/*   Subarray Sum equals K   */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int subarraySum(vector<int> &arr, int k)
{
    int count = 0;
    unordered_map<int, int> mp;
    int sum = arr[0];
    mp[0]++;
    mp[arr[0]]++;
    if (arr[0] == k)
    {
        count++;
    }
    for (int i = 1; i < arr.size(); i++)
    {
        sum += arr[i];
        if (mp.count(sum - k))
        {
            count += mp[sum - k];
        }
        mp[sum]++;
    }
    return count;
}

int main()
{
    vector<int> arr={1,1,1};
    int k=2;
    cout<<subarraySum(arr, k);
}