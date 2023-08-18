
/*   Count and Say   */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

string countAndSay(int n)
{
    if (n == 1)
        return "1";
    string str = countAndSay(n - 1);
    string ans = "";
    int i = 0, count = 0;
    while (i < str.length())
    {
        count++;
        if (i == str.length() - 1 || str[i] != str[i + 1])
        {
            string cnt = to_string(count);
            cnt += str[i];
            ans.append(cnt);
            count = 0;
        }
        i++;
    }
    return ans;
}

int main()
{
    cout<<countAndSay(4);
}