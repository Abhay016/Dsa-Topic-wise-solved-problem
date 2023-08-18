
/*   Given a number n. The task is to find the smallest number whose factorial contains at least n trailing zeroes.   */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int findNum(int n)
{
    int s = 0;
    int e = 5 * n;
    int ans = INT_MAX;
    while (s <= e)
    {
        int mid = (s + (e - s) / 2);
        int count = 0, i = 1;
        while (mid / (pow(5, i)))
        {
            count += mid / pow(5, i);
            i++;
        }
        if (count >= n)
        {
            ans = min(mid, ans);
            e = mid - 1;
        }
        else if (count < n)
        {
            s = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int n=6;
    cout<<findNum(6);
}