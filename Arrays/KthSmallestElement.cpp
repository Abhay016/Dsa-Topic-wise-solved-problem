
/*   Kth Smallest Element*/

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int kthSmallestElement(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq(arr, arr + n);
    while (k != 1)
    {
        pq.pop();
        k--;
    }
    return pq.top();
}

int main()
{
    int arr[] = {7, 10, 4, 20, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    cout << kthSmallestElement(arr, size, k);
}