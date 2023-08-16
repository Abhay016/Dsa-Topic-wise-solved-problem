
/*   Majority Elements   */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int majorityElement(int a[], int size)
{

    // your code here
    int count = 1;
    int ans = a[0];
    for (int i = 1; i < size; i++)
    {
        if (count == 0)
        {
            ans = a[i];
            count = 1;
        }
        else if (ans == a[i])
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    count = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] == ans)
        {
            count++;
        }
    }
    if (count > (size / 2))
        return ans;
    else
        return -1;
}

int main()
{
    int n = 3;
    int arr[] = {3, 1, 3, 3, 2};
    cout << majorityElement(arr, n);
}