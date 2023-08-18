
/*   Reverse a string    */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

void reverseString(vector<char> &s)
{
    int i = 0;
    int j = s.size() - 1;
    while (i < j)
    {
        swap(s[i], s[j]);
        i++;
        j--;
    }
}

int main()
{
    vector<char> str = {'h', 'e', 'l', 'l', 'o'};
    reverseString(str);
    for(int i=0; i<str.size(); i++)
    {
        cout<<str[i];
    }
}