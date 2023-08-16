
/*   Chocolate Distribution Problem    */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int findMinDiff(int n, int m, vector<int> arr)
{
    if (n == 0 || m == 0)
        return 0;
    if (n < m)
        return -1;
    sort(arr.begin(), arr.end());
    int minDiff = INT_MAX;
    int i = 0, j = i + m - 1;
    while (j < n)
    {
        minDiff = min(minDiff, arr[j] - arr[i]);
        i++;
        j++;
    }
    return minDiff;
}

int main()
{
    vector<int> chocolates={3, 4, 1, 9, 56, 7, 9, 12};
    int m=5;
    int ans=findMinDiff(chocolates.size(), m, chocolates);
    cout<<ans;
}