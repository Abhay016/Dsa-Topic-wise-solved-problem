
/*   Given Array of size n and a number k, find all elements that appear more than n/k times   */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

void morethanNbyK(int arr[], int n, int k)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for (auto itr = mp.begin(); itr != mp.end(); itr++)
    {
        if ((itr->second) > (n / k))
        {
            cout << (itr->first) << " ";
        }
    }
}

int main()
{
    int arr[] = {9, 8, 7, 9, 2, 9, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    morethanNbyK(arr, n, k);
    return 0;
}