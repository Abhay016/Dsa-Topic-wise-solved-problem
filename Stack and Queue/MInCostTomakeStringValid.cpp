#include <bits/stdc++.h>
using namespace std;

int findMinimumCost(string str)
{
    int n = str.length();
    if (n % 2 != 0)
    {
        return -1;
    }
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        if (s.empty() || str[i]=='{')
        {
            s.push(str[i]);
        }
        else
        {
            if (s.top() == '{')
            {
                s.pop();
            }
            else
            {
                s.push(str[i]);
            }
        }
    }
    int open = 0, close = 0;
    while (!s.empty())
    {
        if (s.top() == '{')
        open++;
        else
        close++;
        s.pop();
    }
    int ans = (open + 1) / 2 + (close + 1) / 2;
    return ans;
}

int main()
{
    cout<<findMinimumCost("}}}}}{");
}