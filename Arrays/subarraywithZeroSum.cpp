
/*   Subarray with 0 sum   */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

bool subArrayExists(int arr[], int n)
{
    // Your code here
    unordered_set<int> s;
    int sum = 0;
    s.insert(0);
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (s.count(sum))
        {
            return true;
        }
        s.insert(sum);
    }
    return false;
}

int main()
{
    int arr[] = {4, 2, -3, -1, 0, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << subArrayExists(arr, n);
}