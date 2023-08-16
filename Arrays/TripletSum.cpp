
/* Triplet Sum in Array   */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

bool find3Numbers(int A[], int n, int X)
{
    sort(A, A + n);
    int j, k;
    for (int i = 0; i < n - 2; i++)
    {
        j = i + 1;
        k = n - 1;
        while (j < k)
        {
            if ((A[j] + A[k] + A[i]) == X)
            {
                return true;
            }
            else if ((A[j] + A[k] + A[i]) > X)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }
    return false;
}

int main()
{
    int arr[] = {1, 4, 45, 6, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int X = 13;
    cout << find3Numbers(arr, n, X);
}