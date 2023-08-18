
/*   Longest Palindrome in a String   */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

string longestPalin(string S)
{
    // code here
    int n = S.size();
    int low, high;
    int size = 1;
    for (int i = 1; i < n; i++)
    {
        int j = i - 1, k = i + 1;
        while (j >= 0 && k < n && S[j] == S[k])
        {

            if (k - j + 1 > size)
            {
                low = j;
                high = k;
                size = k - j + 1;
            }
            j--;
            k++;
        }
        j = i - 1, k = i;
        while (j >= 0 && k < n && S[j] == S[k])
        {
            if (k - j + 1 > size)
            {
                low = j;
                high = k;
                size = k - j + 1;
            }
            j--;
            k++;
        }
    }
    if (size == 1)
    {
        return S.substr(0, 1);
    }
    return S.substr(low, high - low + 1);
}

int main()
{
    cout<<longestPalin("aaaabbaa");
}