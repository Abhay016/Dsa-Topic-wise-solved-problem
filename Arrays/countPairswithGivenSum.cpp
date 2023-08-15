
/*   Count pairs with given sum   */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int getPairsCount(int arr[], int n, int k)
{
    // code here
    int ans = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        if (mp[k - arr[i]])
        {
            ans = ans + mp[k - arr[i]];
        }
        mp[arr[i]]++;
    }
    return ans;
}

int main()
{
    int arr[]={1,5,7,1};
    int k=6, n=4;
    cout<<getPairsCount(arr, n, k);
}