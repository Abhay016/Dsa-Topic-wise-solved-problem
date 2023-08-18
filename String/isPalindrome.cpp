
/*   Given a string S, check if it is palindrome or not.   */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int isPalindrome(string S)
{
    int i = 0, j = S.size() - 1;
    while (i < j)
    {
        if (S[i] != S[j])
        {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

int main()
{
    cout<<isPalindrome("abcd");
}