
/*   Smallest subarray with sum greater than x   */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int smallestSubWithSum(int arr[], int n, int x)
{
    // Your code goes here
    int i = 0, j = 0;
    int sum = 0;
    int ans = n + 1;
    while (j < n)
    {
        sum += arr[j++];
        if (sum > x)
        {
            while (i < j && sum > x)
            {
                ans = min(ans, j - i);
                sum -= arr[i++];
            }
        }
    }
    if (ans == n + 1)
        return 0;
    else
        return ans;
}

int main()
{
    int arr[] = {1, 4, 45, 6, 0, 19};
    cout << smallestSubWithSum(arr, 6, 51);
}