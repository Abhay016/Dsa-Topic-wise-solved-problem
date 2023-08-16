
/*   Find Pair Given Difference   */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

bool findPair(int arr[], int size, int n)
{
    sort(arr, arr + size);
    for (int i = 0; i < size; i++)
    {
        int j = i + 1, k = size - 1;
        int temp = arr[i] + n;
        while (j <= k)
        {
            int mid = (j + (k - j) / 2);
            if (arr[mid] == temp)
            {
                return true;
            }
            else if (arr[mid] < temp)
            {
                j = mid + 1;
            }
            else
            {
                k = mid - 1;
            }
        }
    }
    return false;
}

int main()
{
    int size = 6, n = 78;
    int arr[] = {5, 20, 3, 2, 5, 80};
    cout << findPair(arr, size, n);
}