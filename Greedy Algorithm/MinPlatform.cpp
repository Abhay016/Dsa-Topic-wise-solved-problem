
#include <bits/stdc++.h>
using namespace std;

int findPlatform(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);
    int res = 1;
    for (int i = 1; i < n; i++)
    {
        int count = 1;
        int j = i;
        int maxVal = dep[i - 1];
        while (j < n && maxVal >= arr[j])
        {
            count++;
            j++;
        }
        res = max(res, count);
    }
    return res;
}